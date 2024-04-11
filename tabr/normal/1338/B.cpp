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
    vector<vector<int>> g(n);
    vector<int> lf;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) {
            lf.emplace_back(i);
        } else {
            root = i;
        }
    }
    vector<int> sz(n), parity(n);
    vector<ll> hi(n);
    ll lo = 1;
    function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        int hix = 0;
        vector<bool> px(2);
        for (int to : g[v]) {
            if (to == p) continue;
            dfs(to, v);
            sz[v] += sz[to];
            px[parity[to]] = true;
            if (sz[to] == 1) {
                hix = 1;
            } else {
                hi[v] += hi[to] + 1;
            }
        }
        hi[v] += hix;
        if (sz[v] == 1) {
            parity[v] = 1;
        } else {
            if (px[0] && px[1]) {
                lo = 3;
            } else if (px[0]) {
                parity[v] = 1;
            } else if (px[1]) {
                parity[v] = 0;
            }
        }
    };
    dfs(root, -1);
    cout << lo << " " << hi[root] << '\n';
    return 0;
}