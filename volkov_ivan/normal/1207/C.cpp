#include <iostream>
#include <cstring>
#define int long long

using namespace std;

const int INF = 1e18;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        s += "0";
        int dp[n + 1][2];
        for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = INF;
        dp[0][0] = b;
        for (int i = 0; i < n; i++) {
            //cout << dp[i][0] << ' ' << dp[i][1] << endl;
            //if (s[i] == '1') dp[i][0] = INF;
            if (s[i + 1] == '0') {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a + b);
                if (s[i] == '0') dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 2 * a + b);
            }
            dp[i + 1][1] = min(dp[i + 1][1], min(dp[i][1] + a + 2 * b, dp[i][0] + 2 * a + 2 * b));
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}