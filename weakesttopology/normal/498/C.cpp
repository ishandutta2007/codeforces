#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
struct Dinic {
    struct Edge {
        int from, to;
        T cap, flow = 0;
        T free() { return cap - flow; }
        Edge(int u, int v, const T& cap) : from(u), to(v), cap(cap) {}
    };
    vector<Edge> edges;
    const T inf = numeric_limits<T>::max(), zero = 0;
    int n, m = 0;
    vector<vector<int>> E;
    vector<int> level, ptr;
    Dinic(int n) : n(n) {
        E.resize(n), level.resize(n), ptr.resize(n);
    }
    int add_edge(int u, int v, const T& cap) {
        assert(cap >= 0);
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, zero);
        E[u].push_back(m++);
        E[v].push_back(m++);
        return m - 2;
    }
    bool bfs(int s, int t) {
        fill(all(level), 0); level[s] = 1;
        static queue<int> q; q.push(s);
        while (not q.empty()) {
            int u = q.front(); q.pop();
            for (auto idx : E[u]) {
                int v = edges[idx].to;
                if (level[v] != 0 || edges[idx].free() <= 0) continue;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != 0;
    }
    T push(int u, int t, T pushed) {
        if (u == t || pushed == 0) return pushed;
        for (int& idx = ptr[u]; idx < (int)size(E[u]); ++idx) {
            auto &edge = edges[E[u][idx]], &back = edges[E[u][idx] ^ 1];
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
            fill(all(ptr), 0);
            while (T pushed = push(s, t, inf)) f += pushed;
        }
        return f;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    const int maxlog = 30, src = n * maxlog, snk = src + 1;
    Dinic<int> dinic(n * maxlog + 2);

    map<pair<int, int>, int> Id;
    int ptr = 0;
    auto get = [&](int u, ll pr) {
        pair p(u, pr);
        return Id.count(p) ? Id[p] : Id[p] = ptr++;
    };

    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        if (u % 2) swap(u, v);

        ll g = gcd(a[u], a[v]);
        for (ll p = 2; p * p <= g; ++p) if (g % p == 0) {
            while (g % p == 0) g /= p;
            dinic.add_edge(get(u, p), get(v, p), INF);
        }
        if (g > 1) dinic.add_edge(get(u, g), get(v, g), INF);
    }

    for (auto [key, id] : Id) {
        auto [u, p] = key;

        int w = 0;
        for (int x = a[u]; x % p == 0; x /= p, w += 1);

        if (u % 2 == 0) dinic.add_edge(src, id, w);
        else dinic.add_edge(id, snk, w);
    }

    int res = dinic.flow(src, snk);
    cout << res << endl;

    exit(0);
}