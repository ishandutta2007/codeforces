#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<ll,int> pii;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<vector<pair<int,int>>> g(n << 4);
    vector<ll> dis(n << 4, 1e18);
    vector<int> id(n);
    int tot = n << 2;
    function<void(int,int,int)> build = [&](int l, int r, int rt) {
        if(l == r) {
            id[l] = rt;
            g[rt].push_back({rt + tot, 0});
            g[rt + tot].push_back({rt, 0});
            return;
        }
        g[rt].push_back({rt << 1, 0});
        g[rt].push_back({rt << 1 | 1, 0});
        g[tot + (rt << 1)].push_back({tot + rt, 0});
        g[tot + (rt << 1 | 1)].push_back({tot + rt, 0});
        int m = (l + r) / 2;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    };
    build(0, n - 1, 1);
    vector<int> a;
    function<void(int,int,int,int,int)> get = [&](int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            a.push_back(rt);
            return;
        }
        int m = (l + r) / 2;
        if(L <= m) get(L, R, l, m, rt << 1);
        if(m < R) get(L, R, m + 1, r, rt << 1 | 1);
    };
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int v, u, w;
            cin >> v >> u >> w;
            --v, --u;
            g[id[v] + tot].push_back({id[u], w});
        } else if(op == 2) {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            --v, --l, --r;
            a.clear();
            get(l, r, 0, n - 1, 1);
            for(int i : a) {
                g[id[v] + tot].push_back({i, w});
            }
        } else {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            --v, --l, --r;
            a.clear();
            get(l, r, 0, n - 1, 1);
            for(int i : a) {
                g[i + tot].push_back({id[v], w});
            }
        }
    }
    q.push({0, id[s]});
    dis[id[s]] = 0;
    while(!q.empty()) {
        auto [w, u] = q.top(); q.pop();
        if(w != dis[u]) continue;
        for(auto [v, w2] : g[u]) {
            if(dis[v] > w + w2) {
                dis[v] = w + w2;
                q.push({dis[v], v});
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(dis[id[i]] == 1e18) {
            cout << -1 << " ";
        } else {
            cout << dis[id[i]] << " ";
        }
    }
    cout << '\n';
}