#include <bits/stdc++.h>
using namespace std;

const int maxn = 1048576, mod = 1e9 + 7;
int dp[maxn][21], tpow[maxn], tdp[maxn];

int main() {
    tpow[0] = 1;
    for (int i = 1; i < maxn; ++i) tpow[i] = tpow[i - 1] * 2ll % mod;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        ++dp[a][20];
    }
    for (int i = maxn - 1; i >= 0; --i) {
        for (int j = 19; j >= 0; --j) {
            if (i >> j & 1) dp[i][j] = dp[i][j + 1];
            else dp[i][j] = (dp[i][j + 1] + dp[i ^ (1 << j)][j + 1]) % mod;
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    for (int i = 0; i < maxn; ++i) tdp[i] = (tpow[dp[i][0]] - 1 + mod) % mod; 
    // for (int i = 0; i < 8; ++i) printf("%d ", tdp[i]); puts("");
    int ans = tdp[0];
    for (int i = 1; i < maxn; ++i) {
        int c = __builtin_popcount(i) & 1 ? -1 : 1;
        ans = (ans + (c * tdp[i] + mod) % mod) % mod;
    }
    printf("%d\n", ans);
    return 0;
}