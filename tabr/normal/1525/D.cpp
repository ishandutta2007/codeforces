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
    vector<int> a(n);
    vector<int> b, c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) {
            b.emplace_back(i);
        } else {
            c.emplace_back(i);
        }
    }
    int x = (int)b.size(), y = (int)c.size();
    int inf = (int)1e9;
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(c[j] - b[i]));
        }
    }
    for (int j = 0; j < y; j++) {
        dp[x][j + 1] = min(dp[x][j], dp[x][j + 1]);
    }
    cout << dp[x][y] << '\n';
    return 0;
}