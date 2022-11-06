#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
int a[maxn], x[maxn], y[maxn], w[maxn];

struct dinic {
    static const long long inf = 1e18;
    struct edge {
        int dest, rev; long long cap;
        edge(int d, long long c, int r): dest(d), cap(c), rev(r) {}
    };
    vector<edge> g[maxn];
    int qu[maxn], ql, qr;
    int lev[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i)
            g[i].clear();
    }
    void add_edge(int a, int b, long long c) {
        g[a].emplace_back(b, c, g[b].size() - 0);
        g[b].emplace_back(a, 0, g[a].size() - 1);
    }
    bool bfs(int s, int t) {
        memset(lev, -1, sizeof(lev));
        lev[s] = 0;
        ql = qr = 0;
        qu[qr++] = s;
        while (ql < qr) {
            int x = qu[ql++];
            for (edge &e : g[x]) if (lev[e.dest] == -1 && e.cap > 0) {
                lev[e.dest] = lev[x] + 1;
                qu[qr++] = e.dest;
            }
        }
        return lev[t] != -1;
    }
    long long dfs(int x, int t, long long flow) {
        if (x == t) return flow;
        long long res = 0;
        for (edge &e : g[x]) if (e.cap > 0 && lev[e.dest] == lev[x] + 1) {
            long long f = dfs(e.dest, t, min(e.cap, flow - res));
            res += f;
            e.cap -= f;
            g[e.dest][e.rev].cap += f;
        }
        if (res == 0) lev[x] = -1;
        return res;
    }
    long long operator()(int s, int t) {
        long long flow = 0;
        for (; bfs(s, t); flow += dfs(s, t, inf));
        return flow;
    }
};

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &w[i]);
        --x[i], --y[i];
        sum += w[i];
    }
    dinic flow;
    int s = n + m, t = n + m + 1;
    for (int i = 0; i < m; ++i) flow.add_edge(s, i, w[i]);
    for (int i = 0; i < m; ++i) flow.add_edge(i, x[i] + m, 1e15);
    for (int i = 0; i < m; ++i) flow.add_edge(i, y[i] + m, 1e15);
    for (int i = 0; i < n; ++i) flow.add_edge(i + m, t, a[i]);
    printf("%lld\n", sum - flow(s, t));
}