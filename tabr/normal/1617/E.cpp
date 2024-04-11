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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto h = [&](int x) {
        int y = 1;
        while (y < x) {
            y <<= 1;
        }
        return y - x;
    };
    vector<int> b;
    b.emplace_back(0);
    for (int i : a) {
        while (i > 0) {
            b.emplace_back(i);
            i = h(i);
        }
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int m = (int) b.size();
    vector<int> p(m, -1);
    vector<vector<int>> g(m);
    vector<int> c(m);
    int idx = 0;
    for (int i : a) {
        c[lower_bound(b.begin(), b.end(), i) - b.begin()] = ++idx;
        while (i > 0) {
            int j = h(i);
            int x = (int) (lower_bound(b.begin(), b.end(), i) - b.begin());
            if (p[x] != -1) {
                break;
            }
            int y = (int) (lower_bound(b.begin(), b.end(), j) - b.begin());
            p[x] = y;
            g[y].emplace_back(x);
            i = j;
        }
    }
    int ans = -1;
    int whox = -1;
    int whoy = -1;
    vector<int> d(m, 100);
    vector<int> who(m, -1);
    auto dfs = [&](auto &&self, int v) -> void {
        vector<int> e, f;
        for (int to : g[v]) {
            self(self, to);
            e.emplace_back(d[to] + 1);
            f.emplace_back(who[to]);
        }
        if (c[v]) {
            if (!e.empty()) {
                int id = (int) (max_element(e.begin(), e.end()) - e.begin());
                if (e[id] > ans) {
                    ans = e[id];
                    whox = c[v];
                    whoy = f[id];
                }
            }
            d[v] = 0;
            who[v] = c[v];
        } 
        if (!e.empty()) {
            vector<int> order(e.size());
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int x, int y) { return e[x] > e[y]; });
            d[v] = e[order[0]];
            who[v] = f[order[0]];
            if ((int) e.size() > 1 && ans < e[order[0]] + e[order[1]]) {
                ans = e[order[0]] + e[order[1]];
                whox = f[order[0]];
                whoy = f[order[1]];
            }
        }
    };
    dfs(dfs, 0);
    cout << whox << " " << whoy << " " << ans << '\n';
    return 0;
}