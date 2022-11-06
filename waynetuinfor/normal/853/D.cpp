#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5, maxt = 300 + 5;
const long long inf = 1e15;
long long dp[2][maxt];
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    fill(dp[0], dp[0] + maxt, inf);
    dp[0][0] = 0;
    int z = 1;
    for (int i = 0; i < n; ++i) {
        fill(dp[z], dp[z] + maxt, inf);
        for (int j = 0; j < maxt; ++j) if (dp[z ^ 1][j] != inf) {
            dp[z][min(300, j + a[i] / 1000)] = min(dp[z][min(300, j + a[i] / 1000)], dp[z ^ 1][j] + a[i] / 100);
            int cost = min(j, a[i] / 100);
            if (cost == 0) continue;
            dp[z][j - cost] = min(dp[z][j - cost], dp[z ^ 1][j] + a[i] / 100 - cost);
        }
        z ^= 1;
    }
    z ^= 1;
    long long ans = inf;
    for (int i = 0; i < maxt; ++i) ans = min(ans, dp[z][i]);
    printf("%lld\n", ans * 100);
    return 0;
}