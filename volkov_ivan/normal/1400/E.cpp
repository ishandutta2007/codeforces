#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5007;
int a[N], dp[N][N], pref[N], suff[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
        int c = (a[0] == i ? 0 : 1);
        dp[0][i] = i + c;
        if (a[0] < i) dp[0][i] = N;
    }
    for (int i = 1; i < n; i++) {
        pref[0] = dp[i - 1][0];
        for (int j = 1; j <= n; j++) pref[j] = min(pref[j - 1], dp[i - 1][j] - j);
        suff[n] = dp[i - 1][n];
        for (int j = n - 1; j >= 0; j--) suff[j] = min(suff[j + 1], dp[i - 1][j]);
        for (int j = 0; j <= n; j++) {
            dp[i][j] = N;
            if (j > a[i]) continue;
            int c = (a[i] == j ? 0 : 1);
            dp[i][j] = min(dp[i][j], min(suff[j], pref[j] + j) + c);
        }
    }
    int res = dp[n - 1][0];
    for (int i = 1; i <= n; i++) res = min(res, dp[n - 1][i]);
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}