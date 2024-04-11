#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<int>> g(n);
    vector<int> x(n - 1), y(n - 1), z(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        x[i] = u;
        y[i] = v;
        z[i] = w;
        g[u].emplace_back(i);
        g[v].emplace_back(i);
    }
    vector<long long> depth(n), diam(n);
    function<void(int, int)> Dfs = [&](int v, int p) {
        vector<long long> c;
        for (int id : g[v]) {
            if (id == p) {
                continue;
            }
            int to = v ^ x[id] ^ y[id];
            Dfs(to, id);
            depth[v] = max(depth[v], depth[to] + z[id]);
            diam[v] = max(diam[v], diam[to]);
            c.emplace_back(depth[to] + z[id]);
        }
        diam[v] = max(diam[v], depth[v]);
        sort(c.rbegin(), c.rend());
        if (c.size() > 1) {
            diam[v] = max(diam[v], c[0] + c[1]);
        }
    };
    Dfs(0, -1);
    long long ans = (long long) 9e18;
    long long sum = 2LL * accumulate(z.begin(), z.end(), 0LL);
    function<void(int, int)> Reroot = [&](int v, int p) {
        vector<int> idx;
        vector<long long> d0, d1;
        for (int id : g[v]) {
            int to = v ^ x[id] ^ y[id];
            idx.emplace_back(id);
            d0.emplace_back(depth[to] + z[id]);
            d1.emplace_back(diam[to]);
        }
        int sz = (int) idx.size();
        vector<long long> pref0 = d0, pref1 = d1, suf0 = d0, suf1 = d1;
        for (int i = 1; i < sz; i++) {
            pref0[i] = max(pref0[i], pref0[i - 1]);
            pref1[i] = max(pref1[i], pref1[i - 1]);
        }
        for (int i = sz - 2; i >= 0; i--) {
            suf0[i] = max(suf0[i], suf0[i + 1]);
            suf1[i] = max(suf1[i], suf1[i + 1]);
        }
        vector<long long> c(2);
        c[0] = d0[0];
        for (int i = 1; i < sz; i++) {
            c.emplace_back(d0[i]);
            sort(c.rbegin(), c.rend());
            c.pop_back();
            pref1[i] = max(pref1[i], c[0] + c[1]);
        }
        c[0] = d0[sz - 1];
        c[1] = 0;
        for (int i = sz - 2; i >= 0; i--) {
            c.emplace_back(d0[i]);
            sort(c.rbegin(), c.rend());
            c.pop_back();
            suf1[i] = max(suf1[i], c[0] + c[1]);
        }
        for (int i = 0; i < sz; i++) {
            int id = idx[i];
            if (id == p) {
                continue;
            }
            int to = v ^ x[id] ^ y[id];
            long long depth_v = depth[v];
            long long depth_to = depth[to];
            long long diam_v = diam[v];
            long long diam_to = diam[to];
            depth[v] = 0;
            if (i - 1 >= 0) {
                depth[v] = max(depth[v], pref0[i - 1]);
            }
            if (i + 1 < sz) {
                depth[v] = max(depth[v], suf0[i + 1]);
            }
            diam[v] = depth[v];
            if (i - 1 >= 0) {
                diam[v] = max(diam[v], pref1[i - 1]);
            }
            if (i + 1 < sz) {
                diam[v] = max(diam[v], suf1[i + 1]);
            }
            if (i - 1 >= 0 && i + 1 < sz) {
                diam[v] = max(diam[v], pref0[i - 1] + suf0[i + 1]);
            }
            diam[to] = diam_v;
            depth[to] = max(depth[to], depth[v] + z[id]);
            ans = min(ans, sum - z[id] * 2 - diam[v] - diam_to);
            Reroot(to, id);
            depth[v] = depth_v;
            depth[to] = depth_to;
            diam[v] = diam_v;
            diam[to] = diam_to;
        }
        sort(d0.rbegin(), d0.rend());
        if (sz >= 4) {
            ans = min(ans, sum - d0[0] - d0[1] - d0[2] - d0[3]);
        }
    };
    Reroot(0, -1);
    cout << ans << "\n";
}