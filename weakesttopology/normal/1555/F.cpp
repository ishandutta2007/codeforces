#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct DSU {
    vector<int> p, pc, rk;
    vector<pair<T, int>> tag;
    DSU(int N) : p(N), rk(N), tag(N) {
        iota(begin(p), end(p), 0);
        pc = p;
    }
    int find(int u) {
        return pc[u] == u ? u : pc[u] = find(pc[u]);
    }
    T query(int u, int v) {
        int last = -1;
        T res{};
        while (u != v) {
            if (rk[u] < rk[v]) swap(u, v);
            if (last < tag[v].first) {
                tie(last, res) = tag[v];
            }
            v = p[v];
        }
        return res;
    }
    int cnt = 0;
    bool unite(int u, int v, T t) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (rk[u] < rk[v]) swap(u, v);
        pc[v] = p[v] = u;
        tag[v] = {cnt++, t};
        rk[u] += (rk[u] == rk[v]);
        return true;
    }
};
template<typename T>
struct G1 {
    using Type = T;
    inline const static T Id = 0;
    static T op(const T& x, const T& y) { return x + y; }
    static T inv(const T& x) { return -x; }
};
int lsb(int b) { return b & -b; }
template<typename Group>
struct BIT {
    using G = Group;
    using T = typename G::Type;
    int n, h;
    vector<T> ft;
    BIT(int n) : n(n), h(__lg(n)), ft(n + 1, G::Id) { }
    BIT(const vector<T>& a) : BIT((int)size(a)) {
        for (int i = 1; i <= n; ++i) ft[i] = G::op(ft[i - 1], a[i - 1]);
        for (int i = n; i >= 1; --i) ft[i] = G::op(G::inv(ft[i - lsb(i)]), ft[i]);
    }
    T query(int p) const {
        T res = G::Id;
        for (++p; p >= 1; p -= lsb(p)) res = G::op(ft[p], res);
        return res;
    }
    T query(int l, int r) const {
        return G::op(G::inv(query(l - 1)), query(r));
    }
    void update(int p, T value) {
        for (++p; p <= n; p += lsb(p)) ft[p] = G::op(ft[p], value);
    }
    // first r such that cmp(query(0, r), value) == false
    template<typename S, typename Cmp>
    int lower_bound(S value, Cmp&& cmp) const {
        T prefix = G::Id;
        int pos = 0;
        for (int x = h; x >= 0; --x) {
            int npos = pos + (1 << x);
            if (npos <= n && cmp(G::op(prefix, ft[npos]), value) == true) {
                pos = npos;
                prefix = G::op(prefix, ft[pos]);
            }
        }
        return pos;
    }
    int lower_bound(T value) const {
        return lower_bound(value, less<T>());
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    DSU<int> dsu(N);
    vector<array<int, 3>> edges(Q);
    vector<vector<array<int, 2>>> E(N);
    vector<bool> on(Q);
    for (int q = 0; q < Q; ++q) {
        auto& [u, v, x] = edges[q];
        cin >> u >> v >> x;
        --u, --v;
        if (dsu.unite(u, v, -1)) {
            on[q] = true;
            E[u].push_back({v, x});
            E[v].push_back({u, x});
        }
    }
    vector<int> L(N), R(N), h(N), p(N);
    int timer = 0;
    dsu = DSU<int>(N);
    auto dfs = [&](auto& self, int u) -> void {
        L[u] = timer++;
        for (auto [v, x] : E[u]) {
            if (v == p[u]) continue;
            h[v] = h[u] ^ x;
            p[v] = u;
            self(self, v);
            dsu.unite(u, v, u);
        }
        R[u] = timer;
    };
    for (int u = 0; u < N; ++u) {
        if (L[u] == 0) {
            dfs(dfs, u);
        }
    }
    BIT<G1<int>> bit(N + 1);
    string res[2] = {"NO", "YES"};
    for (int q = 0; q < Q; ++q) {
        auto [u, v, x] = edges[q];
        bool good;
        if (on[q]) {
            good = true;
        }
        else if ((h[u] ^ h[v] ^ x) == 0) {
            good = false;
        }
        else {
            int lca = dsu.query(u, v);
            assert(L[lca] <= min(L[u], L[v]) && max(R[u], R[v]) <= R[lca]);
            int on_cycle = bit.query(L[u]) + bit.query(L[v]) - 2 * bit.query(L[lca]);
            assert(on_cycle >= 0);
            if (on_cycle) {
                good = false;
            }
            else {
                good = true;
                for (int w : {u, v}) {
                    while (w != lca) {
                        bit.update(L[w], +1);
                        bit.update(R[w], -1);
                        w = p[w];
                    }
                }
            }
        }
        cout << res[good] << '\n';
    }
    exit(0);
}