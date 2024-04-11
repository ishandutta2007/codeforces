#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxsq = 32000, inf = 1e6 + 1;
int a[maxn];
vector<int> pr;

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

void sieve() {
    bitset<maxsq> v;
    for (int i = 2; i < maxsq; ++i) {
        if (!v[i]) pr.push_back(i);
        for (int j = 0; i * pr[j] < maxsq; ++j) {
            v[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
}

int x[maxn], y[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int n, m; cin >> n >> m;
    vector<int> used;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int tmp = a[i];
        size_t ptr = 0;
        while (tmp > 1 && ptr < pr.size()) {
            int c = 0;
            while (tmp % pr[ptr] == 0) tmp /= pr[ptr], ++c;
            if (c) used.push_back(pr[ptr]);
            ++ptr;
        }
        if (tmp > 1) used.push_back(tmp);
    }
    sort(used.begin(), used.end()); used.resize(unique(used.begin(), used.end()) - used.begin());
    for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];
    int ans = 0;
    for (int p : used) {
        int s = 0, t = n + 1;
        Dinic flow(n + 2, s, t);
        for (int i = 1; i <= n; ++i) {
            int c = 0;
            while (a[i] % p == 0) a[i] /= p, ++c;
            if (!c) continue;
            if (i & 1) flow.add_edge(s, i, c);
            else flow.add_edge(i, t, c);
        }
        for (int i = 0; i < m; ++i) {
            if (x[i] & 1) flow.add_edge(x[i], y[i], inf);
            else flow.add_edge(y[i], x[i], inf);
        }
        ans += flow.maxflow();
    }
    cout << ans << endl;
    return 0;
}