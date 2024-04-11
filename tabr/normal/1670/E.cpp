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
        int q;
        cin >> q;
        int n = 1 << q;
        vector<vector<int>> g(n);
        vector<pair<int, int>> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(i);
            g[y].emplace_back(i);
            edges[i] = make_pair(x, y);
        }
        vector<int> ans(2 * n - 1);
        vector<int> depth(n);
        function<void(int, int)> Dfs = [&](int v, int p) {
            for (int id : g[v]) {
                int to = v ^ edges[id].first ^ edges[id].second;
                if (to == p) {
                    continue;
                }
                ans[n + id] = n + id + 1;
                ans[to] = id + 1;
                if (depth[v] % 2 == 1) {
                    swap(ans[n + id], ans[to]);
                }
                depth[to] = depth[v] + 1;
                Dfs(to, v);
            }
        };
        ans[0] = n;
        Dfs(0, -1);
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            cout << ans[i + n] << " \n"[i == n - 2];
        }
    }
    return 0;
}