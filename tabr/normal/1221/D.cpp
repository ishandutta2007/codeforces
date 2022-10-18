#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        rep(i, 0, n) cin >> a[i] >> b[i];
        vector<vector<ll>> dp(3, vector<ll>(n));
        dp[1][0] = b[0];
        dp[2][0] = 2LL * b[0];

        rep(i, 1, n) {
            ll mnn = min({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
            if (a[i - 1] + 2 < a[i] || a[i] < a[i - 1] - 2) {
                dp[0][i] = mnn;
                dp[1][i] = dp[0][i] + b[i];
                dp[2][i] = dp[1][i] + b[i];
            } else if (a[i - 1] + 2 == a[i]) {
                dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
                dp[1][i] = mnn + b[i];
                dp[2][i] = dp[1][i] + b[i];
            } else if (a[i - 1] + 1 == a[i]) {
                dp[0][i] = min(dp[0][i - 1], dp[2][i - 1]);
                dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + b[i];
                dp[2][i] = mnn + b[i] * 2LL;
            } else if (a[i - 1] == a[i]) {
                dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]);
                dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + b[i];
                dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + b[i] * 2LL;
            } else if (a[i - 1] - 1 == a[i]) {
                dp[0][i] = mnn;
                dp[1][i] = min(dp[1][i - 1], dp[2][i - 1]) + b[i];
                dp[2][i] = min(dp[0][i - 1], dp[2][i - 1]) + b[i] * 2LL;
            } else {
                dp[0][i] = mnn;
                dp[1][i] = mnn + b[i];
                dp[2][i] = min(dp[1][i - 1], dp[2][i - 1]) + b[i] * 2LL;
            }
        }
        cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << endl;
    }

    return 0;
}