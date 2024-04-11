#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

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
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) {
                swap(u, v);
            }
            par[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }
};

vector<int> adj[N];
bool visited[N];
long long a[N];
int order[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(4);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    iota(order, order + n, 0);
    sort(order, order + n, [&](int i, int j) {
        return a[i] > a[j];
    });

    long long ans = 0;
    union_find dsu(n);

    for (int i = 0; i < n; ++i) {
        int u = order[i];
        visited[u] = true;
        for (auto c : adj[u]) {
            if (visited[c] && !dsu.same(u, c)) {
                ans += a[u] * dsu.size[dsu.find(u)] * dsu.size[dsu.find(c)];
                dsu.unite(u, c);
            }
        }
    }

    cout << 2.0 * ans / n / (n - 1.0) << "\n";
}