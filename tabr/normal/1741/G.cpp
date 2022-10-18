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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        int f;
        cin >> f;
        vector<int> h(f);
        for (int i = 0; i < f; i++) {
            cin >> h[i];
            h[i]--;
        }
        int k;
        cin >> k;
        vector<int> p(k);
        for (int i = 0; i < k; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<int> d(n, -1);
        d[0] = 0;
        queue<int> que;
        que.emplace(0);
        vector<set<int>> s(n);
        s[0].emplace(0);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < k; i++) {
                if (v == h[p[i]]) {
                    set<int> new_s;
                    for (int x : s[v]) {
                        new_s.emplace(x | (1 << i));
                    }
                    swap(s[v], new_s);
                }
            }
            for (int to : g[v]) {
                if (d[to] == -1) {
                    d[to] = d[v] + 1;
                    que.emplace(to);
                }
                if (d[to] == d[v] + 1) {
                    for (int x : s[v]) {
                        s[to].emplace(x);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            debug(s[i]);
        }
        set<int> t;
        t.emplace(0);
        for (int i = 0; i < f; i++) {
            if (find(p.begin(), p.end(), i) != p.end()) {
                continue;
            }
            debug(i);
            set<int> new_t = t;
            for (int x : t) {
                for (int y : s[h[i]]) {
                    new_t.emplace(x | y);
                }
            }
            swap(t, new_t);
        }
        int ans = 0;
        for (int x : t) {
            ans = max(ans, __builtin_popcount(x));
        }
        debug(t);
        ans = k - ans;
        cout << ans << '\n';
    }
    return 0;
}