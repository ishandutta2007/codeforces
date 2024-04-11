#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<int>> g(63);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 63; j++) {
            if (a[i] & (1LL << j)) {
                g[j].emplace_back(i);
            }
        }
    }
    bool ng = true;
    for (int i = 0; i < 63; i++) {
        if (g[i].size() > 2) {
            cout << 3 << endl;
            return 0;
        } else if (g[i].size() == 2) {
            ng = false;
        }
    }
    if (ng) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> v;
    for (int i = 0; i < 63; i++) {
        v.insert(v.end(), g[i].begin(), g[i].end());
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    g.clear();
    g.resize(m);
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (a[v[i]] & a[v[j]]) {
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }
    int ans = m + 1;
    for (int i = 0; i < m; i++) {
        vector<int> deg(m, -1), par(m, -1);
        deg[i] = 0;
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int to : g[u]) {
                if (to == par[u]) {
                    continue;
                }
                if (deg[to] == -1) {
                    par[to] = u;
                    deg[to] = deg[u] + 1;
                    que.push(to);
                } else {
                    ans = min(ans, deg[to] + deg[u] + 1);
                }
            }
        }
    }
    cout << (ans <= m ? ans : -1) << endl;
    return 0;
}