#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

vector<bool> pn;
inline void sieve(int n) {
    pn.resize(n + 1, true);
    pn[0] = pn[1] = false;
    for (int i = 2; i <= n; i++) {
        if (pn[i]) {
            for (int j = 2; i * j <= n; j++) {
                pn[i * j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(1000000);
    map<int, int> mp;
    int id = 0;
    pn[1] = true;
    for (int i = 0; i < 1000000; i++) {
        if (pn[i]) {
            mp[i] = id;
            id++;
        }
    }
    ll n;
    cin >> n;
    vector<vector<int>> g(id);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        ll u = 1, v = 1;
        for (ll t = 2; t * t <= a; t++) {
            if (a % t == 0) {
                while (a % (t * t) == 0) {
                    a /= t * t;
                }
                if (a % t == 0) {
                    v = t;
                    a /= t;
                    if (u < v) swap(u, v);
                }
            }
        }
        if (a != 1) {
            v = a;
        }
        g[mp[u]].emplace_back(mp[v]);
        g[mp[v]].emplace_back(mp[u]);
    }
    int ans = 1e7;
    function<void(int)> bfs = [&](int p) {
        vector<int> deg(id, -1), par(id, -1);
        queue<int> que;
        que.push(p);
        deg[p] = 0;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            bool same = false;
            for (int to : g[v]) {
                if (to == par[v]) {
                    if (!same) {
                        same = true;
                        continue;
                    }
                }
                if (deg[to] == -1) {
                    par[to] = v;
                    deg[to] = deg[v] + 1;
                    que.push(to);
                } else {
                    ans = min(ans, deg[to] + deg[v] + 1);
                }
            }
        }
    };
    for (int i = 0; i < 500; i++) {
        bfs(i);
    }
    cout << (ans != 1e7 ? ans : -1) << endl;
    return 0;
}