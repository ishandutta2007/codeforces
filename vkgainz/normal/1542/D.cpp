#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<char, int>> in(n + 1);
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        if(c == '-') in[i + 1].first = c;
        else in[i +1].first = c, cin >> in[i + 1].second;
    }
    
    long long ans = 0LL, MOD = 998244353;
    for(int pos = 1; pos <= n; pos++) {
        if(in[pos].first == '-') continue;

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        dp[0][0] = 1LL;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < n; j++) {
                if(in[i].first == '+') {
                    if(i == pos) {
                        dp[i][j] += dp[i - 1][j];
                        dp[i][j] %= MOD;
                        continue;
                    }
                    bool less = (in[i].second < in[pos].second) ||
                        (in[i].second == in[pos].second && i < pos);
                    if(less) {
                        if(j > 0)
                            dp[i][j] += dp[i - 1][j - 1];
                    }
                    else
                        dp[i][j] += dp[i - 1][j];
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
                else {
                    dp[i][j] += dp[i - 1][j];
                    if(j == 0) {
                        dp[i][j] += dp[i - 1][j + 1];                   
                        if(i < pos)
                            dp[i][j] += dp[i - 1][j];
                    }
                    else {
                        dp[i][j] += dp[i - 1][j + 1];
                    }
                    dp[i][j] %= MOD;
                }
            }
        }
        for(int left = 0; left < n; left++) {
            ans += dp[n][left] * 1LL * in[pos].second % MOD;
            ans %= MOD;
        }
    }
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}