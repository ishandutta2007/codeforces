#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 100 + 10, inf = 1e9;
const double eps = 1e-6;
int n, m, x;

struct edge { int a, b, c; };
vector<edge> ed;

struct Dinic {
    int n, s, t;
    vector<int> level;
    struct Edge {
        int to, rev, cap;
        Edge() {}
        Edge(int a, int b, int c): to(a), cap(b), rev(c) {}
    };
    vector<Edge> G[maxn];
    bool bfs() {
        level.assign(n, -1);
        level[s] = 0; 
        queue<int> que; que.push(s);
        while (que.size()) {
            int tmp = que.front(); que.pop();
            for (auto e : G[tmp]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[tmp] + 1;
                    que.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    int flow(int now, int low) {
        if (now == t) return low;
        int ret = 0;
        for (auto &e : G[now]) {
            if (e.cap > 0 && level[e.to] == level[now] + 1) {
                int tmp = flow(e.to, min(e.cap, low - ret));
                e.cap -= tmp; G[e.to][e.rev].cap += tmp;
                ret += tmp;
            }
        }
        if (ret == 0) level[now] = -1;
        return ret;
    }
    Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
        fill(G, G + maxn, vector<Edge>());
    }
    void add_edge(int a, int b, int c) {
        G[a].push_back(Edge(b, c, G[b].size()));
        G[b].push_back(Edge(a, 0, G[a].size() - 1));
    }
    int maxflow() {
        int ret = 0;
        while (bfs()) ret += flow(s, inf);
        return ret;
    }
};

bool check(double cap) {
    cap /= (double)x;
    int s = 0, t = n + 1;
    Dinic flow(n + 2, s, t);
    for (int i = 0; i < m; ++i) {
        int cnt = (int)((double)ed[i].c / cap);
        flow.add_edge(ed[i].a, ed[i].b, cnt);
    }
    flow.add_edge(s, 1, x);
    flow.add_edge(n, t, inf);
    return flow.maxflow() == x;
}

double bs(double l, double r) {
    if (r - l < eps) return l;
    double m = (l + r) / 2.0;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        ed.push_back({ a, b, c });
    }
    cout << fixed << setprecision(20) << bs(0, 1e9) << endl;
    return 0;
}