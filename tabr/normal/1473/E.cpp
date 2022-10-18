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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n * 4);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        for (int j = 0; j < 4; j++) {
            g[x + n * j].emplace_back(y + n * j, w);
            g[y + n * j].emplace_back(x + n * j, w);
            if (j % 2 == 0) {
                g[x + n * j].emplace_back(y + n * (j + 1), w * 2);
                g[y + n * j].emplace_back(x + n * (j + 1), w * 2);
            }
            if (j < 2) {
                g[x + n * j].emplace_back(y + n * (j + 2), 0);
                g[y + n * j].emplace_back(x + n * (j + 2), 0);
            }
        }
    }
    long long inf = (long long)1e18;
    vector<long long> d(4 * n, inf);
    d[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(d[0], 0);
    while (!pq.empty()) {
        auto [ex, v] = pq.top();
        pq.pop();
        if (d[v] != ex) {
            continue;
        }
        for (auto [to, w] : g[v]) {
            if (d[to] > d[v] + w) {
                d[to] = d[v] + w;
                pq.emplace(d[to], to);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        cout << min(d[i], d[i + 3 * n]) << " ";
    }
    cout << '\n';
    return 0;
}