#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9;
int a[maxn], dp[2][2][maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) {
        dp[0][0][i] = dp[0][0][i - 1] - a[i];
        dp[0][1][i] = max(dp[0][1][i - 1], dp[0][0][i - 1]) + a[i];
    }
    for (int i = n; i > 0; --i) {
        dp[1][0][i] = dp[1][0][i + 1] - a[i];
        dp[1][1][i] = max(dp[1][1][i + 1], dp[1][0][i + 1]) + a[i];
    }
    int ans = -inf;
    for (int i = 1; i <= n; ++i) ans = max(ans, max(dp[0][0][i], dp[0][1][i]) + max(dp[1][0][i + 1], dp[1][1][i + 1]));
    printf("%d\n", ans);
    return 0;
}