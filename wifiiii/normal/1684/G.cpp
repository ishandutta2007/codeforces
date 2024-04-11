#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

template<typename T>
struct dinic {
    struct edge {
        int v, nxt;
        T f, c;
    };
    vector<edge> es;
    vector<int> head, cur, d;
    int n, tot;
    const T inf = numeric_limits<T>::max();
    dinic(int n):n(n) {
        cur.resize(n);
        head.resize(n);
        d.resize(n);
        fill(head.begin(), head.end(), -1);
        tot = 0;
    }
    void adde(int u, int v, T w) {
        es.push_back({v, head[u], 0, w}); head[u] = tot++;
        es.push_back({u, head[v], 0, 0}); head[v] = tot++;
    }
    T maxflow(int s, int t) {
        auto bfs = [&]() -> int {
            for(int i = 0; i < n; ++i) d[i] = -1;
            queue<int> q;
            q.push(s);
            d[s] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int i = head[u]; ~i; i = es[i].nxt) {
                    if(d[es[i].v] == -1 && es[i].f < es[i].c) {
                        d[es[i].v] = d[u] + 1;
                        q.push(es[i].v);
                        if(es[i].v == t) return 1;
                    }
                }
            }
            return 0;
        };
        function<T(int,T)> dfs = [&](int u, T f) {
            if(u == t || !f) return f;
            T ret = 0;
            for(int &i = cur[u]; ~i; i = es[i].nxt) {
                if(d[es[i].v] == d[u] + 1 && es[i].c - es[i].f) {
                    T tmp = dfs(es[i].v, min(f, es[i].c - es[i].f));
                    if(!tmp) {
                        d[es[i].v] = 0;
                        continue;
                    }
                    es[i].f += tmp;
                    es[i^1].f -= tmp;
                    f -= tmp;
                    ret += tmp;
                    if(!f) break;
                }
            }
            return ret;
        };
        T ans = 0;
        while(bfs()) {
            for(int i = 0; i < n; ++i) cur[i] = head[i];
            ans += dfs(s, inf);
        }
        return ans;
    }
};

int main() {
    // (3x, 2x) -> x, x <= m / 3

    // a > b -> r  ==>  r = a % b, 2r <= a - 1 <= m - 1 ==> r <= (m - 1) / 2

    // (a, b) -> (kd, b) -> (kd, d) ==> kd & d
    // b = (k+1)d, a = (2k+1)d

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    if(*max_element(a.begin(), a.end()) > (m - 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> b, c;
    for(int i = 0; i < n; ++i) {
        if(a[i] <= m / 3) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    dinic<int> g(n + 2);
    int s = n, t = n + 1;
    for(int i = 0; i < c.size(); ++i) {
        for(int j = 0; j < b.size(); ++j) {
            if(c[i] % b[j] == 0 && 2 * c[i] + b[j] <= m) {
                //     (c[i] + c[i] + b[j], c[i] + b[j])
                // --> (c[i], c[i] + b[j]), r = c[i]
                // --> (c[i], b[j]), r = b[j]
                // --> (   0, b[j]), r = 0
                g.adde(i, j + c.size(), 1);
            }
        }
    }
    for(int i = 0; i < c.size(); ++i) g.adde(s, i, 1);
    for(int i = c.size(); i < n; ++i) g.adde(i, t, 1);
    if(g.maxflow(s, t) < c.size()) {
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<int,int>> ans;
    vector<int> vis(b.size());
    for(int i = 0; i < c.size(); ++i) {
        for(int j = g.head[i]; ~j; j = g.es[j].nxt) {
            if(g.es[j].c == g.es[j].f && c.size() <= g.es[j].v && g.es[j].v < n) {
                int k = g.es[j].v - c.size();
                vis[k] = 1;
                ans.push_back({c[i] + c[i] + b[k], c[i] + b[k]});
            }
        }
    }
    for(int i = 0; i < b.size(); ++i) {
        if(!vis[i]) ans.push_back({3 * b[i], 2 * b[i]});
    }
    cout << ans.size() << '\n';
    for(auto [x, y] : ans) cout << x << " " << y << "\n";
}