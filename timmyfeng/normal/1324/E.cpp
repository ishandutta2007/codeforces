#include <bits/stdc++.h>
using namespace std;

int dp[2000 + 1][2000];
int a[2000 + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < h; ++j) {
            dp[i][j] = max(
                    dp[i - 1][(j - a[i] + 1 + h) % h],
                    dp[i - 1][(j - a[i] + h) % h]
            );
            if (j >= l && j <= r && dp[i][j] != -1) {
                ans = max(ans, ++dp[i][j]);
            }
        }
    }
    cout << ans;
}