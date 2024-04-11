#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
struct Dinic {
    inline static const T inf = numeric_limits<T>::max();
    struct Edge {
        int from, to;
        T cap, flow = 0;
        T free() const { return cap - flow; }
        Edge(int u, int v, T cap) : from(u), to(v), cap(cap) {}
    };
    vector<Edge> edges;
    int n, m = 0;
    vector<vector<int>> E;
    vector<int> level, ptr;
    Dinic(int n) : n(n), E(n), level(n), ptr(n) {}
    int add_edge(int u, int v, T cap) {
        assert(cap >= 0);
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        E[u].push_back(m++);
        E[v].push_back(m++);
        return m - 2;
    }
    bool bfs(int s, int t) {
        fill(begin(level), end(level), -1);
        level[s] = 0;
        static queue<int> q;
        q.push(s);
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            for (auto j : E[u]) {
                int v = edges[j].to;
                if (level[v] != -1 || edges[j].free() <= 0) continue;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != -1;
    }
    T push(int u, int t, T pushed) {
        if (u == t || pushed == 0) return pushed;
        for (int& i = ptr[u]; i < (int)size(E[u]); ++i) {
            auto &edge = edges[E[u][i]], &back = edges[E[u][i] ^ 1];
            if (level[edge.to] != level[u] + 1 || edge.free() <= 0) continue;
            T pushing = push(edge.to, t, min(pushed, edge.free()));
            if (pushing == 0) continue;
            edge.flow += pushing, back.flow -= pushing;
            return pushing;
        }
        return 0;
    }
    T flow(int s, int t) {
        for (auto& edge : edges) edge.flow = 0;
        T f = 0;
        while (bfs(s, t)) {
            fill(begin(ptr), end(ptr), 0);
            while (T pushed = push(s, t, inf)) f += pushed;
        }
        return f;
    }
    bool cut(int j) const {
        return edges[j].free() == 0 && level[edges[j].from] != -1 && level[edges[j].to] == -1;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back({v, i}), E[v].push_back({u, i});
    }
    constexpr int K = 14;
    vector<array<int, K>> up(n);
    vector<int> h(n), f(n);
    auto dfs = [&](auto& self, int u, int p) -> void {
        up[u][0] = p;
        for (int k = 0; k + 1 < K; ++k) {
            up[u][k + 1] = up[up[u][k]][k];
        }
        for (auto [v, i] : E[u]) {
            if (v == p) continue;
            h[v] = h[u] + 1, f[v] = i;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, 0);
    const int N = m + n * K, src = N, snk = N + 1;
    Dinic<int> dinic(N + 2);
    auto id = [&](int u, int k) { return m + u * K + k; };
    vector<int> cid(m), gid(n);
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cid[j] = dinic.add_edge(src, j, 1);
        if (h[u] < h[v]) swap(u, v);
        int d = h[u] - h[v];
        for (int k = 0; k < K; ++k) {
            if (d >> k & 1) {
                dinic.add_edge(j, id(u, k), Dinic<int>::inf);
                u = up[u][k];
            }
        }
        if (u == v) continue;
        for (int k = K - 1; k >= 0; --k) {
            int nu = up[u][k], nv = up[v][k];
            if (nu != nv) {
                for (int w : {u, v}) {
                    dinic.add_edge(j, id(w, k), Dinic<int>::inf);
                }
                u = nu, v = nv;
            }
        }
        for (int w : {u, v}) {
            dinic.add_edge(j, id(w, 0), Dinic<int>::inf);
        }
    }
    for (int u = 0; u < n; ++u) {
        for (int k = 0; k + 1 < K; ++k) {
            for (int w : {u, up[u][k]}) {
                dinic.add_edge(id(u, k + 1), id(w, k), Dinic<int>::inf);
            }
        }
        gid[u] = dinic.add_edge(id(u, 0), snk, 1);
    }
    int flow = dinic.flow(src, snk);
    cerr << "flow == " << flow << endl;
    vector<int> cs, gs;
    for (int j = 0; j < m; ++j) {
        if (dinic.cut(cid[j])) {
            cs.push_back(j);
        }
    }
    for (int u = 0; u < n; ++u) {
        if (dinic.cut(gid[u])) {
            gs.push_back(f[u]);
        }
    }
    int q = (int)size(cs), e = (int)size(gs), k = q + e;
    cout << k << endl;
    cout << q;
    for (int i = 0; i < q; ++i) {
        cout << " " << cs[i] + 1;
    }
    cout << endl;
    cout << e;
    for (int i = 0; i < e; ++i) {
        cout << " " << gs[i] + 1;
    }
    cout << endl;
    exit(0);
}