#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];
char s[maxn];
long long dp[5][maxn];
char hard[5] = "hard";


int main() {
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 4; ++j) dp[j][i] = 1e18;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i + 1] == hard[j]) {
                dp[j + 1][i + 1] = min(dp[j + 1][i + 1], dp[j][i]);
                dp[j][i + 1] = min(dp[j][i + 1], dp[j][i] + a[i + 1]);
            } else {
                dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);
            }
        }
    }
    long long ans = 1e18;
    for (int i = 0; i < 4; ++i) ans = min(ans, dp[i][n]);
    printf("%lld\n", ans);
    return 0;
}