#include<bits/stdc++.h>
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
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        dinic<int> g(2 * n + 2);
        int S = 2 * n, T = 2 * n + 1;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            while(x) {
                if(x <= n) g.adde(i, n + x - 1, 1);
                x /= 2;
            }
        }
        for(int i = 0; i < n; ++i) g.adde(S, i, 1);
        for(int i = 0; i < n; ++i) g.adde(n + i, T, 1);
        cout << (g.maxflow(S, T) == n ? "YES" : "NO") << '\n';
    }
}