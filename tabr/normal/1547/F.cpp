#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> scc(const vector<vector<int>> &g) {
    int n = (int) g.size();
    int cnt = 0;
    vector<vector<int>> rev_g(n);
    vector<int> order;
    vector<int> res(n, -1);
    vector<bool> was(n);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            rev_g[j].emplace_back(i);
        }
    }
    function<void(int)> dfs1 = [&](int v) {
        was[v] = true;
        for (int to : g[v]) {
            if (!was[to]) {
                dfs1(to);
            }
        }
        order.emplace_back(v);
    };
    function<void(int)> dfs2 = [&](int v) {
        for (int to : rev_g[v]) {
            if (res[to] == -1) {
                res[to] = res[v];
                dfs2(to);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            dfs1(i);
        }
    }
    for (int id = n - 1; id >= 0; id--) {
        int i = order[id];
        if (res[i] == -1) {
            res[i] = cnt++;
            dfs2(i);
        }
    }
    return res;
}

vector<vector<int>> scc_graph(const vector<vector<int>> &g, const vector<int> &c) {
    vector<vector<int>> new_g(c.size());
    for (int i = 0; i < (int) g.size(); i++) {
        for (int j : g[i]) {
            if (c[i] < c[j]) {
                new_g[c[i]].emplace_back(c[j]);
            }
        }
    }
    for (int i = 0; i < (int) new_g.size(); i++) {
        sort(new_g[i].begin(), new_g[i].end());
        new_g[i].resize(unique(new_g[i].begin(), new_g[i].end()) - new_g[i].begin());
    }
    return new_g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int c = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c = __gcd(c, a[i]);
        }
        int ans = 0;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (a[i] != a[(i + 1) % n]) {
                b.emplace_back(i);
            }
        }
        sort(b.begin(), b.end());
        while (!b.empty()) {
            vector<int> d;
            vector<int> new_a;
            for (int i : b) {
                new_a.emplace_back(__gcd(a[i], a[(i + 1) % n]));
            }
            for (int i = 0; i < (int) b.size(); i++) {
                a[b[i]] = new_a[i];
            }
            for (int i : b) {
                if (a[i] != a[(i + n - 1) % n]) {
                    d.emplace_back((i + n - 1) % n);
                }
                if (a[i] != a[(i + 1) % n]) {
                    d.emplace_back(i);
                }
            }
            sort(d.begin(), d.end());
            d.resize(unique(d.begin(), d.end()) - d.begin());
            swap(b, d);
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}