#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Vemaybay {
public:
    string tenchuyen;
    string ngaybay;
    double giave;

    // Hàm tạo
    Vemaybay() {
        tenchuyen = "";
        ngaybay = "";
        giave = 0.0;
    }

    // Hàm hủy
    ~Vemaybay() {
    }

    // Nhập thông tin vé máy bay
    void Nhap() {
        cout << "Nhap ten chuyen bay: ";
        cin >> tenchuyen;
        cout << "Nhap ngay bay: ";
        cin >> ngaybay;
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    // Xuất thông tin vé máy bay
    void Xuat() {
        cout << "Ten chuyen bay: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    // Hàm trả về giá vé
    double getgiave() {
        return giave;
    }
};

class Nguoi {
public:
    string hoten;
    string gioitinh;
    int tuoi;

    // Hàm tạo
    Nguoi() {
        hoten = "";
        gioitinh = "";
        tuoi = 0;
    }

    // Hàm hủy
    ~Nguoi() {
    }

    // Nhập thông tin người
    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        cin >> gioitinh;
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    // Xuất thông tin người
    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class hanhkhach : public Nguoi {
public:
    Vemaybay* ve;
    int soluong;

    // Hàm tạo
    hanhkhach() {
        ve = nullptr;
        soluong = 0;
    }

    // Hàm hủy
    ~hanhkhach() {
        delete[] ve;
    }

    // Nhập thông tin hành khách
    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++) {
            cout << "Nhap thong tin ve thu " << i + 1 << ":" << endl;
            ve[i].Nhap();
        }
    }

    // Xuất thông tin hành khách
    void Xuat() {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;
        cout << "Thong tin ve may bay da mua:" << endl;
        for (int i = 0; i < soluong; i++) {
            ve[i].Xuat();
        }
    }

    // Hàm tính tổng tiền phải trả
    double tongtien() const {
    double total = 0.0;
    for (int i = 0; i < soluong; i++) {
        total += ve[i].getgiave();
    }
    return total;
}
};

// Hàm tính tổng ước của một số nguyên dương n
long long sumDivisors(int n) {
    long long sum = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                sum += i;
            else
                sum += i + n / i;
        }
    }
    return sum;
}

// Hàm mã hóa chuỗi s thành chuỗi mã hóa
string encodeString(const string& s) {
    string encoded = "";
    stack<pair<char, int>> st;

    for (char ch : s) {
        if (st.empty() || st.top().first != ch) {
            if (!st.empty()) {
                encoded += st.top().first + to_string(st.top().second);
            }
            st.push({ch, 1});
        } else {
            st.top().second++;
        }
    }

    if (!st.empty()) {
        encoded += st.top().first + to_string(st.top().second);
    }

    return encoded;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm tìm các số siêu nguyên tố nhỏ hơn hoặc bằng n
vector<int> superPrimeNumber(int n) {
    vector<int> result;
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current <= n) {
            if (isPrime(current)) {
                result.push_back(current);
                for (int i = 1; i <= 9; i += 2) {
                    int next = current * 10 + i;
                    if (next <= n) {
                        q.push(next);
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    int choice;
    while (true) {
        cout << "Chon bai tap (1-4) hoac nhap 0 de thoat:" << endl;
        cout << "1. Tinh tong uoc cua 1 so nguyen duong n" << endl;
        cout << "2. Quan ly ve may bay (Vemaybay)" << endl;
        cout << "3. Ma hoa chuoi" << endl;
        cout << "4. So sieu nguyen to" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;
        }

        switch (choice) {
            case 1: {
                int T, n;
                cout << "Nhap so luong test case: ";
                cin >> T;
                for (int i = 0; i < T; i++) {
                    cout << "Nhap so nguyen duong n: ";
                    cin >> n;
                    cout << "Ket qua: " << sumDivisors(n) << endl;
                }
                break;
            }
            case 2: {
                int n;
                cout << "Nhap so luong hanh khach: ";
                cin >> n;
                vector<hanhkhach> danhSachHanhKhach(n);
                for (int i = 0; i < n; i++) {
                    cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << endl;
                    danhSachHanhKhach[i].Nhap();
                }

                // Sắp xếp danh sách hành khách theo tổng tiền giảm dần
                sort(danhSachHanhKhach.begin(), danhSachHanhKhach.end(),
                     [](const hanhkhach& a, const hanhkhach& b) {
                         return a.tongtien() < b.tongtien();
                     });

                // In danh sách hành khách và số tiền phải trả
                cout << "Danh sach hanh khach va so tien phai tra:" << endl;
                for (int i = 0; i < n; i++) {
                    cout << "Hanh khach thu " << i + 1 << ":" << endl;
                    danhSachHanhKhach[i].Xuat();
                    cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
                    cout << "===============================" << endl;
                }
                break;
            }
            case 3: {
                string s;
                cin.ignore();
                cout << "Nhap chuoi can ma hoa: ";
                getline(cin, s);
                cout << "Chuoi da ma hoa: " << encodeString(s) << endl;
                break;
            }
            case 4: {
                int n;
                cout << "Nhap so nguyen n: ";
                cin >> n;
                vector<int> superPrimes = superPrimeNumber(n);
                cout << "Cac so sieu nguyen to nho hon hoac bang " << n << ": ";
                for (int prime : superPrimes) {
                    cout << prime << " ";
                }
                cout << endl;
                break;
            }
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
    }

    return 0;
}
