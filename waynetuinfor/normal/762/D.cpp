#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1e15;
long long a[3][maxn];
long long dp[3][maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < 3; ++i) for (int j = 1; j <= n; ++j) scanf("%lld", &a[i][j]);
    for (int i = 0; i < 3; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = -inf;
    dp[0][0] = 0;
    dp[0][1] = a[0][1], dp[1][1] = a[0][1] + a[1][1], dp[2][1] = a[0][1] + a[1][1] + a[2][1];
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = max(dp[0][i], dp[0][i - 1] + a[0][i]);
        dp[0][i] = max(dp[0][i], dp[1][i - 1] + a[1][i] + a[0][i]);
        dp[0][i] = max(dp[0][i], dp[2][i - 1] + a[2][i] + a[1][i] + a[0][i]);
        dp[0][i] = max(dp[0][i], dp[2][i - 2] + a[0][i] + a[0][i - 1] + a[1][i] + a[1][i - 1] + a[2][i] + a[2][i - 1]);
        dp[1][i] = max(dp[1][i], dp[0][i - 1] + a[0][i] + a[1][i]);
        dp[1][i] = max(dp[1][i], dp[1][i - 1] + a[1][i]);
        dp[1][i] = max(dp[1][i], dp[2][i - 1] + a[2][i] + a[1][i]);
        dp[2][i] = max(dp[2][i], dp[0][i - 1] + a[0][i] + a[1][i] + a[2][i]);
        dp[2][i] = max(dp[2][i], dp[1][i - 1] + a[1][i] + a[2][i]);
        dp[2][i] = max(dp[2][i], dp[2][i - 1] + a[2][i]);
        dp[2][i] = max(dp[2][i], dp[0][i - 2] + a[0][i] + a[0][i - 1] + a[1][i] + a[1][i - 1] + a[2][i] + a[2][i - 1]);
    }
    printf("%lld\n", dp[2][n]);
}