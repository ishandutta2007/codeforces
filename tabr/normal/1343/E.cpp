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
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        a--, b--, c--;
        vector<ll> p(m), ps(m + 1);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < m; i++) {
            ps[i + 1] = p[i] + ps[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<int> da(n), db(n), dc(n);
        auto bfs = [&](int v, vector<int> &dv) {
            vector<bool> was(n);
            queue<int> que;
            que.push(v);
            was[v] = true;
            while (que.size()) {
                for (int i = que.size(); i > 0; i--) {
                    int u = que.front();
                    que.pop();
                    for (int to : g[u]) {
                        if (was[to]) continue;
                        was[to] = true;
                        dv[to] = dv[u] + 1;
                        que.push(to);
                    }
                }
            }
        };
        bfs(a, da);
        bfs(b, db);
        bfs(c, dc);
        ll ans = 1e18;
        for (int i = 0; i < n; i++) {
            int s = db[i];
            int t = da[i] + dc[i];
            ll res = ps[s];
            if (t + s > m) {
                continue;
            }
            res += ps[t + s];
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
    return 0;
}