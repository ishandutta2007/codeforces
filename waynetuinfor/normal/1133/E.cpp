#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int a[maxn], prv[maxn], dp[maxn][maxn];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (a[i] - a[j] <= 5) {
                prv[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j)
                dp[i][j] = max(dp[i][j], dp[prv[i] - 1][j - 1] + i - prv[i] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
}