#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxk = 100 + 5;
const int mod = 998244353;
int a[maxn], to[maxk][maxn];
int dp[maxk][maxn], s[maxk][maxn], offset[maxk];

int main() {
    int n, k, l; scanf("%d%d%d", &n, &k, &l);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    if (l == 1) {
        puts("0");
        return 0;
    }
    --l;
    for (int i = 1; i <= k; ++i) {
        int last = n;
        for (int j = n; j >= 1; --j) {
            to[i][j] = last;
            if (a[j] != -1 && a[j] != i) last = j - 1;
        } 
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        // for (int j = 0; j <= k; ++j) printf("s[%d][%d] = %d\n", j, i, s[j][i]);
        for (int j = 0; j <= k; ++j) (offset[j] += s[j][i]) %= mod;
        // for (int j = 0; j <= k; ++j) printf("offset[%d] = %d\n", j, offset[j]);
        for (int j = 0; j <= k; ++j) (dp[j][i] += offset[j]) %= mod;
        if (i == n) break;
        int sum = 0;
        for (int j = 0; j <= k; ++j) (sum += dp[j][i]) %= mod;
        for (int j = 1; j <= k; ++j) {
            // printf("dp[%d][%d] = %d\n", j, i, dp[j][i]);
            int way = (sum + mod - dp[j][i]) % mod;
            if (a[i + 1] != -1 && a[i + 1] != j) continue;
            int g = min(to[j][i + 1], i + 1 + l - 1);
            // printf("i = %d j = %d way = %d to = %d\n", i, j, way, g);
            (s[j][i + 1] += way) %= mod;
            (s[j][g + 1] += mod - way) %= mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) (ans += dp[i][n]) %= mod;
    printf("%d\n", ans);
    return 0;
}