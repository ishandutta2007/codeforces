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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
            deg[x]++;
            deg[y]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
            if (deg[i] < k) {
                que.emplace(i);
            }
        }
        int id = -1;
        vector<int> ans;
        vector<int> del(n);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (deg[v] == k - 1) {
                vector<int> t;
                t.emplace_back(v);
                for (int to : g[v]) {
                    if (!del[to]) {
                        t.emplace_back(to);
                    }
                }
                bool ok = true;
                for (int i = 0; i < k; i++) {
                    for (int j = i + 1; j < k; j++) {
                        if (!binary_search(g[t[i]].begin(), g[t[i]].end(), t[j])) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    ans = t;
                    id = 2;
                    break;
                }
            }
            del[v] = 1;
            for (int to : g[v]) {
                deg[to]--;
                if (deg[to] == k - 1) {
                    que.emplace(to);
                }
            }
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (!del[i]) {
                s++;
                id = max(id, 1);
            }
        }
        if (id == 1) {
            cout << 1 << " " << s << '\n';
            for (int i = 0; i < n; i++) {
                if (!del[i]) {
                    cout << i + 1 << " ";
                }
            }
            cout << '\n';
        } else if (id == 2) {
            cout << 2 << '\n';
            for (int i : ans) {
                cout << i + 1 << " ";
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}