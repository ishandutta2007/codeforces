#include <iostream>

using namespace std;

long long mod = 998244353, n, m, k, dp[2005][2005];
// # of bricks, # of diff color


int main() {
    cin >> n >> m >> k;
    dp[1][0] = m;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] += dp[i-1][j-1] * (m-1) + dp[i-1][j];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][k] % mod << endl;
}