#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> par, sz;
    void init(int n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.resize(n);
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }
};

dsu x, y;
int main() {
    int n; cin >> n;
    int m1, m2; cin >> m1 >> m2;
    x.init(n), y.init(n);
    for (int i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        x.merge(u, v);
    }
    for (int i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        y.merge(u, v);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x.find(i) == x.find(j) || y.find(i) == y.find(j)) continue;
            x.merge(i, j);
            y.merge(i, j);
            ans.push_back({i + 1, j + 1});
        }
    }
    cout << (int) ans.size() << "\n";
    for (auto &it : ans)
        cout << it.first << " " << it.second << "\n";
}