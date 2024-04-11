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
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        } else if (n == 2) {
            cout << 1 << '\n';
            continue;
        }
        int r = -1;
        for (int i = 0; i < n; i++) {
            if (g[i].size() > 2) {
                r = i;
                break;
            }
        }
        if (r == -1) {
            cout << 1 << '\n';
            continue;
        }
        vector<int> dp(n);
        function<void(int, int)> Dfs = [&](int v, int p) {
            if (g[v].size() == 1) {
                return;
            }
            vector<int> c;
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                Dfs(to, v);
                c.emplace_back(dp[to]);
            }
            sort(c.begin(), c.end());
            for (int i = 0; i < (int) c.size(); i++) {
                if (i > 0) {
                    c[i] = max(c[i], 1);
                }
                dp[v] += c[i];
            }
        };
        Dfs(r, -1);
        cout << dp[r] << '\n';
    }
    return 0;
}