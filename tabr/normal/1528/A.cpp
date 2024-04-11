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
        vector<vector<long long>> a(n, vector<long long>(2));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<vector<long long>> dp(n, vector<long long>(2));
        function<void(int, int)> dfs = [&](int v, int p) {
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                dfs(to, v);
                for (int i = 0; i < 2; i++) {
                    long long add = 0;
                    for (int j = 0; j < 2; j++) {
                        add = max(add, dp[to][j] + abs(a[to][j] - a[v][i]));
                    }
                    dp[v][i] += add;
                }
            }
        };
        dfs(0, -1);
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }
    return 0;
}