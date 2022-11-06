#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;

template <typename T> class Matrix {
    private:
        int n, mod;
    public:
        vector<vector<T>> mat;
        Matrix(int n, int mod=0, bool I=false): n(n), mod(mod) {
            mat.resize(n);
            for (int i = 0; i < n; ++i) mat[i].resize(n);
            if (!I) return;
            for (int i = 0; i < n; ++i) mat[i][i] = 1;
        }
        Matrix operator+(const Matrix& rhs) const {
            Matrix ret(n, mod);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ret.mat[i][j] = mat[i][j] + rhs.mat[i][j];
                    if (mod) ret.mat[i][j] %= mod;
                }
            }
            return ret;
        }
        Matrix operator-(const Matrix& rhs) const {
            Matrix ret(n, mod);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ret.mat[i][j] = mat[i][j] - rhs.mat[i][j];
                    if (mod) {
                        ret.mat[i][j] %= mod;
                        ret.mat[i][j] += mod;
                        ret.mat[i][j] %= mod;
                    }
                }
            }
            return ret;
        }
        Matrix operator*(const Matrix& rhs) const {
            Matrix ret(n, mod);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        if (mod) ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % mod) % mod;
                        else ret.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                        assert(ret.mat[i][j] < mod);
                    }
                }
            }
            return ret;
        }
};

int a[maxn], cnt[10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, b, k, x; cin >> n >> b >> k >> x;
    Matrix<long long> m(x + 1, mod);
    for (int i = 0; i < n; ++i) cin >> a[i], cnt[a[i]]++;
    for (int i = 0; i < x; ++i) {
        for (int j = 1; j <= 9; ++j) {
            m.mat[i][(i * 10 + j) % x] += cnt[j];
        }
    }
    Matrix<long long> ans(x + 1, mod, true);
    for (; b; b >>= 1) {
        if (b & 1) {
            ans = ans * m;
        }
        m = m * m;
    }
    cout << ans.mat[0][k % x] << endl;
    return 0;
}