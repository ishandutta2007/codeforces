#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e9 + 1;
int ub[maxn], lb[maxn];

struct MincostMaxflow {
    struct Edge {
        int to, rev, cap, w;
        Edge() {}
        Edge(int a, int b, int c, int d): to(a), cap(b), w(c), rev(d) {}
    };
    int n, s, t;
    vector<int> p, id, d;
    bitset<maxn> inque;
    vector<Edge> G[maxn];
    pair<int, int> spfa() {
        p.assign(n, -1);
        d.assign(n, inf);
        id.assign(n, -1);
        d[s] = 0; p[s] = s;
        queue<int> que; que.push(s); inque[s] = true;
        while (que.size()) {
            int tmp = que.front(); que.pop();
            inque[tmp] = false;
            int i = 0;
            for (auto e : G[tmp]) {
                if (e.cap > 0 && d[e.to] > d[tmp] + e.w) {
                    d[e.to] = d[tmp] + e.w;
                    p[e.to] = tmp;
                    id[e.to] = i;
                    if (!inque[e.to]) que.push(e.to), inque[e.to] = true;
                }
                ++i;
            }
        }
        if (d[t] == inf) return make_pair(-1, -1);
        int a = inf;
        for (int i = t; i != s; i = p[i]) {
            a = min(a, G[p[i]][id[i]].cap);
        }
        for (int i = t; i != s; i = p[i]) {
            Edge &e = G[p[i]][id[i]];
            e.cap -= a; G[e.to][e.rev].cap += a;
        }
        return make_pair(a, d[t]);
    }
    MincostMaxflow(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
        fill(G, G + maxn, vector<Edge>());
    }
    void add_edge(int a, int b, int cap, int w) {
        G[a].push_back(Edge(b, cap, w, (int)G[b].size()));
        G[b].push_back(Edge(a, 0, -w, (int)G[a].size() - 1));
    }
    pair<int, int> maxflow() {
        int mxf = 0, mnc = 0;
        while (true) {
            pair<int, int> res = spfa();
            if (res.first == -1) break;
            mxf += res.first; mnc += res.first * res.second;
        }
        return make_pair(mxf, mnc);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    fill(lb, lb + maxn, 1); fill(ub, ub + maxn, n);
    while (q--) {
        int t, l, r, v; cin >> t >> l >> r >> v;
        for (int i = l; i <= r; ++i) {
            if (t == 1) lb[i] = max(lb[i], v);
            else ub[i] = min(ub[i], v);
        }
    }
    MincostMaxflow flow(2 * n + 2, 0, 2 * n + 1);
    int s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; ++i) flow.add_edge(s, i, 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = lb[i]; j <= ub[i]; ++j) flow.add_edge(i, j + n, 1, 0);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) flow.add_edge(i + n, t, 1, 2 * j - 1);
    }
    int mf, mc;
    tie(mf, mc) = flow.maxflow();
    if (mf != n) cout << "-1" << endl;
    else cout << mc << endl;
    return 0;
}