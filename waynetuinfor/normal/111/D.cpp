#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, maxk = 1e6 + 5, mod = 1e9 + 7;
int dp[maxn][maxn], f[maxk], invf[maxk];

int fpow(int a, int n) {
    int r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return r;
}

int comb(int n, int k) {
    if (n < k) return 0;
    return f[n] * 1ll * invf[k] % mod * 1ll * invf[n - k] % mod;
}

int main() {
    int n, m, k; scanf("%d %d %d", &m, &n, &k);
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= min(m, k); ++j) dp[i][j] = (j * 1ll * dp[i - 1][j] % mod + dp[i - 1][j - 1]) % mod;
    }
    f[0] = 1, invf[0] = 1;
    for (int i = 1; i < maxk; ++i) f[i] = f[i - 1] * 1ll * i % mod, invf[i] = fpow(f[i], mod - 2);
    if (n == 1) {
        printf("%d\n", fpow(k, m));
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= min(m, k); ++i) {
        for (int j = 0; j <= i; ++j) {
            int way = comb(k, i) * 1ll * comb(i, j) % mod * 1ll * comb(k - i, i - j) % mod;
            way = way * 1ll * f[i] % mod * 1ll * f[i] % mod * 1ll * dp[m][i] % mod * 1ll * dp[m][i] % mod;
            way = way * 1ll * fpow(j, (n - 2) * m) % mod;
            ans = (ans + way) % mod;
        }
    }
    printf("%d\n", ans);
    return 0;
}