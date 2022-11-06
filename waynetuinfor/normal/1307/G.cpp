#include <bits/stdc++.h>
using namespace std;

constexpr int kInf = 1'000'000'000;

struct Edge {
    int to, rev, cap, w;
    Edge(int a, int b, int c, int d) : to(a), cap(b), w(c), rev(d) {}
};

vector<tuple<int, int, int>> Flow(vector<vector<Edge>> g) {
    int n = g.size(), flow = 0, sum = 0;
    vector<tuple<int, int, int>> res;
    while (true) {
        vector<int> dist(n, kInf), pv(n, -1), qu(1, 0), inq(n, 0), ed(n, -1);
        dist[0] = 0;
        for (int i = 0; i < qu.size(); ++i) {
            int x = qu[i];
            inq[x] = 0;
            for (int i = 0; i < g[x].size(); ++i) {
                const Edge &e = g[x][i];
                if (e.cap == 0) continue;
                if (dist[e.to] > dist[x] + e.w) {
                    dist[e.to] = dist[x] + e.w;
                    pv[e.to] = x;
                    ed[e.to] = i;
                    if (!inq[e.to]) {
                        inq[e.to] = 1;
                        qu.push_back(e.to);
                    }
                }
            }
        }
        if (dist[n - 1] == kInf) break;
        int f = kInf;
        for (int x = n - 1; x != 0; x = pv[x]) f = min(f, g[pv[x]][ed[x]].cap);
        for (int x = n - 1; x != 0; x = pv[x]) {
            g[pv[x]][ed[x]].cap -= f;
            g[x][g[pv[x]][ed[x]].rev].cap += f;
        }
        res.emplace_back(flow, sum, dist[n - 1]);
        sum += f * dist[n - 1];
        flow += f;
    }
    res.emplace_back(flow, sum, kInf);
    return res;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<Edge>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        g[u].emplace_back(v, 1, +w, g[v].size() - 0);
        g[v].emplace_back(u, 0, -w, g[u].size() - 1);
    }
    auto gr = Flow(g);
    vector<long long> cut;
    for (auto &s : gr) {
        long long v = 1LL * get<2>(s) * get<0>(s) - get<1>(s);
        cut.push_back(v);
    }
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        auto it = upper_bound(cut.begin(), cut.end(), x);
        assert(it != cut.begin());
        int p = it - cut.begin() - 1;
        double ans = kInf;
        if (get<0>(gr[p]) != 0) ans = min(ans, 1.0 * (x + get<1>(gr[p])) / get<0>(gr[p]));
        if (p + 1 < cut.size()) ans = min(ans, 1.0 * (x + get<1>(gr[p + 1])) / get<0>(gr[p + 1]));
        printf("%.20lf\n", ans);
    }
}