#include <bits/stdc++.h>
using namespace std;

struct union_find {
    union_find(int n = 0) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) swap(u, v);
            parent[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }

    vector<int> parent, size;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        for (auto &i : p) cin >> i, --i;

        union_find dsu(n);
        for (int i = 0; i < n; ++i)
            dsu.unite(i, p[i]);

        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[p[i]] = i;

        vector<int> answer = pos;
        for (int i = 1; i < n; ++i) {
            if (!dsu.same(i - 1, i)) {
                swap(answer[i - 1], answer[i]);
                dsu.unite(i - 1, i);
            }
        }

        for (int i = 0, u = 0; i < n; ++i) {
            cout << u + 1 << " ";
            u = answer[u];
        }
        cout << "\n";
    }
}