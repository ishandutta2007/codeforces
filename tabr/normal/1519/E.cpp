#include <bits/stdc++.h>
using namespace std;
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
    vector<pair<long long, long long>> x(n), y(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            long long s, t;
            cin >> s >> t;
            long long g = gcd(s, t);
            s /= g;
            t /= g;
            if (j == 0) {
                x[i] = {s, t};
            } else {
                y[i] = {s, t};
            }
        }
    }
    vector<pair<long long, long long>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = {y[i].first * x[i].second, y[i].second * (x[i].first + x[i].second)};
        b[i] = {(y[i].first + y[i].second) * x[i].second, y[i].second * x[i].first};
        long long g = gcd(a[i].first, a[i].second);
        a[i].first /= g;
        a[i].second /= g;
        g = gcd(b[i].first, b[i].second);
        b[i].first /= g;
        b[i].second /= g;
    }
    vector<int> w(n);
    vector<pair<long long, long long>> c = a;
    c.insert(c.end(), b.begin(), b.end());
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    int m = (int)c.size();
    vector<vector<int>> g(m);
    for (int i = 0; i < n; i++) {
        int u = (int)(lower_bound(c.begin(), c.end(), a[i]) - c.begin());
        int v = (int)(lower_bound(c.begin(), c.end(), b[i]) - c.begin());
        g[u].emplace_back(i);
        g[v].emplace_back(i);
        w[i] = u ^ v;
    }
    swap(n, m);
    vector<pair<int, int>> ans;
    vector<int> was(n);
    vector<int> used(m);
    function<void(int, int)> dfs = [&](int v, int pe) {
        was[v] = 1;
        vector<int> e;
        for (int id : g[v]) {
            if (id == pe) {
                continue;
            }
            int to = w[id] ^ v;
            if (was[to]) {
                if (!used[id]) {
                    e.emplace_back(id);
                }
                used[id] = 1;
                continue;
            }
            dfs(to, id);
            if (!used[id]) {
                e.emplace_back(id);
                used[id] = 1;
            }
        }
        if ((int)e.size() % 2 == 1 && pe != -1) {
            e.emplace_back(pe);
            used[pe] = 1;
        }
        for (int i = 0; i + 1 < (int)e.size(); i += 2) {
            ans.emplace_back(e[i] + 1, e[i + 1] + 1);
        }
    };
    for (int i = 0; i < n; i++) {
        if (was[i]) {
            continue;
        }
        dfs(i, -1);
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}