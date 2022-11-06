#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int maxs = 1e5 + 5;
vector<int> gr[maxs], rg[maxs], sg[maxs];
int x[maxs], a[maxs], f[maxs], p[maxs];
int y[maxs], d[maxs], g[maxs];
int w[maxn][maxn], mg[maxn];
int topo[maxs], scc[maxs], uf[maxs];
long long pf[maxs], sum[maxs], ans[maxs];
long long opt[maxs];
bool ok[maxs], used[maxs];
bool sok[maxs];

void build(int n, int s, int b) {
    vector<int> vs(s), vb(b);
    iota(vs.begin(), vs.end(), 0);
    iota(vb.begin(), vb.end(), 0);
    sort(vs.begin(), vs.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    sort(vb.begin(), vb.end(), [&](int i, int j) {
        return d[i] < d[j];
    });

    for (int i = 0; i < n; ++i) mg[i] = -1;

    for (int i = 0, j = 0; i < s; ++i) {
        while (j < b && d[vb[j]] <= a[vs[i]]) {
            mg[y[vb[j]]] = max(mg[y[vb[j]]], g[vb[j]]);
            ++j;
        }
        int res = -1;
        for (int k = 0; k < n; ++k) {
            if (w[x[vs[i]]][k] <= f[vs[i]])
                res = max(res, mg[k]);
        }
        if (res == -1) ok[vs[i]] = false;
        else ok[vs[i]] = true, pf[vs[i]] = res - p[vs[i]];
    }
}

void dfs(int x) {
    static int sz = 0;
    used[x] = true;
    for (int i = 0; i < (int)gr[x].size(); ++i) {
        int u = gr[x][i];
        if (!used[u]) dfs(u);
    }
    topo[sz++] = x;
}

void rdfs(int x, int s) {
    scc[x] = s;
    for (int i = 0; i < (int)rg[x].size(); ++i) {
        int u = rg[x][i];
        if (scc[u] == -1) rdfs(u, s);
    }
}

int find(int x) {
    if (x == uf[x]) return x;
    return uf[x] = find(uf[x]);
}

void merge(int x, int y) {
    uf[find(x)] = find(y);
}

vector<int> walk;

void dfs3(int x) {
    walk.push_back(x);
    used[x] = true;
    for (int i = 0; i < (int)sg[x].size(); ++i) {
        int u = sg[x][i];
        if (used[u]) continue;
        dfs3(u);
    }
}

struct dinic {
    static const int maxn = maxs;
    static const long long inf = 1e18;
    struct edge {
        int dest, rev;
        long long cap;
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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            w[i][j] = i == j ? 0 : 1e8;
    }
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        if (u == v) continue;
        w[u][v] = w[v][u] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
        }
    }
    
    int s, b, k; scanf("%d%d%d", &s, &b, &k);
    for (int i = 0; i < s; ++i) {
        scanf("%d%d%d%d", &x[i], &a[i], &f[i], &p[i]);
        --x[i];
    }
    for (int i = 0; i < b; ++i) {
        scanf("%d%d%d", &y[i], &d[i], &g[i]);
        --y[i];
    }

    build(n, s, b);
    dinic flow;
    long long sum = 0;
    for (int i = 0; i < s; ++i) {
        if (!ok[i]) {
            flow.add_edge(i, s + 1, 2e14);
            continue;
        }
        if (pf[i] >= 0) {
            sum += pf[i];
            flow.add_edge(s, i, pf[i]);
        } else {
            flow.add_edge(i, s + 1, -pf[i]);
        }
    }

    while (k--) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        flow.add_edge(u, v, 2e14);
    }

    printf("%lld\n", sum - flow(s, s + 1));

    /* 
    for (int i = 0; i < s; ++i) {
        if (!used[i]) dfs(i);
    }

    memset(scc, -1, sizeof(scc));
    int sz = 0;
    for (int i = s - 1; i >= 0; --i) {
        if (scc[topo[i]] == -1) {
            rdfs(topo[i], sz);
            ++sz;
        }
    }

    for (int i = 0; i < sz; ++i) {
        sok[i] = true;
        uf[i] = i;
    }

    for (int i = 0; i < s; ++i) {
        sok[scc[i]] &= ok[i]; 
        sum[scc[i]] += pf[i];
        for (int j = 0; j < (int)gr[i].size(); ++j) {
            int u = gr[i][j];
            if (scc[i] != scc[u]) {
                sg[scc[i]].push_back(scc[u]);
                merge(scc[i], scc[u]);
            }
        }
    }

    for (int i = 0; i < sz; ++i) {
        sort(sg[i].begin(), sg[i].end());
        sg[i].resize(unique(sg[i].begin(), sg[i].end()) - sg[i].begin());
    }

    memset(used, false, sizeof(used));
    for (int i = 0; i < sz; ++i) opt[i] = -1e18;
    for (int i = 0; i < sz; ++i) {
        walk.clear();
        dfs3(i);
        bool tok = true;
        long long su = 0;
        for (int j = 0; j < (int)walk.size(); ++j) {
            int u = walk[j];
            tok |= sok[u];
            su += sum[u];
            used[u] = false;
        }
        if (tok) opt[find(i)] = max(opt[find(i)], su);
    }

    long long ans = 0;
    for (int i = 0; i < sz; ++i) {
        if (find(i) == i)
            ans += max(0ll, opt[i]);
    } */

    // printf("%lld\n", ans);
    return 0;
}