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
        int n, k;
        cin >> n >> k;
        int m = (k + 1) * (k + 1);
        vector<vector<pair<int, int>>> g(m);
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (i != k) {
                    int x = i * (k + 1) + j;
                    int y = (i + 1) * (k + 1) + j;
                    g[x].emplace_back(y, 0);
                    g[y].emplace_back(x, 0);
                }
                if (j != k) {
                    int x = i * (k + 1) + j;
                    int y = i * (k + 1) + j + 1;
                    g[x].emplace_back(y, 0);
                    g[y].emplace_back(x, 0);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            if (make_pair(x1, y1) > make_pair(x2, y2)) {
                swap(x1, x2);
                swap(y1, y2);
            }
            int z1 = -1;
            int z2 = -1;
            if (x1 == x2) {
                x2++;
                z1 = x1 * (k + 1) + y2;
                z2 = x2 * (k + 1) + y2;
            } else {
                z1 = x2 * (k + 1) + y2;
                z2 = x2 * (k + 1) + y2 + 1;
            }
            debug(z1, z2);
            for (auto& p : g[z1]) {
                if (p.first == z2) {
                    p.second++;
                }
            }
            for (auto& p : g[z2]) {
                if (p.first == z1) {
                    p.second++;
                }
            }
            z1 = m - 1 - z1;
            z2 = m - 1 - z2;
            for (auto& p : g[z1]) {
                if (p.first == z2) {
                    p.second++;
                }
            }
            for (auto& p : g[z2]) {
                if (p.first == z1) {
                    p.second++;
                }
            }
        }
        debug(g);
        vector<int> d(m, (int) 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        d[m / 2] = 0;
        pq.emplace(d[m / 2], m / 2);
        while (!pq.empty()) {
            auto [ex, v] = pq.top();
            pq.pop();
            if (d[v] != ex) {
                continue;
            }
            for (auto [to, c] : g[v]) {
                int cost = d[v] + c;
                if (d[to] > cost) {
                    d[to] = cost;
                    pq.emplace(d[to], to);
                }
            }
        }
        cout << n - d[0] << '\n';
    }
    return 0;
}