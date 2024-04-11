#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10, inf = 1e9 + 1;

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

int b[maxn], a[maxn], c[maxn], pos[maxn], alpha[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string st; cin >> st;
    for (int i = 1; i <= n; ++i) {
        a[i] = st[i - 1] - 'a' + 1;
        ++c[a[i]];
    }
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int s = 0, t = maxn - 1;
    MCMF flow(maxn, s, t);
    int ptr = 0;
    for (int i = 1; i <= 26; ++i) {
        alpha[i] = ++ptr;
        flow.add_edge(s, alpha[i], c[i], 0);
    }
    for (int i = 1; i <= n / 2; ++i) {
        pos[i] = ++ptr;
        flow.add_edge(pos[i], t, 2, 0);
    }
    for (int i = 1; i <= 26; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
            int to = n - j + 1;
            if (a[j] == i && a[to] == i) flow.add_edge(alpha[i], pos[j], 1, -max(b[j], b[to])); 
            else if (a[j] == i) flow.add_edge(alpha[i], pos[j], 1, -b[j]);
            else if (a[to] == i) flow.add_edge(alpha[i], pos[j], 1, -b[to]);
            else flow.add_edge(alpha[i], pos[j], 1, 0);
        } 
    }
    cout << -flow.maxflow().second << endl;
    return 0;
}