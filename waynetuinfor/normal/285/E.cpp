#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, mod = 1e9 + 7;
long long dp[8][maxn][maxn], c[maxn][maxn];
long long tdp[maxn], f[maxn], fdp[maxn];
int n, k;

void init() {
    c[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            c[i][j] = c[i - 1][j];
            if (j) (c[i][j] += c[i - 1][j - 1]) %= mod;
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[3][i][0] = (dp[1][i - 1][0] + dp[3][i - 1][0]) % mod;
        dp[1][i][0] = (dp[0][i - 1][0] + dp[2][i - 1][0]) % mod;
        if (i + 1 > n) dp[2][i][0] = (dp[1][i - 1][0] + dp[3][i - 1][0]) % mod;
        for (int j = 1; j <= n; ++j) {
            if (i + 1 <= n) dp[0][i][j] = (dp[0][i - 1][j - 1] + dp[2][i - 1][j - 1]) % mod;
            else dp[0][i][j] = (dp[2][i - 1][j] + dp[0][i - 1][j] + dp[2][i - 1][j - 1]) % mod;
            dp[3][i][j] = (dp[1][i - 1][j] + dp[3][i - 1][j] + dp[3][i - 1][j - 1]) % mod;
            if (i + 1 <= n) dp[2][i][j] = (dp[1][i - 1][j - 1] + dp[3][i - 1][j - 1]) % mod;
            else dp[2][i][j] = (dp[1][i - 1][j] + dp[3][i - 1][j] + dp[3][i - 1][j - 1]);
            dp[1][i][j] = (dp[0][i - 1][j] + dp[2][i - 1][j] + dp[2][i - 1][j - 1]) % mod;
        }
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * i % mod;
    for (int i = 0; i <= n; ++i) tdp[i] = (dp[0][n][i] + dp[2][n][i]) * f[n - i] % mod;
}

int main() {
    scanf("%d %d", &n, &k);
    init();
    fdp[n] = tdp[n];
    for (int i = n - 1; i >= 0; --i) {
        fdp[i] = tdp[i];
        for (int j = i + 1; j <= n; ++j) {
            fdp[i] -= fdp[j] * c[j][i] % mod;
            fdp[i] %= mod;
            fdp[i] += mod;
            fdp[i] %= mod;
        }
    }
    printf("%" PRId64 "\n", fdp[k]);
    return 0;
}