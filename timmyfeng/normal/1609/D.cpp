#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    union_find dsu(n + 1);
    int samples = 1;

    while (d--) {
        int u, v;
        cin >> u >> v;

        samples += !dsu.unite(u, v);

        vector<int> sizes;
        for (int i = 1; i <= n; ++i) {
            if (i == dsu.find(i)) {
                sizes.push_back(dsu.size[i]);
            }
        }

        sort(sizes.rbegin(), sizes.rend());

        cout << accumulate(sizes.begin(), sizes.begin() + samples, 0) - 1 << "\n";
    }
}