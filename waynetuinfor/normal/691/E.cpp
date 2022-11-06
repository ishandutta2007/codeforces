#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, mod = 1e9 + 7;
long long a[maxn];

using matrix = vector<vector<int>>;
using row = vector<int>;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

matrix matmul(const matrix &a, const matrix &b) {
    matrix ret(a.size(), row(b[0].size()));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < b.size(); ++k) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
        }
    }
    return ret;
}

matrix fpow(matrix &a, long long n) {
    matrix ret(a.size(), row(a.size()));
    for (int i = 0; i < a.size(); ++i) ret[i][i] = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = matmul(ret, a);
        a = matmul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; long long k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (k == 1) return cout << n << endl, 0;
    matrix mat(n, row(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) mat[i][j] = 1;
        }
    }
    mat = fpow(mat, k - 2);
    matrix ori(n, row(1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) ++ori[i][0];
        }
    }
    ori = matmul(mat, ori);
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = add(ans, ori[i][0]);
    cout << ans << endl;
    return 0;
}