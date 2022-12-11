#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int p = 998244353;

struct matrix{
    vector <vector <int>> m;
    matrix() {}
    matrix(int n) {
        m.resize(n);
        for (int i = 0; i < n; i++) m[i].assign(n, 0);
    }
    int size() {
        return (int) m.size();
    }
    matrix operator * (matrix a) {
        int n = size();
        matrix ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ans.m[i][j] = (ans.m[i][j] + m[i][k] * a.m[k][j]) % p;
                }
            }
        }
        return ans;
    }
    void print() {
        for (auto elem : m) {
            for (auto elem2 : elem) cout << elem2 << ' ';
            cout << endl;
        }
    }
};

matrix m_pow(matrix a, int n) {
    if (n == 1) return a;
    if (n % 2 == 0) {
        auto mem = m_pow(a, n / 2);
        return mem * mem;
    }
    return a * m_pow(a, n - 1);
}

int n_pow(int a, int n) {
    if (n == 1) return a % p;
    if (n % 2 == 0) {
        int mem = n_pow(a, n / 2);
        return (mem * mem) % p;
    }
    return (a * n_pow(a, n - 1)) % p;
}

signed main() {
    int n, m, l, r, s;
    cin >> n >> m >> l >> r;
    s = n * m;
    if (s % 2 == 1) {
        cout << n_pow(r - l + 1, s) << "\n";
        return 0;
    }
    int len = r - l + 1;
    int ch = len / 2, nech = len / 2;
    if (l % 2 == r % 2 && l % 2 == 1) nech++;
    if (l % 2 == r % 2 && l % 2 == 0) ch++;
    //cout << ch << ' ' << nech << endl;
    matrix a(2);
    a.m[0][0] = a.m[1][1] = ch % p;
    a.m[0][1] = a.m[1][0] = nech % p;
    a = m_pow(a, s);
    cout << a.m[0][0] << endl;
    return 0;
}