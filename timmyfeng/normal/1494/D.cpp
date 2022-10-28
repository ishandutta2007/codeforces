#include <bits/stdc++.h>
using namespace std;

const int N = 501;

vector<array<int, 2>> edges;
int salary[2 * N];

struct union_find {
    vector<int> par, size;

    union_find(int n) {
        par.resize(n);
        size.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (par[u] != u) {
            par[u] = find(par[u]);
        }
        return par[u];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        edges.push_back({u, v});
        u = find(u), v = find(v);
        if (u != v) {
            par[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> events;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a;
            cin >> a;
            if (i == j) {
                salary[i] = a;
            } else if (i < j) {
                events.push_back({a, i, j});
            }
        }
    }
    sort(events.begin(), events.end());

    union_find dsu(2 * n);
    for (auto [a, u, v] : events) {
        u = dsu.find(u), v = dsu.find(v);
        if (u != v) {
            if (a == salary[u]) {
                dsu.unite(v, u);
            } else if (a == salary[v]) {
                dsu.unite(u, v);
            } else {
                salary[++n] = a;
                dsu.unite(u, n);
                dsu.unite(v, n);
            }
        }
    }

    cout << n << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << salary[i] << " ";
    }
    cout << "\n";
    cout << dsu.find(1) << "\n";
    for (auto [u, v] : edges) {
        cout << u << " " << v << "\n";
    }
}