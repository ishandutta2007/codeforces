#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int mod = 998244353;
int dp[maxn][maxn], ans[maxn];
int pw[maxn], qw[maxn], scc[maxn];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    int a, b; scanf("%d%d", &a, &b);
    int p = a * 1ll * fpow(b, mod - 2) % mod;
    int q = mod + 1 - p;

    ans[1] = 0;
    dp[1][1] = 1;

    pw[0] = qw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * 1ll * p % mod;
        qw[i] = qw[i - 1] * 1ll * q % mod;
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] * 1ll * qw[j] % mod + dp[i - 1][j - 1] * 1ll * pw[i - j] % mod;
            dp[i][j] %= mod;

            assert((pw[j] + mod - qw[j]) % mod * 1ll * dp[i][j] % mod == (pw[i + 1 - j] + mod - qw[i + 1 - j]) % mod * 1ll * dp[i][j - 1] % mod);
        }

        for (int j = 1; j < i; ++j) {
            scc[i] += scc[j] * 1ll * dp[i][j] % mod;
            scc[i] %= mod;
        }
        scc[i] = (mod + 1 - scc[i]) % mod;
    }

    ans[1] = 0;
    for (int i = 2; i <= n; ++i) {
        ans[i] = dp[i][i] * 1ll * scc[i] % mod * (i * (i - 1) / 2) % mod;
        for (int j = 1; j < i; ++j) {
            int k = ((ans[j] + ans[i - j]) % mod + j * (j - 1) / 2 + j * (i - j)) % mod;
            ans[i] += dp[i][j] * 1ll * scc[j] % mod * k % mod;
            ans[i] %= mod;
        }

        ans[i] = ans[i] * 1ll * fpow(mod + 1 - scc[i] % mod, mod - 2) % mod;
    }

    printf("%d\n", ans[n]);
    return 0;
}