#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
const int mod = 1e9 + 7;
const int inv = 500000004;
int n, k, pw[maxn], dp[maxn][maxn];

int fpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * 1ll * x % mod;
        x = x * 1ll * x % mod;
        n >>= 1;
    }
    return res;
}

int dfs(int d, int p) {
    if (dp[d][p] >= 0) return dp[d][p];
    if (d == 0) return pw[p];
    dp[d][p] = 0;
    if (p > 0) {
        dp[d][p] += dfs(d - 1, p) * 1ll * p % mod;
        if (dp[d][p] >= mod)
            dp[d][p] -= mod;
    }
    if (n - p > 0) {
        dp[d][p] += dfs(d - 1, p + 1) * 1ll * (n - p) % mod;
        if (dp[d][p] >= mod)
            dp[d][p] -= mod;
    }
    return dp[d][p];
}

int main() {
    scanf("%d%d", &n, &k);
    pw[0] = fpow(2, n);
    for (int i = 1; i < maxn; ++i) 
        pw[i] = pw[i - 1] * 1ll * inv % mod;
    memset(dp, -1, sizeof(dp));
    printf("%d\n", dfs(k, 0));
    return 0;
}