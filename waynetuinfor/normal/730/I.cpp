#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10, inf = 1e9 + 1;
int a[maxn], b[maxn];

struct MCMF {
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
    MCMF(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
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
    int n, p, s; cin >> n >> p >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int sink = 0, target = n + 3;
    MCMF flow(n + 4, sink, target);
    for (int i = 1; i <= n; ++i) flow.add_edge(sink, i, 1, 0);
    flow.add_edge(n + 1, target, p, 0); flow.add_edge(n + 2, target, s, 0);
    for (int i = 1; i <= n; ++i) {
        flow.add_edge(i, n + 1, 1, -a[i]);
        flow.add_edge(i, n + 2, 1, -b[i]);
    }
    int mxf, mnc;
    tie(mxf, mnc) = flow.maxflow();
    cout << -mnc << endl;
    vector<int> va, vb;
    for (int i = 1; i <= n; ++i) {
        for (auto j : flow.G[i]) {
            if (j.to == 0 || j.cap || j.w > 0) continue;
            if (j.to == n + 1) va.push_back(i);
            else vb.push_back(i);
        }
    }
    assert((int)va.size() == p && (int)vb.size() == s);
    for (int i : va) cout << i << ' '; cout << endl;
    for (int i : vb) cout << i << ' '; cout << endl;
    return 0;
}