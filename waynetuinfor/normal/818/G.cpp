#include <bits/stdc++.h>
using namespace std;

const int maxv = 1e4 + 5, maxn = 1e5 + 5;
const int inf = 1e9 + 5;

struct mincost {
    struct edge {
        int dest, cap, w, rev;
        edge(int a, int b, int c, int d): dest(a), cap(b), w(c), rev(d) {}
    };
    vector<edge> g[maxn];
    int d[maxn], p[maxn], ed[maxn];
    bool inq[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) g[i].clear();
    }
    void add_edge(int a, int b, int c, int d) {
        g[a].emplace_back(b, c, +d, g[b].size() - 0);
        g[b].emplace_back(a, 0, -d, g[a].size() - 1);
    }
    bool spfa(int s, int t, int &f, int &c) {
        for (int i = 0; i < maxn; ++i) {
            d[i] = inf;
            p[i] = ed[i] = -1;
            inq[i] = false;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size()) {
            int x = q.front(); q.pop();
            inq[x] = false;
            for (int i = 0; i < g[x].size(); ++i) {
                edge &e = g[x][i];
                if (e.cap > 0 && d[e.dest] > d[x] + e.w) {
                    d[e.dest] = d[x] + e.w;
                    p[e.dest] = x;
                    ed[e.dest] = i;
                    if (!inq[e.dest]) q.push(e.dest), inq[e.dest] = true;
                }
            }
        }
        if (d[t] == inf) return false;
        int dlt = inf;
        for (int x = t; x != s; x = p[x]) dlt = min(dlt, g[p[x]][ed[x]].cap);
        for (int x = t; x != s; x = p[x]) {
            edge &e = g[p[x]][ed[x]];
            e.cap -= dlt;
            g[e.dest][e.rev].cap += dlt;
        }
        f += dlt; c += d[t] * dlt;
        return true;
    }
    pair<int, int> operator()(int s, int t) {
        int f = 0, c = 0;
        while (spfa(s, t, f, c));
        return make_pair(f, c);
    }
};

int a[maxn], nxt[maxn];
int z[7];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    mincost flow;
    for (int i = 1; i <= n; ++i) flow.add_edge(i, i + n, 1, -1), flow.add_edge(i, i + n, inf, 0);
    for (int i = n; i >= 1; --i) {
        if (nxt[a[i] + 1]) flow.add_edge(i + n, nxt[a[i] + 1], 1, 0);
        if (nxt[a[i] - 1]) flow.add_edge(i + n, nxt[a[i] - 1], 1, 0);
        if (z[a[i] % 7]) flow.add_edge(i + n, z[a[i] % 7], inf, 0);
        z[a[i] % 7] = i;
        nxt[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) flow.add_edge(0, i, 1, 0);
    for (int i = 1; i <= n; ++i) flow.add_edge(i + n, n + n + 1, 1, 0);
    flow.add_edge(n + n + 2, 0, 4, 0);
    int f = 0, c = 0;
    tie(f, c) = flow(n + n + 2, n + n + 1);
    printf("%d\n", -c);
}