#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
pair<int, int> dp[2][maxn];
pair<int, int> p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
    sort(p + 1, p + n + 1);
    dp[0][0].second = dp[1][0].second = -inf;
    for (int i = 1; i <= n; ++i) {
        int l = p[i].first - p[i].second, r = p[i].first + p[i].second;
        dp[0][i].first = max(dp[0][i - 1].first, dp[1][i - 1].first); dp[0][i].second = p[i].first;
        for (int j = 0; j < 2; ++j) {
            if (l > dp[j][i - 1].second) {
                if (dp[j][i - 1].first + 1 > dp[1][i].first) dp[1][i].first = dp[j][i - 1].first + 1, dp[1][i].second = p[i].first;
                else if (dp[j][i - 1].first + 1 == dp[1][i].first) dp[1][i].second = min(dp[1][i].second, p[i].first);
            }
            if ((i < n && r < p[i + 1].first) || i == n) {
                if (dp[j][i - 1].first + 1 > dp[1][i].first) dp[1][i].first = dp[j][i - 1].first + 1, dp[1][i].second = r;
                else if (dp[j][i - 1].first + 1 == dp[1][i].first) dp[1][i].second = min(dp[1][i].second, r);
            }
        }
        // cout << dp[0][i].first << ' ' << dp[0][i].second << ' ' << dp[1][i].first << ' ' << dp[1][i].second << endl;
    }
    cout << max(dp[0][n].first, dp[1][n].first) << endl;
    return 0;
}