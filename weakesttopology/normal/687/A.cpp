#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

struct DSU {
    vector<int> p, rk, color, bipartite;
    DSU(int n) : p(n), rk(n), color(n), bipartite(n, 1) {
        iota(all(p), 0);
    };
    int find(int u) {
        if (u == p[u]) return u;
        int v = find(p[u]);
        color[u] ^= color[p[u]];
        return p[u] = v;
    }
    bool find_color(int u) {
        find(u);
        return color[u];
    }
    bool can(int u, int v) {
        return find(u) != find(v) || color[u] != color[v];
    }
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) {
            if (color[u] == color[v]) bipartite[pu] = false;
            return false;
        }
        else {
            if (rk[pu] < rk[pv]) swap(u, v), swap(pu, pv);
            if (color[u] == color[v]) color[pv] ^= 1;
            p[pv] = pu, rk[pu] += (rk[pu] == rk[pv]);
            return true;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (not dsu.can(u, v)) {
            cout << -1 << endl;
            exit(0);
        }
        dsu.unite(u, v);
    }

    vector<int> A[2];
    for (int u = 0; u < n; ++u) {
        dsu.find(u);
        A[dsu.color[u]].push_back(u);
    }

    for (int t : {0, 1}) {
        int k = (int)size(A[t]);
        cout << k << endl;
        for (int j = 0; j < k; ++j) {
            cout << A[t][j] + 1 << "\n "[j + 1 < k];
        }
    }

    exit(0);
}