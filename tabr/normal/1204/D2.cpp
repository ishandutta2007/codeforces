#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(2, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            dp[0][i] = max(dp[0][i + 1], dp[1][i + 1]) + 1;
            dp[1][i] = dp[1][i + 1];
        } else {
            dp[0][i] = dp[0][i + 1];
            dp[1][i] = dp[1][i + 1] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            continue;
        }
        int x = max(dp[0][i], dp[1][i]);
        int y = max(dp[0][i + 1], dp[1][i + 1]);
        if (x > y) {
            s[i] = '0';
        }
    }
    cout << s << '\n';
    return 0;
}