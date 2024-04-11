#include <iostream>
 
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, m, a, l, r, pos, w;
    cin >> a >> n >> m;
    bool rain[a + 1];
    for (int i = 0; i <= a; i++) rain[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        for (int j = l + 1; j <= r; j++) rain[j] = 1;
    }
    pair <int, int> ambr[m + 1];
    for (int i = 1; i <= m; i++) {
        cin >> pos >> w;
        ambr[i] = make_pair(pos, w);
    }
    int dp[a + 1][m + 1];
    dp[0][0] = 0;
    int f, next_f = INF;
    for (int i = 1; i <= m; i++) {
        if (ambr[i].first == 0) {
            dp[0][i] = 0;
            next_f = min(next_f, ambr[i].second);
        }
        else dp[0][i] = INF;
    }
    for (int i = 1; i <= a; i++) {
        f = next_f;
        next_f = INF;
        if (rain[i]) dp[i][0] = f;
        else dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= m; j++) {
            if (ambr[j].first > i) {
                dp[i][j] = INF;
                continue;
            }
            if (ambr[j].first < i) {
                dp[i][j] = min(INF, dp[i - 1][j] + ambr[j].second);
            }
            if (ambr[j].first == i) dp[i][j] = dp[i][0];
            next_f = min(next_f, dp[i][j] + ambr[j].second);
        }
    }
    int ans = INF;
    for (int i = 0; i <= m; i++) {
        ans = min(ans, dp[a][i]);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}