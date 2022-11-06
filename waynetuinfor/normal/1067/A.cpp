#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 998244353;
int a[maxn], dp[201][2][2];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    if (~a[1]) dp[a[1]][1][0] = 1;
    else for (int i = 1; i <= 200; ++i) dp[i][1][0] = 1;
    for (int i = 1; i <= 200; ++i) {
        (dp[i][1][1] += dp[i - 1][1][1]) %= mod;
        (dp[i][1][0] += dp[i - 1][1][0]) %= mod;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 200; ++j) dp[j][i & 1][1] = dp[j][i & 1][0] = 0;
        if (~a[i]) {
            dp[a[i]][i & 1][1] = ((dp[a[i]][i & 1 ^ 1][0] + mod - dp[a[i] - 1][i & 1 ^ 1][0]) % mod + 
                                  (dp[a[i]][i & 1 ^ 1][1] + mod - dp[a[i] - 1][i & 1 ^ 1][1]) % mod) % mod;
            (dp[a[i]][i & 1][1] += (dp[200][i & 1 ^ 1][1] + mod - dp[a[i]][i & 1 ^ 1][1]) % mod) %= mod;
            (dp[a[i]][i & 1][0] += (dp[a[i] - 1][i & 1 ^ 1][1] + dp[a[i] - 1][i & 1 ^ 1][0]) % mod) %= mod;
        } else {
            for (int j = 1; j <= 200; ++j) {
                dp[j][i & 1][1] = ((dp[j][i & 1 ^ 1][0] + mod - dp[j - 1][i & 1 ^ 1][0]) % mod + 
                                   (dp[j][i & 1 ^ 1][1] + mod - dp[j - 1][i & 1 ^ 1][1]) % mod) % mod;
                (dp[j][i & 1][1] += (dp[200][i & 1 ^ 1][1] + mod - dp[j][i & 1 ^ 1][1]) % mod) %= mod;
                (dp[j][i & 1][0] += (dp[j - 1][i & 1 ^ 1][1] + dp[j - 1][i & 1 ^ 1][0]) % mod) %= mod;
            }
        }
        for (int j = 1; j <= 200; ++j) {
            (dp[j][i & 1][1] += dp[j - 1][i & 1][1]) %= mod;
            (dp[j][i & 1][0] += dp[j - 1][i & 1][0]) %= mod;
        }
    }
    printf("%d\n", dp[200][n & 1][1]);
    return 0;
}