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
        vector<int> deg(n);
        vector<pair<int, int>> e;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            deg[x]++;
            deg[y]++;
            if (x > y) {
                swap(x, y);
            }
            g[x].emplace_back(i);
            g[y].emplace_back(i);
            e.emplace_back(x, y);
        }
        if (*max_element(deg.begin(), deg.end()) > 2) {
            cout << -1 << '\n';
            continue;
        }
        int r = (int) (min_element(deg.begin(), deg.end()) - deg.begin());
        vector<int> order;
        function<void(int, int)> dfs = [&](int v, int p) {
            for (int id : g[v]) {
                if (id == p) {
                    continue;
                }
                order.emplace_back(id);
                int to = e[id].first ^ e[id].second ^ v;
                dfs(to, id);
            }
        };
        dfs(r, -1);
        vector<int> ans(n - 1);
        for (int i = 0; i < n - 1; i++) {
            ans[order[i]] = i % 2 + 2;
        }
        for (int i = 0; i < n - 1; i++) {
            cout << ans[i] << " \n"[i == n - 2];
        }
    }
    return 0;
}