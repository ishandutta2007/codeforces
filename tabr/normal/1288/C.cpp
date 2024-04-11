#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, mod = 1e9 + 7;
    cin >> n >> m;
    vector<vector<ll>> dp(1010, vector<ll>(1010));
    dp[0][n + 1] = -1;
    while (m--) {
        rep(i, 1, n + 1) for (int j = n; j > 0; j--) {
            dp[i][j] =
                (dp[i][j] + dp[i - 1][j] + dp[i][j + 1] - dp[i - 1][j + 1]) %
                mod;
            if (dp[i][j] < 0) dp[i][j] += mod;
        }
        dp[0][n + 1] = 0;
    }
    ll ans = 0;
    rep(i, 1, n + 1) rep(j, i, n + 1) {
        ans = (ans + dp[i][j]) % mod;
    }
    cout << ans << endl;
    return 0;
}