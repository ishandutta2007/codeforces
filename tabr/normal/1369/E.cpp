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
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<set<int>> g(n);
    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        g[x[i]].emplace(i);
        g[y[i]].emplace(i);
        c[x[i]]++, c[y[i]]++;
    }
    vector<int> ans;
    map<int, int> d;
    for (int i = 0; i < m; i++) {
        if (w[x[i]] >= c[x[i]] || w[y[i]] >= c[y[i]]) {
            ans.emplace_back(i);
            g[x[i]].erase(i);
            g[y[i]].erase(i);
            d[x[i]]++, d[y[i]]++;
        }
    }
    while (!d.empty()) {
        vector<int> t;
        for (auto e : d) {
            t.emplace_back(e.first);
            c[e.first] -= e.second;
        }
        d.clear();
        for (int i : t) {
            if (w[i] >= c[i]) {
                for (int e : g[i]) {
                    ans.emplace_back(e);
                    int j = x[e] ^ y[e] ^ i;
                    d[j]++;
                    g[j].erase(e);
                }
                g[i].clear();
            }
        }
    }
    debug(ans);
    if (ans.size() == m) {
        cout << "ALIVE" << '\n';
        reverse(ans.begin(), ans.end());
        for (int i : ans) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    } else {
        cout << "DEAD" << '\n';
    }
    return 0;
}