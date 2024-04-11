#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
const int mod = 998244353;
int cnt[maxn], dp[maxn][maxn], sum[maxn][maxn], inv[maxn];

int fpow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * 1ll * x % mod;
        x = x * 1ll * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ++cnt[x];
    }

    for (int i = 1; i <= n; ++i) inv[i] = fpow(i, mod - 2);

    dp[0][0] = 1;
    sum[0][0] = 1;
    int ans = 0, pref = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 0) pref += 1;
        for (int j = 0; j <= n; ++j)
            sum[i][j] = sum[i - 1][j];

        for (int j = 1; j <= pref; ++j) {
            int p = cnt[i] * 1ll * inv[n - j + 1] % mod;
            dp[i][j] = sum[i - 1][j - 1] * 1ll * p % mod;
            (sum[i][j] += dp[i][j]) %= mod;

            if (cnt[i] > 1 && j < n) {
                ans += dp[i][j] * 1ll * (cnt[i] - 1) % mod * inv[n - j] % mod;
                ans %= mod;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}