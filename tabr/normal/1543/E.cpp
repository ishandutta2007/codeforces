#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// editorial

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int vc = 1 << n;
        int ec = n * (1 << (n - 1));
        debug(n, vc, ec);
        vector<vector<int>> g(vc);
        for (int i = 0; i < ec; i++) {
            int x, y;
            cin >> x >> y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<int> p(vc);
        vector<int> d(vc, -1);
        queue<int> que;
        que.emplace(0);
        d[0] = 0;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int to : g[v]) {
                if (d[to] == -1) {
                    d[to] = d[v] + 1;
                    if (d[v] == 0) {
                        p[to] = 1 << (int) que.size();
                    } else {
                        p[to] = p[v];
                    }
                    que.emplace(to);
                } else if (d[to] == d[v] + 1) {
                    p[to] |= p[v];
                }
            }
        }
        vector<int> q(vc);
        for (int i = 0; i < vc; i++) {
            q[p[i]] = i;
        }
        for (int i : q) {
            cout << i << " ";
        }
        cout << '\n';
        if (__builtin_popcount(n) == 1) {
            for (int i = 0; i < vc; i++) {
                int k = 0;
                for (int j = 0; j < n; j++) {
                    if (p[i] & (1 << j)) {
                        k ^= j;
                    }
                }
                cout << k << " ";
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}