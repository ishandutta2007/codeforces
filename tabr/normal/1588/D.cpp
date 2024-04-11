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
        int n;
        cin >> n;
        vector<int> a[10];
        vector<int> b[52][10];
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int j = 0;
            for (char c : s) {
                if (c >= 'a') {
                    a[i].emplace_back(c - 'a' + 26);
                } else {
                    a[i].emplace_back(c - 'A');
                }
                b[a[i].back()][i].emplace_back(j);
                j++;
            }
        }
        vector<vector<int>> c;
        for (int i = 0; i < 52; i++) {
            vector<int> x(n);
            function<void(int)> dfs = [&](int j) {
                if (j == n) {
                    c.emplace_back(x);
                } else {
                    for (int k : b[i][j]) {
                        x[j] = k;
                        dfs(j + 1);
                    }
                }
            };
            dfs(0);
        }
        int m = (int) c.size();
        if (m == 0) {
            cout << 0 << '\n';
            cout << '\n';
            continue;
        }
        sort(c.begin(), c.end());
        vector<int> g[m];
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < 52; k++) {
                vector<int> y(n, -1);
                for (int j = 0; j < n; j++) {
                    for (int l : b[k][j]) {
                        if (c[i][j] < l) {
                            y[j] = l;
                            break;
                        }
                    }
                    if (y[j] == -1) {
                        y[0] = -1;
                        break;
                    }
                }
                if (y[0] == -1) {
                    continue;
                }
                auto it = lower_bound(c.begin(), c.end(), y);
                g[i].emplace_back((int) (it - c.begin()));
            }
        }
        vector<int> dp(m, 1);
        vector<int> pre(m, -1);
        for (int i = 0; i < m; i++) {
            for (int j : g[i]) {
                if (dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                }
            }
        }
        int id = (int) (max_element(dp.begin(), dp.end()) - dp.begin());
        string res;
        while (id != -1) {
            int d = a[0][c[id][0]];
            if (d >= 26) {
                d -= 26;
                res += (char) ('a' + d);
            } else {
                res += (char) ('A' + d);
            }
            id = pre[id];
        }
        reverse(res.begin(), res.end());
        cout << res.size() << '\n';
        cout << res << '\n';
    }
    return 0;
}