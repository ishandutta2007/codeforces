#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, mod = 1e9 + 7;
int dp[maxn][maxn * maxn];
int c[maxn][maxn], g[maxn][maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

void init() {
    c[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            c[i][j] = c[i - 1][j];
            if (j > 0) c[i][j] = add(c[i][j], c[i - 1][j - 1]);
        }
    }
}

int fpow(int a, long long n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int main() {
    init();
    int n, k; long long m; cin >> n >> m >> k;
    for (int b = 0; b <= n; ++b) {
        for (int i = 0; i < n; ++i) g[b][i] = fpow(c[n][b], i < m % n ? m / n + 1 : m / n);
    }
    for (int j = 0; j <= min(n, k); ++j) {
        dp[0][j] = g[j][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int b = 0; b <= n; ++b) {
                if (j - b >= 0) dp[i][j] = add(dp[i][j], mul(dp[i - 1][j - b], g[b][i]));
            }
        }
    }
    cout << dp[n - 1][k] << endl;
    return 0;
}