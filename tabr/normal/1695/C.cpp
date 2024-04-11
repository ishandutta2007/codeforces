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
    int tt;
    cin >> tt;
    while (tt--) {
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<bitset<2022>>> dp(h, vector<bitset<2022>>(w));
        dp[0][0][1011 + a[0][0]] = 1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i > 0) {
                    if (a[i][j] == 1) {
                        dp[i][j] |= dp[i - 1][j] << 1;
                    } else {
                        dp[i][j] |= dp[i - 1][j] >> 1;
                    }
                }
                if (j > 0) {
                    if (a[i][j] == 1) {
                        dp[i][j] |= dp[i][j - 1] << 1;
                    } else {
                        dp[i][j] |= dp[i][j - 1] >> 1;
                    }
                }
            }
        }
        if (dp[h - 1][w - 1][1011]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}