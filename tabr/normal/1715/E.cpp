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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, long long>>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }
    const long long inf = (long long) 1e18;
    vector<long long> d(n, inf);
    d[0] = 0;
    for (int zz = 0; zz < k + 1; zz++) {
        if (zz > 0) {
            // (-2 * i, d[i] + i * i)
            deque<pair<long long, long long>> deq;
            for (int i = 0; i < n; i++) {
                long long x0 = -2 * i;
                long long y0 = d[i] + i * 1LL * i;
                while (deq.size() >= 2) {
                    auto [x1, y1] = deq.back();
                    deq.pop_back();
                    auto [x2, y2] = deq.back();
                    long double z01 = (y0 - y1) * -1.0L / (x0 - x1);
                    long double z12 = (y2 - y1) * -1.0L / (x2 - x1);
                    if (z12 <= z01) {
                        deq.emplace_back(x1, y1);
                        break;
                    }
                }
                deq.emplace_back(x0, y0);
            }
            debug(d);
            debug(deq);
            int sz = (int) deq.size();
            vector<long double> z;
            for (int i = 0; i < sz - 1; i++) {
                auto [x1, y1] = deq[i];
                auto [x2, y2] = deq[i + 1];
                z.emplace_back((y2 - y1) * -1.0L / (x2 - x1));
            }
            for (int i = 0; i < n; i++) {
                int l = (int) (lower_bound(z.begin(), z.end(), i) - z.begin());
                for (int j = max(0, l - 2); j <= min(sz - 1, l + 2); j++) {
                    auto [x, y] = deq[j];
                    d[i] = min(d[i], x * i + y + i * 1LL * i);
                }
            }
            debug(d);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.emplace(d[i], i);
        }
        while (!pq.empty()) {
            auto [dd, v] = pq.top();
            pq.pop();
            if (d[v] != dd) {
                continue;
            }
            for (auto [to, w] : g[v]) {
                if (d[to] > d[v] + w) {
                    d[to] = d[v] + w;
                    pq.emplace(d[to], to);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << " \n"[i == n - 1];
    }
    return 0;
}