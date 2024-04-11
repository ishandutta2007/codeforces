#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2007, M = 998244353;
int dp[N][2], ndp[N][2];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    s = "-" + s;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        memset(ndp, 0, sizeof(ndp));
        //memcpy(ndp, dp, sizeof(dp));
        for (int j = 0; j <= n; j++) {
            if (s[i] != ')') {
                ndp[j + 1][0] += dp[j][0];
                ndp[j][1] += dp[j][1];
                ndp[j][1] += dp[j][0] * j;
            }
            if (s[i] != '(') {
                ndp[j][0] += dp[j][0];
                if (j != 0) {
                    ndp[j - 1][1] += dp[j][1];
                    ndp[j - 1][1] += dp[j][0] * j;
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            dp[j][0] = ndp[j][0] % M;
            dp[j][1] = ndp[j][1] % M;
            //cout << i << ' ' << j << ' ' << dp[j][0] << ' ' << dp[j][1] << endl;
        }
    }
    cout << dp[0][1] << endl;
}