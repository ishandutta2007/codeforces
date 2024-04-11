#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    vector<int> ct(s.size() + 1);
    for (int i = 0; i < s.size(); ++i) {
        ct[i + 1] = ct[i] + (s[i] == '?');
    }

    vector<int> powTwo(ct.back() + 1);
    powTwo[0] = 1;
    for (int i = 1; i <= ct.back(); ++i) {
        powTwo[i] = (powTwo[i - 1] + powTwo[i - 1]) % MOD;
    }

    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    for (int k = 2; k <= s.size(); ++k) {
        for (int l = 0; l + k - 1 < s.size(); ++l) {
            int r = l + k - 1;
            if (s[l] != '(') {
                dp[l][r] += dp[l + 1][r], dp[l][r] %= MOD;
            }
            if (s[r] != ')') {
                dp[l][r] += dp[l][r - 1], dp[l][r] %= MOD;
            }
            if (s[l] != '(' && s[r] != ')') {
                dp[l][r] -= dp[l + 1][r - 1], dp[l][r] += MOD, dp[l][r] %= MOD;
            }
            if (s[l] != ')' && s[r] != '(') {
                dp[l][r] += dp[l + 1][r - 1], dp[l][r] %= MOD;
                dp[l][r] += powTwo[ct[r] - ct[l + 1]], dp[l][r] %= MOD;
            }
        }
    }

    cout << dp[0][s.size() - 1] << '\n';
}