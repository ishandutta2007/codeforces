#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        fill(begin(level), end(level), 0); level[s] = 1;
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
            fill(begin(ptr), end(ptr), 0);
            while (T pushed = push(s, t, inf)) f += pushed;
        }
        return f;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 2>> pts(n);
    map<int, int> cntrow, cntcol;
    for (auto& [x, y] : pts) {
        cin >> x >> y;
        ++cntrow[x], ++cntcol[y];
    }
    const int src = 0, snk = 1, supersrc = 2, supersnk = 3;
    map<pair<int, int>, int> Id;
    int ptr = 4;
    auto id = [&](int b, int x) {
        pair<int, int> p(b, x);
        return Id.count(p) ? Id[p] : Id[p] = ptr++;
    };
    int N = (int)(size(cntrow) + size(cntcol)) + 4;
    Dinic<int> dinic(N);
    vector<int> edges;
    for (auto [x, y] : pts) {
        edges.push_back(dinic.add_edge(id(0, x), id(1, y), 1));
    }
    vector<int> d(N);
    for (auto [x, deg] : cntrow) {
        int u = id(0, x);
        dinic.add_edge(src, u, deg % 2);
        d[u] -= deg / 2;
        d[src] += deg / 2;
    }
    for (auto [y, deg] : cntcol) {
        int u = id(1, y);
        dinic.add_edge(u, snk, deg % 2);
        d[u] += deg / 2;
        d[snk] -= deg / 2;
    }
    dinic.add_edge(snk, src, n);
    int sum = 0;
    for (int u = 0; u < N; ++u) {
        if (d[u] < 0) {
            dinic.add_edge(supersrc, u, -d[u]);
            sum += -d[u];
        }
        else if (d[u] > 0) dinic.add_edge(u, supersnk, d[u]);
    }
    int flow = dinic.flow(supersrc, supersnk);
    cerr << "flow == " << flow << endl;
    cerr << "sum == " << sum << endl;
    assert(flow == sum);
    for (int i = 0; i < n; ++i) {
        cout << "rb"[dinic.edges[edges[i]].flow];
    }
    cout << endl;
    exit(0);
}