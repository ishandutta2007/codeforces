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
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                a[i][j] = s[j] - '0';
            }
        }
        vector<vector<int>> pref(h + 1, vector<int>(w + 1));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + a[i][j];
            }
        }
        int ans = h * w;
        for (int x = 0; x < h; x++) {
            for (int y = x + 4; y < h; y++) {
                vector<int> b(w), c(w);
                for (int j = 0; j < w; j++) {
                    b[j] = pref[y][j + 1] - pref[x + 1][j + 1] - pref[y][j] + pref[x + 1][j];
                    c[j] = y - x - 1 - b[j];
                    b[j] += 2 - (a[x][j] + a[y][j]);
                }
                swap(b, c);
                debug(x, y, b, c);
                vector<int> dp(3, h * w);
                for (int j = 0; j < w; j++) {
                    ans = min(ans, dp[2] + b[j]);
                    dp[2] = min(dp[2] + c[j], dp[1] + c[j]);
                    dp[1] = dp[0] + c[j];
                    dp[0] = b[j];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}