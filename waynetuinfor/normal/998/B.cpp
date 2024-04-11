#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn], dp[maxn][maxn], s[maxn];

int main() {
    int n, b; scanf("%d %d", &n, &b);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + (a[i] % 2 ? 1 : -1);
    a[0] = a[1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k < i; ++k) if (s[i] - s[k] == 0) {
                int bit = abs(a[k + 1] - a[k]);
                if (j >= bit) dp[i][j] = max(dp[i][j], dp[k][j - bit] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; ++i) ans = max(ans, dp[n][i] - 1);
    printf("%d\n", ans);
}