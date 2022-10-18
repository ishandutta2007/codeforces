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
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    int ans = abs(sx - fx) + abs(sy - fy);
    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> p = x, q = y;
    p.emplace_back(sx);
    q.emplace_back(sy);
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    sort(q.begin(), q.end());
    q.resize(unique(q.begin(), q.end()) - q.begin());
    int k = (int)(p.size() + q.size());
    vector<vector<pair<int, int>>> g(k);
    vector<int> d(k, 2e9);
    int ps = (int)p.size(), qs = (int)q.size();
    for (int i = 1; i < ps; i++) {
        g[i - 1].emplace_back(i, p[i] - p[i - 1]);
        g[i].emplace_back(i - 1, p[i] - p[i - 1]);
    }
    for (int i = 1; i < qs; i++) {
        g[ps + i - 1].emplace_back(ps + i, q[i] - q[i - 1]);
        g[ps + i].emplace_back(ps + i - 1, q[i] - q[i - 1]);
    }
    x.emplace_back(sx);
    y.emplace_back(sy);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i <= m; i++) {
        int a = lower_bound(p.begin(), p.end(), x[i]) - p.begin();
        int b = lower_bound(q.begin(), q.end(), y[i]) - q.begin();
        g[a].emplace_back(ps + b, 0);
        g[ps + b].emplace_back(a, 0);
        if (i == m) {
            d[a] = d[ps + b] = 0;
            pq.emplace(0, a);
            pq.emplace(0, ps + b);
        }
    }
    while (!pq.empty()) {
        int v, cost;
        tie(cost, v) = pq.top();
        pq.pop();
        if (d[v] != cost) {
            continue;
        }
        for (auto e : g[v]) {
            int to, c;
            tie(to, c) = e;
            if (d[to] > d[v] + c) {
                d[to] = d[v] + c;
                pq.emplace(d[to], to);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a = lower_bound(p.begin(), p.end(), x[i]) - p.begin();
        ans = min(ans, d[a] + abs(x[i] - fx) + abs(y[i] - fy));
    }
    cout << ans << '\n';
    return 0;
}