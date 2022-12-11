#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 5e4 + 7;
int dp[N][3];
int a[N];

void solve() {
    int n;
    cin >> n;
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = -N;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = dp[i][2] = -N;
    }
    int x;
    cin >> x;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = 1 + dp[i - 1][0];
        if (i > 1 && a[i] + a[i - 1] >= 2 * x) {
            dp[i][2] = max(dp[i][2], dp[i - 1][1] + 1);
            if (i > 2 && a[i] + a[i - 1] + a[i - 2] >= 3 * x)
                dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
        }
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}