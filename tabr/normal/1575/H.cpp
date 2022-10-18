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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<int> ng(m);
    int ok = 0;
    for (int i = 0; i < m; i++) {
        string c = b.substr(0, i);
        c += b[i] ^ 1;
        while (!c.empty()) {
            if (c == b.substr(0, c.size())) {
                ng[i] = (int) c.size();
                break;
            }
            c.erase(c.begin());
        }
    }
    {
        string c = b;
        c.erase(c.begin());
        while (!c.empty()) {
            if (c == b.substr(0, c.size())) {
                ok = (int) c.size();
                break;
            }
            c.erase(c.begin());
        }
    }
    debug(ng, ok);
    int inf = (int) 1e9;
    vector<vector<int>> dp(m, vector<int>(n - m + 2, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> new_dp(m, vector<int>(n - m + 2, inf));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n - m + 1; k++) {
                if (a[i] == b[j]) {
                    if (j == m - 1) {
                        new_dp[ok][k + 1] = min(new_dp[ok][k + 1], dp[j][k]);
                    } else {
                        new_dp[j + 1][k] = min(new_dp[j + 1][k], dp[j][k]);
                    }
                    new_dp[ng[j]][k] = min(new_dp[ng[j]][k], dp[j][k] + 1);
                } else {
                    if (j == m - 1) {
                        new_dp[ok][k + 1] = min(new_dp[ok][k + 1], dp[j][k] + 1);
                    } else {
                        new_dp[j + 1][k] = min(new_dp[j + 1][k], dp[j][k] + 1);
                    }
                    new_dp[ng[j]][k] = min(new_dp[ng[j]][k], dp[j][k]);
                }
            }
        }
        swap(dp, new_dp);
    }
    vector<int> ans(n - m + 2, inf);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - m + 2; j++) {
            ans[j] = min(ans[j], dp[i][j]);
        }
    }
    for (int i = 0; i < n - m + 2; i++) {
        if (ans[i] == inf) {
            ans[i] = -1;
        }
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}