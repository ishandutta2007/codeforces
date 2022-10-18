#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll dp[n + 1][3][3] = {};
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n + 1) rep(j, 0, 3) rep(k, 0, 3) dp[i][j][k] = -1e18;
    dp[0][0][0] = 0;

    rep(i, 0, n + 1) rep(j, 0, 3) rep(k, 0, 3) {
        if (k < 2)
            dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
        if (j < 2)
            dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
        if (i < n)
            dp[i + 1][j][k] =
                max(dp[i + 1][j][k],
                    dp[i][j][k] + (j == 1 ? a[i] : 0) * (k == 1 ? x : 1));
    }

    cout << dp[n][2][2] << endl;

    return 0;
}