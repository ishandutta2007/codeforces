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
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        vector<vector<int>> dp(10, vector<int>(10));
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    if (dp[x][y] % 2 == 0) {
                        if (x == c) {
                            dp[x][y]++;
                        }
                    } else {
                        if (y == c) {
                            dp[x][y]++;
                        }
                    }
                }
            }
        }
        int a = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (dp[i][j] != 1 && dp[i][j] % 2 == 1 && i != j) {
                    dp[i][j]--;
                }
                a = max(a, dp[i][j]);
            }
        }
        cout << n - a << '\n';
    }
    return 0;
}