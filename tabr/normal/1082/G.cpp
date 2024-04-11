#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct dinic {
    T eps = (T)1e-9;

    struct edge {
        int from;
        int to;
        T c;
        T f;
        edge(int _from, int _to, T _c, T _f) : from(_from), to(_to), c(_c), f(_f) {}
    };

    vector<vector<int>> g;
    vector<edge> edges;
    vector<int> ptr;
    vector<int> d;
    vector<int> q;
    int n;
    int st;
    int fin;
    T flow;

    dinic(int _n, int _st, int _fin) : n(_n), st(_st), fin(_fin) {
        assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
        g.resize(n);
        ptr.resize(n);
        d.resize(n);
        q.resize(n);
        flow = 0;
    }

    void clear_flow() {
        for (const edge &e : edges) {
            e.f = 0;
        }
        flow = 0;
    }

    int add(int from, int to, T forward_cap, T backward_cap = 0) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].emplace_back(id);
        edges.emplace_back(from, to, forward_cap, 0);
        g[to].emplace_back(id + 1);
        edges.emplace_back(to, from, backward_cap, 0);
        return id;
    }

    bool bfs() {
        fill(d.begin(), d.end(), -1);
        q[0] = fin;
        d[fin] = 0;
        int beg = 0, end = 1;
        while (beg < end) {
            int i = q[beg++];
            for (int id : g[i]) {
                edge &e = edges[id];
                edge &back = edges[id ^ 1];
                if (back.c - back.f > eps && d[e.to] == -1) {
                    d[e.to] = d[i] + 1;
                    if (e.to == st) {
                        return true;
                    }
                    q[end++] = e.to;
                }
            }
        }
        return false;
    }

    T dfs(int v, T w) {
        if (v == fin) {
            return w;
        }
        int &j = ptr[v];
        while (j >= 0) {
            int id = g[v][j];
            edge &e = edges[id];
            if (e.c - e.f > eps && d[e.to] == d[v] - 1) {
                T t = dfs(e.to, min(e.c - e.f, w));
                if (t > eps) {
                    edges[id].f += t;
                    edges[id ^ 1].f -= t;
                    return t;
                }
            }
            j--;
        }
        return 0;
    }

    T max_flow() {
        while (bfs()) {
            for (int i = 0; i < n; i++) {
                ptr[i] = (int)g[i].size() - 1;
            }
            T sum = 0;
            while (true) {
                T add = dfs(st, numeric_limits<T>::max());
                if (add <= eps) {
                    break;
                }
                sum += add;
            }
            if (sum <= eps) {
                break;
            }
            flow += sum;
        }
        return flow;
    }

    vector<bool> min_cut() {
        max_flow();
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = (d[i] != -1);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dinic<long long> fg(n + m + 2, n + m, n + m + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fg.add(n + m, i, a);
    }
    long long inf = (long long)1e18;
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        fg.add(x, n + i, inf);
        fg.add(y, n + i, inf);
        fg.add(n + i, n + m + 1, w);
        ans += w;
    }
    cout << ans - fg.max_flow() << '\n';
    return 0;
}