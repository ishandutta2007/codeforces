#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5, inf = 1e9;
int st[maxn], ed[maxn], c[maxn];

struct mcmf {
    struct edge {
        int to, cap, cost, rev, fr, flow;
        edge(int a, int b, int c, int d, int e): to(a), cap(b), cost(c), rev(d), fr(e), flow(0) {}
    };
    vector<edge> graf[maxn]; 
    int p[maxn], d[maxn], id[maxn];
    int n, s, t;
    bool inq[maxn];
    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        for (int i = 0; i < n; ++i) graf[i].clear();
    }
    void add_edge(int a, int b, int c, int d, int e) {
        graf[a].push_back(edge(b, c, d, graf[b].size(), e));
        graf[b].push_back(edge(a, 0, -d, graf[a].size() - 1, e));
    }
    pair<int, int> spfa() {
        fill(p, p + n, -1); fill(d, d + n, inf); fill(id, id + n, -1);
        d[s] = 0; p[s] = s;
        queue<int> q; q.push(s); inq[s] = true;
        while (q.size()) {
            int now = q.front(); q.pop();
            inq[now] = false;
            for (int i = 0; i < graf[now].size(); ++i) {
                edge e = graf[now][i];
                if (e.cap > 0 && d[e.to] > d[now] + e.cost) {
                    d[e.to] = d[now] + e.cost;
                    p[e.to] = now;
                    id[e.to] = i;
                    if (!inq[e.to]) inq[e.to] = true, q.push(e.to);
                }
            }
        }
        if (d[t] == inf) return make_pair(-1, -1);
        int dlt = inf;
        for (int i = t; i != s; i = p[i]) dlt = min(dlt, graf[p[i]][id[i]].cap);
        for (int i = t; i != s; i = p[i]) {
            edge &e = graf[p[i]][id[i]];
            e.cap -= dlt; e.flow += dlt;
            graf[e.to][e.rev].cap += dlt;
            graf[e.to][e.rev].flow -= dlt;
        }
        return make_pair(dlt, d[t]);
    }
    pair<int, int> operator()() {
        int mxf = 0, mnc = 0;
        while (true) {
            int f, c; tie(f, c) = spfa();
            if (f == -1) break;
            mxf += f; mnc += f * c;
        }
        return make_pair(mxf, mnc);
    }
} flow;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d %d %d", st + i, ed + i, c + i), ed[i] += st[i];
    vector<int> ds;
    for (int i = 0; i < n; ++i) ds.push_back(st[i]), ds.push_back(ed[i]);
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    int s = 0, t = ds.size();
    flow.init(ds.size() + 1, s, t);
    for (int i = 0; i < ds.size(); ++i) flow.add_edge(i, i + 1, k, 0, -1);
    for (int i = 0; i < n; ++i) {
        int a = lower_bound(ds.begin(), ds.end(), st[i]) - ds.begin() + 1;
        int b = lower_bound(ds.begin(), ds.end(), ed[i]) - ds.begin() + 1;
        flow.add_edge(a, b, 1, -c[i], i);
    }
    int mxf, mnc; tie(mxf, mnc) = flow();
    for (int i = 0; i < n; ++i) {
        int a = lower_bound(ds.begin(), ds.end(), st[i]) - ds.begin() + 1;
        int b = lower_bound(ds.begin(), ds.end(), ed[i]) - ds.begin() + 1;
        int ans = -1;
        for (int j = 0; j < flow.graf[a].size(); ++j) {
            if (flow.graf[a][j].to == b && flow.graf[a][j].fr == i) {
                if (flow.graf[a][j].flow == 0) ans = 0;
                else ans = 1;
            }
        }
        assert(ans != -1);
        printf("%d ", ans);
    }
    puts("");
    return 0;
}