#include <bits/stdc++.h>
using namespace std;

const int maxn = 60, mod = 1e9 + 7;
long long n;
int m, k;
bool ban[maxn][maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

using matrix = vector<vector<int>>;

matrix matmul(const matrix &a, const matrix &b) {
    matrix ret = matrix(maxn, vector<int>(maxn));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < b.size(); ++k) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
        }
    }
    return ret;
}

matrix fpow(matrix a, long long n) {
    matrix ret = matrix(maxn, vector<int>(maxn));
    for (int i = 0; i < maxn; ++i) ret[i][i] = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = matmul(ret, a);
        a = matmul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        int a = (s[0] >= 'a' && s[0] <= 'z' ? s[0] - 'a' : s[0] - 'A' + 26);
        int b = (s[1] >= 'a' && s[1] <= 'z' ? s[1] - 'a' : s[1] - 'A' + 26);
        ban[a][b] = true;
    }
    matrix mat = matrix(maxn, vector<int>(1));
    for (int i = 0; i < m; ++i) mat[i][0] = 1;
    matrix matpow = matrix(maxn, vector<int>(maxn));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!ban[i][j]) matpow[i][j] = 1;
            else matpow[i][j] = 0;
        }
    }
    matpow = fpow(matpow, n - 1);
    int ans = 0;
    mat = matmul(matpow, mat);
    for (int i = 0; i < m; ++i) ans = add(ans, mat[i][0]);
    cout << ans << endl;
    return 0;
}