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
    int find_color(int u) {
        find(u);
        return color[u];
    }
    // check if it doesn't create an odd cycle
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
            if (rk[pu] < rk[pv]) swap(pu, pv);
            if (color[u] == color[v]) color[pv] ^= 1;
            p[pv] = pu, rk[pu] += (rk[pu] == rk[pv]);
            if (not bipartite[pv]) bipartite[pu] = false;
            return true;
        }
    }
};

using Edge = array<int, 3>;
vector<Edge> operator+(const vector<Edge>& lhs, const vector<Edge>& rhs) {
    vector<Edge> E, res;
    merge(all(lhs), all(rhs), back_inserter(E));
    DSU dsu(accumulate(all(E), 0, [](int x, Edge e){ return max({x, e[1], e[2]}); }) + 1);
    reverse(all(E));
    for (auto [w, u, v] : E) {
        if (not dsu.can(u, v)) {
            res.push_back({w, u, v});
            break;
        }
        else if (dsu.unite(u, v)) {
            res.push_back({w, u, v});
        }
    }
    reverse(all(res));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edges(m);
    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
        --u, --v;
    }

    vector<vector<Edge>> st(2 * m);
    for (int j = 0; j < m; ++j) {
        st[m + j] = {edges[j]};
    }
    for (int p = m - 1; p; --p) {
        st[p] = st[p << 1] + st[p << 1 | 1];
    }

    auto query = [&](int l, int r) {
        vector<Edge> res;
        for (l += m, r += m + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = res + st[l++];
            if (r & 1) res = res + st[--r];
        }
        return res;
    };

    for (int z = 0; z < q; ++z) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        auto E = query(l, r);
        DSU dsu(n);
        int ans = -1;
        reverse(all(E));
        for (auto [w, u, v] : E) {
            if (not dsu.can(u, v)) {
                ans = w;
                break;
            }
            dsu.unite(u, v);
        }

        cout << ans << endl;
    }

    exit(0);
}