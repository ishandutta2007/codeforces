#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(2);
    for (int i = 0; i < 2; i++) {
        cin >> s[i];
        s[i] += "0";
    }
    vector dp(2, vector<int>(2, -10101010));
    dp[0][0] = 0;
    dp[0][s[1][0] - '0'] = 0;
    for (int i = 0; i < n; i++) {
        vector new_dp(2, vector<int>(2, -10101010));
        for (int x = 0; x < 2; x++) {
            new_dp[x][s[x ^ 1][i + 1] - '0'] = max(new_dp[x][s[x ^ 1][i + 1] - '0'], dp[x][0] + (s[x][i + 1] - '0'));
            new_dp[x][0] = max(new_dp[x][0], dp[x][0] + (s[x][i + 1] - '0'));
            new_dp[x ^ 1][0] = max(new_dp[x ^ 1][0], dp[x][1] + 1 + (s[x ^ 1][i + 1] - '0'));
        }
        swap(dp, new_dp);
    }
    int ans = -1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}