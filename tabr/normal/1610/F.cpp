#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct edge {
    int from;
    int to;
    int w;
    edge() {}
    edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {}
};

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector g(2, vector<vector<int>>(n));
    vector<edge> edges(m);
    vector<int> c(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--, z--;
        g[z][x].emplace_back(i);
        g[z][y].emplace_back(i);
        edges[i] = edge(x, y, z);
        if (z == 0) {
            c[x] ^= 1;
            c[y] ^= 1;
        }
    }
    vector<vector<pair<int, int>>> f(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            while (g[j][i].size() >= 2) {
                int x = g[j][i].back();
                g[j][i].pop_back();
                int y = g[j][i].back();
                g[j][i].pop_back();
                f[x].emplace_back(y, i);
                f[y].emplace_back(x, i);
            }
        }
        if (g[0][i].size() == 1 && g[1][i].size() == 1) {
            int x = g[0][i].back();
            g[0][i].pop_back();
            int y = g[1][i].back();
            g[1][i].pop_back();
            f[x].emplace_back(y, i);
            f[y].emplace_back(x, i);
        }
    }
    string ans(m, '0');
    for (int i = 0; i < m; i++) {
        if (ans[i] != '0') {
            continue;
        }
        if (f[i].empty()) {
            ans[i] = '1';
            continue;
        }
        int j = f[i][0].first;
        vector<int> a;
        vector<int> b;
        function<void(int, int)> dfs = [&](int v, int p) {
            a.emplace_back(v);
            for (auto [to, u] : f[v]) {
                if (to == p || to == i || to == j) {
                    continue;
                }
                b.emplace_back(u);
                dfs(to, v);
            }
        };
        dfs(j, i);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        b.emplace_back(f[i][0].second);
        dfs(i, j);
        ans[a[0]] = '1';
        debug(a);
        debug(b);
        for (int it = 1; it < (int) a.size(); it++) {
            int x = a[it - 1];
            int y = a[it];
            ans[y] = ans[x];
            int z = b[it - 1];
            if ((z == edges[x].from) == (z == edges[y].from)) {
                ans[y] ^= '1';
                ans[y] ^= '2';
            }
        }
    }
    cout << accumulate(c.begin(), c.end(), 0) << '\n';
    cout << ans << '\n';
    return 0;
}