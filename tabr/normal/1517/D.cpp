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
    int h, w, k;
    cin >> h >> w >> k;
    int inf = (int)1e9;
    vector<vector<int>> a(h, vector<int>(w - 1));
    vector<vector<int>> b(h - 1, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w - 1; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }
    if (k % 2 == 1) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << -1 << " ";
            }
            cout << '\n';
        }
        return 0;
    }
    vector<vector<int>> dp(h, vector<int>(w, 0));
    k /= 2;
    while (k--) {
        vector<vector<int>> new_dp(h, vector<int>(w, inf));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i != 0) {
                    new_dp[i - 1][j] = min(new_dp[i - 1][j], dp[i][j] + b[i - 1][j]);
                }
                if (i != h - 1) {
                    new_dp[i + 1][j] = min(new_dp[i + 1][j], dp[i][j] + b[i][j]);
                }
                if (j != 0) {
                    new_dp[i][j - 1] = min(new_dp[i][j - 1], dp[i][j] + a[i][j - 1]);
                }
                if (j != w - 1) {
                    new_dp[i][j + 1] = min(new_dp[i][j + 1], dp[i][j] + a[i][j]);
                }
            }
        }
        swap(dp, new_dp);
    }
    for (auto v : dp) {
        for (auto i : v) {
            cout << i * 2 << " ";
        }
        cout << '\n';
    }
    return 0;
}