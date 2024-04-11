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
    vector<vector<int>> g(n);
    vector<map<int, int>> f(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        f[x][y]++;
        f[x][-1]++;
        g[y].emplace_back(x);
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
    }
    const long long inf = (long long) 1e18;
    vector<long long> d(n, inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    d[n - 1] = 0;
    pq.emplace(d[n - 1], n - 1);
    while (!pq.empty()) {
        auto [dv, v] = pq.top();
        pq.pop();
        if (d[v] != dv) {
            continue;
        }
        for (int from : g[v]) {
            f[from][-1] -= f[from][v];
            long long cost = d[v] + 1 + f[from][-1];
            if (d[from] > cost) {
                d[from] = cost;
                pq.emplace(d[from], from);
            }
        }
    }
    cout << d[0] << '\n';
    return 0;
}