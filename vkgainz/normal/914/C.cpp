#include <bits/stdc++.h>
using namespace std;

long long dp[1001][1001][2];
int num[1001];

int main() {
    string s; cin >> s;
    int k; cin >> k;
    if (k == 0) {
        cout << 1 << "\n";
        return 0;
    }
    dp[0][0][1] = 1;
    long long MOD = 1e9 + 7;
    for (int i = 1; i <= (int) s.length(); i++) {
        for (int j = 0; j <= 1000; j++) {
            if (j >= (s[i - 1] - '0'))
                dp[i][j][1] = dp[i - 1][j - (s[i - 1] - '0')][1];
            dp[i][j][0] = dp[i - 1][j][0];
            if (j > 0) dp[i][j][0] += dp[i - 1][j - 1][0];
            if (s[i - 1] == '1') {
                dp[i][j][0] += dp[i - 1][j][1];
            }
            dp[i][j][1] %= MOD, dp[i][j][0] %= MOD;
        }
    }
    num[1] = 0;
    for (int i = 2; i <= 1000; i++) {
        num[i] = num[__builtin_popcount(i)] + 1;
    }
    long long ans = 0LL;
    for (int i = 1; i <= 1000; i++) {
        if (num[i] == k - 1)
            ans += dp[(int) s.length()][i][0] + dp[(int) s.length()][i][1];
        ans %= MOD;
    }
    if (k == 1)
        --ans;
    cout << ans << "\n";
}