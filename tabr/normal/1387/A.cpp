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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges(m);
    vector<ll> c(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y >> c[i];
        x--, y--;
        g[x].emplace_back(i);
        g[y].emplace_back(i);
        edges[i] = {x, y};
    }
    vector<ll> a(n);
    vector<ll> b(n);
    vector<double> res(n);
    for (int l = 0; l < n; l++) {
        if (a[l]) {
            continue;
        }
        vector<int> was;
        function<void(int)> dfs = [&](int v) {
            was.emplace_back(v);
            for (int id : g[v]) {
                int to = v ^ edges[id].first ^ edges[id].second;
                if (a[to]) {
                    continue;
                }
                a[to] = -a[v];
                b[to] = c[id] - b[v];
                dfs(to);
            }
        };
        a[l] = 1;
        dfs(l);
        int x = 0, y = 0;
        vector<int> e;
        for (int i : was) {
            for (int id : g[i]) {
                if (i == edges[id].first) {
                    e.emplace_back(id);
                }
            }
        }
        for (int i : e) {
            if (a[edges[i].first] == a[edges[i].second]) {
                int z = c[i] - b[edges[i].first] - b[edges[i].second];
                z *= a[edges[i].first];
                if (x != 0 && z != y) {
                    cout << "NO" << '\n';
                    return 0;
                }
                y = z;
                x = 2;
            } else {
                if (c[i] != b[edges[i].first] + b[edges[i].second]) {
                    cout << "NO" << '\n';
                    return 0;
                }
            }
        }
        if (x == 0 && y == 0) {
            int k = was.size();
            vector<ll> t;
            for (int i : was) {
                t.emplace_back(a[i] * b[i]);
            }
            sort(t.begin(), t.end());
            vector<ll> s = t;
            for (int i = 1; i < k; i++) {
                s[i] += s[i - 1];
            }
            ll sum = 9e18;
            ll ans = 0;
            for (int i = 0; i < k; i++) {
                ll z = t[i] * (i + 1) - s[i];
                if (i != k - 1) {
                    z += s[k - 1] - s[i] - t[i] * (k - 1 - i);
                }
                if (sum > z) {
                    sum = z;
                    ans = t[i];
                }
            }
            for (int i : was) {
                res[i] = -ans * a[i] + b[i];
            }
        } else {
            double t = 0.5 * y;
            for (int i : was) {
                res[i] = t * a[i] + b[i];
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << "YES" << '\n';
    for (auto i : res) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}