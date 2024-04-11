#include <bits/stdc++.h>
using namespace std;

constexpr int kN = 400 + 5;

void Solve() {
    char s[kN], t[kN];
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1, j = 1; i <= n; ++i) {
        if (j <= m && s[i] == t[j]) j++;
        if (j > m) {
            puts("YES");
            return;
        }
    }
    for (int k = 1; k < m; ++k) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -(n + 1)));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (dp[i][j] < 0) continue;
                if (j + 1 <= k && s[i + 1] == t[j + 1]) {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                }
                if (dp[i][j] + 1 <= m - k && s[i + 1] == t[k + dp[i][j] + 1]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
                }
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }
        if (dp[n][k] == m - k) {
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) Solve();
}