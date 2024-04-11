#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, mod;
    cin >> n >> mod;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(j + 1 <= n) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (j + 1)) % mod;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 2 * j) % mod;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i) ans += dp[i][n + 1 - i];
    ans %= mod;
    cout << ans << '\n';
}