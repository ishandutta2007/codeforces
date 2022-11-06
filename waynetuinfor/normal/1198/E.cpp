#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int inf = 1e9 + 100;
vector<int> g[maxn];
int l[maxn], r[maxn], u[maxn], d[maxn];
map<int, int> mx, my;


struct dinic {
    static const int inf = 1e9;
    struct edge {
        int dest, cap, rev;
        edge(int d, int c, int r): dest(d), cap(c), rev(r) {}
    };
    vector<edge> g[maxn];
    int qu[maxn], ql, qr;
    int lev[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i)
            g[i].clear();
    }
    void add_edge(int a, int b, int c) {
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
    int dfs(int x, int t, int flow) {
        if (x == t) return flow;
        int res = 0;
        for (edge &e : g[x]) if (e.cap > 0 && lev[e.dest] == lev[x] + 1) {
            int f = dfs(e.dest, t, min(e.cap, flow - res));
            res += f;
            e.cap -= f;
            g[e.dest][e.rev].cap += f;
        }
        if (res == 0) lev[x] = -1;
        return res;
    }
    int operator()(int s, int t) {
        int flow = 0;
        for (; bfs(s, t); flow += dfs(s, t, inf));
        return flow;
    }
};
int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<int> dx, dy;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &l[i], &u[i], &r[i], &d[i]);
        dx.push_back(l[i]);
        dx.push_back(r[i] + 1);
        dy.push_back(u[i]);
        dy.push_back(d[i] + 1);
    }

    sort(dx.begin(), dx.end());
    dx.resize(unique(dx.begin(), dx.end()) - dx.begin());
    sort(dy.begin(), dy.end());
    dy.resize(unique(dy.begin(), dy.end()) - dy.begin());

    dinic flow;

    for (int i = 0; i < (int)dx.size() - 1; ++i) {
        for (int j = 0; j < (int)dy.size() - 1; ++j) {
            int pl = dx[i], pr = dx[i + 1] - 1;
            int pu = dy[j], pd = dy[j + 1] - 1;
            bool edge = false;
            for (int k = 0; k < m; ++k) {
                if (r[k] < pl || l[k] > pr || d[k] < pu || u[k] > pd) continue;
                edge = true;
            }
            if (edge) {
                flow.add_edge(i, j + 200, 1e9 + 100);
            }
        }
    }
    int s = 1000, t = 1001;
    for (int i = 0; i < (int)dx.size() - 1; ++i) flow.add_edge(s, i, dx[i + 1] - dx[i]);
    for (int i = 0; i < (int)dy.size() - 1; ++i) flow.add_edge(i + 200, t, dy[i + 1] - dy[i]);
    printf("%d\n", flow(s, t));
}