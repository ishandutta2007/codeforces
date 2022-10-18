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
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        a--, b--;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        if (db < 2 * da + 1) {
            cout << "Alice" << '\n';
            continue;
        }
        int c = 2 * da + 1;
        string ans = "Bob";
        function<void(int, int, int)> check = [&](int v, int p, int d) {
            if (v == b) {
                ans = "Alice";
            }
            if (d == da) {
                return;
            }
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                check(to, v, d + 1);
            }
        };
        check(a, -1, 0);
        // if (ans == "Alice") {
        //     cout << ans << '\n';
        //     continue;
        // }
        vector<int> depth(n), md(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                depth[to] = depth[v] + 1;
                dfs(to, v);
                md[v] = max(md[v], md[to] + 1);
            }
        };
        dfs(0, -1);
        function<void(int, int)> reroot = [&](int v, int p) {
            // debug(v, md);
            if (md[v] <= da) {
                ans = "Alice";
            }
            vector<int> a(g[v].size() + 2, -1);
            for (int i = 0; i < g[v].size(); i++) {
                a[i + 1] = md[g[v][i]];
            }
            vector<int> l = a, r = a;
            for (int i = 1; i < a.size(); i++) {
                l[i] = max(l[i], l[i - 1]);
            }
            for (int i = a.size() - 2; i >= 0; i--) {
                r[i] = max(r[i], r[i + 1]);
            }
            int id = 0;
            for (int to : g[v]) {
                id++;
                if (to == p) {
                    continue;
                }
                int tv = md[v];
                int tto = md[to];
                md[v] = max(l[id - 1], r[id + 1]) + 1;
                md[to] = max(md[to], md[v] + 1);
                reroot(to, v);
                md[v] = tv;
                md[to] = tto;
            }
        };
        reroot(0, -1);
        cout << ans << '\n';
    }
    return 0;
}