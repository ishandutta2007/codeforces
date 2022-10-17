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
    vector<tuple<int,int,int>> mincut(int s, int t) {
        vector<tuple<int,int,int>> ret;
        maxflow(s, t);
        queue<int> q;
        vector<int> vis(n);
        q.push(s); vis[s] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = es[i].nxt) {
                if(es[i].f < es[i].c && !vis[es[i].v]) {
                    vis[es[i].v] = 1;
                    q.push(es[i].v);
                }
            }
        }
        for(int u = 0; u < n; ++u) {
            if(!vis[u]) continue;
            for(int i = head[u]; ~i; i = es[i].nxt) {
                if(!vis[es[i].v]) {
                    ret.push_back({u, es[i].v, es[i].c});
                }
            }
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n), rg(n);
    dinic<int> d(2 * n + 2);
    int S = 2 * n, T = 2 * n + 1;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        rg[v].push_back(u);
        d.adde(u, v + n, 1e9);
    }
    for(int i = 0; i < n; ++i) {
        d.adde(S, i, 1);
        d.adde(i + n, T, 1);
    }
    vector<int> markl(n), markr(n);
    auto cut = d.mincut(S, T);
    for(auto [u, v, w] : cut) {
        if(u == S) {
            markl[v] = 1;
        }
        if(v == T) {
            markr[u - n] = 1;
        }
    }
    vector<int> mc;
    for(int i = 0; i < n; ++i) {
        if(markl[i]) mc.push_back(i + 1);
        if(markr[i]) mc.push_back(-(i + 1));
    }
    for(int i = 0; i < n; ++i) {
        for(int v : g[i]) {
            assert(markl[i] || markr[v]);
        }
    }
    int p = n - mc.size();
    if(p > k) {
        cout << k << '\n';
        for(int i = 0; i < k; ++i) cout << 0 << " ";
        cout << '\n';
        return 0;
    }
    vector<vector<ll>> dp(k + 1, vector<ll>(mc.size() + 1, -1e18));
    dp[0][0] = 0;
    vector<ll> xx(k + 1), yy(k + 1);
    for(int i = 1; i <= k; ++i) {
        ll x, y;
        cin >> x >> y;
        xx[i] = x, yy[i] = y;
        for(int j = max(0, i - p); j <= mc.size(); ++j) {
            for(int r = j; r <= mc.size(); ++r) {
                dp[i][r] = max(dp[i][r], dp[i - 1][j] + max(0ll, x - (r - j) * y));
            }
        }
    }
    vector<int> gap;
    int cur = k - p + 1;
    for(int i = k - 1; i >= 0; --i) {
        int lst = -1;
        for(int j = max(0, i - p + 1); j <= cur; ++j) {
            if(dp[i + 1][cur] == dp[i][j] + max(0ll, xx[i + 1] - (cur - j) * yy[i + 1])) {
                lst = j;
                break;
            }
        }
        gap.push_back(cur - lst);
        cur = lst;
    }
    reverse(gap.begin(), gap.end());
    cout << k + k - p + 1 << '\n';
    for(int i : gap) {
        while(i--) {
            cout << mc.back() << " ";
            mc.pop_back();
        }
        cout << 0 << " ";
    }
    cout << '\n';
}