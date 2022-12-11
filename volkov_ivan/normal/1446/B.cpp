#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 5007;
int dp[N][N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] != t[j - 1]) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) - 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + 2;
            }
            dp[i][j] = max(dp[i][j], 0);
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}