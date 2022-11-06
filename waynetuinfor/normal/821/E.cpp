#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, mod = 1e9 + 7, maxc = 16;
using matrix = vector<vector<int>>;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

matrix matmul(const matrix& a, const matrix& b) {
    matrix ret = matrix(maxc, vector<int>(maxc));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < b.size(); ++k) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
        }
    }
    return ret;
}

matrix fpow(matrix a, long long n) {
    matrix ret = matrix(maxc, vector<int>(maxc));
    for (int i = 0; i < maxc; ++i) ret[i][i] = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = matmul(ret, a);
        a = matmul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; long long k; cin >> n >> k;
    matrix now = matrix(maxc, vector<int>(1));
    now[0][0] = 1;
    long long pv = 0;
    while (n--) {
        long long a, b; int c; cin >> a >> b >> c;
        matrix t = matrix(maxc, vector<int>(maxc));
        for (int i = 0; i <= c; ++i) {
            t[i][i] = 1;
            if (i - 1 >= 0) t[i][i - 1] = 1;
            if (i + 1 <= c) t[i][i + 1] = 1;
        }
        // for (int i = 0; i <= c; ++i) {
            // for (int j = 0; j <= c; ++j) cout << t[i][j] << ' ';
            // cout  << endl;
        // }
        t = fpow(t, min(k, b) - pv);
        now = matmul(t, now);
        pv = min(k, b);
        if (pv == k) break;
    }
    if (pv < k) return cout << "0" << endl, 0;
    cout << now[0][0] << endl;
    return 0;
}