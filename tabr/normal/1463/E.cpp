#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> topsort(vector<vector<int>> g) {
    int n = (int)g.size();
    vector<int> deg(n);
    for (int v = 0; v < n; v++) {
        for (int to : g[v]) {
            deg[to]++;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            res.emplace_back(i);
        }
    }
    for (int i = 0; i < (int)res.size(); i++) {
        int v = res[i];
        for (int to : g[v]) {
            if (--deg[to] == 0) {
                res.emplace_back(to);
            }
        }
    }
    if ((int)res.size() != n) {
        return vector<int>();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> to(n, -1), from(n, -1);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        to[x] = y;
        from[y] = x;
    }
    int cnt = 0;
    vector<vector<int>> a;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (from[i] != -1) {
            continue;
        }
        int v = i;
        vector<int> q;
        while (v != -1) {
            b[v] = (int)a.size();
            cnt++;
            q.emplace_back(v);
            v = to[v];
        }
        a.emplace_back(q);
        set<int> st;
        for (int j = (int)q.size() - 1; j >= 0; j--) {
            if (st.count(p[q[j]])) {
                cout << 0 << '\n';
                return 0;
            }
            st.emplace(q[j]);
        }
    }
    if (cnt != n) {
        cout << 0 << '\n';
        return 0;
    }
    debug(a);
    debug(b);
    int m = (int)a.size();
    vector<vector<int>> g(m);
    for (int i = 0; i < n; i++) {
        if (p[i] != -1 && b[p[i]] != b[i]) {
            g[b[p[i]]].emplace_back(b[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
    }
    debug(g);
    vector<int> c = topsort(g);
    if (c.empty()) {
        cout << 0 << '\n';
    } else {
        for (int i : c) {
            for (int j : a[i]) {
                cout << j + 1 << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}