#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int s[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    dp[1] = s[1] - 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        int over = 0;
        for (int j = i - 1; j >= 1; j--) {
            over += max(0ll, s[j] - (i - j));
        }
        assert(dp[i - 1] >= over);
        dp[i] += max(0ll, s[i] - 1 - (dp[i - 1] - over));
    }
    cout << dp[n] << "\n";
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