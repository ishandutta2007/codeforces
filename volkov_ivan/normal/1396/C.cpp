#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 7, INF = 1e18;
int dp[N][3], a[N];
int t[N][2];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    int d;
    cin >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t[i][0] = a[i] * min(r1, r3) + r3;
        t[i][1] = r2 + min(r1, min(r2, r3));
        t[i][1] = min(t[i][1], a[i] * min(r1, r3) + min(r3, min(2 * r1, 2 * r2)));
        //cout << t[i][0] << ' ' << t[i][1] << endl;
    }
    for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = dp[i][2] = INF;
    dp[0][0] = 0;
    dp[0][2] = (n - 1) * d;
    for (int i = 1; i <= n; i++) {
        int c = (i == 1 ? 0 : d);
        dp[i][0] = dp[i - 1][0] + c + t[i][0];
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + c + min(t[i][0], t[i][1]));
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + c + t[i][1] + 2 * d);
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + c + min(t[i][0], t[i][1]) + 2 * d;
        if (i != n) dp[i][2] = dp[i - 1][2] + min(t[i][0], t[i][1]) + c; 
        if (i == n) {
            dp[n][2] = dp[n - 1][2] + c + t[i][0];
            //cout << dp[n - 1][2] << endl;
            dp[n][2] = min(dp[n][2], dp[n - 1][2] + c + t[i][1] + 2 * d);
            //cout << dp[n][2] << endl;
        }
        if (i != n) dp[i][2] = min(dp[i][2], min(dp[i - 1][0], dp[i - 1][1]) + c + min(t[i][0], t[i][1]) + d * (n - i));
        //cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    }
    cout << min(dp[n][0], dp[n][2]) << "\n";
    return 0;
}