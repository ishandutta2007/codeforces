#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int M = 1007, N = 1e5 + 7;
int dp[N], pref[N];
int t[N], x[N], y[N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int r, n;
    cin >> r >> n;
    memset(dp, 0, sizeof(dp));
    memset(pref, 0, sizeof(pref));
    x[0] = y[0] = 1;
    t[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) {
        dp[i] = -N;
        for (int j = i - 1; j >= 0; j--) {
            if (t[i] - t[j] > M) {
                dp[i] = max(dp[i], pref[j] + 1);
                break;
            }
            int d = abs(x[j] - x[i]) + abs(y[j] - y[i]);
            //cout << i << ' ' << j << ' ' << d << endl;
            if (d <= t[i] - t[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        pref[i] = max(pref[i - 1], dp[i]);
        //cout << dp[i] << ' ' << pref[i] << endl;
    }
    cout << pref[n] << "\n";
    return 0;
}