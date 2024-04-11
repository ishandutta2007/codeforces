#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5, mod = 1e9 + 7;
const int inf = 1e9 + 1;
int h[maxn], dp[2][maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", h + i);
    h[0] = inf; h[n + 1] = inf;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] == h[i + 1]) {
            dp[1][i] = dp[1][i - 1] * 1ll * (min(h[i], h[i - 1]) - 1) % mod;
            dp[1][i] = (dp[1][i] + h[i] - 1) % mod;
        } 
        if (h[i] > h[i + 1]) {
            dp[1][i] = dp[1][i - 1] * 1ll * (min(h[i + 1], min(h[i - 1], h[i])) - 1) % mod;
            dp[1][i] = (dp[1][i] + h[i + 1] - 1) % mod;
            if (h[i - 1] > h[i + 1]) {
                dp[0][i] = dp[1][i - 1] * 1ll * (min(h[i], h[i - 1]) - h[i + 1]) % mod;
            }
            dp[0][i] = (dp[0][i] + h[i] - h[i + 1]) % mod;
        }
        if (h[i] < h[i + 1]) {
            dp[1][i] = dp[1][i - 1] * 1ll * (min(h[i - 1], h[i]) - 1) % mod;
            dp[1][i] = (dp[1][i] + h[i] - 1) % mod;
        }
        ans = (ans + (dp[0][i] + dp[1][i]) % mod) % mod;
    }
    printf("%d\n", ans);
    return 0;
}