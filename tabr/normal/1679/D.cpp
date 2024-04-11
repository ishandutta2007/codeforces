#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> topsort(const vector<vector<int>> &g) {
    int n = (int) g.size();
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
    for (int i = 0; i < (int) res.size(); i++) {
        int v = res[i];
        for (int to : g[v]) {
            if (--deg[to] == 0) {
                res.emplace_back(to);
            }
        }
    }
    if ((int) res.size() != n) {
        return vector<int>();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edges.emplace_back(x, y);
    }
    if (k == 1) {
        cout << *min_element(a.begin(), a.end()) << '\n';
        return 0;
    }
    sort(edges.begin(), edges.end(), [&](auto i, auto j) {
        return max(a[i.first], a[i.second]) < max(a[j.first], a[j.second]);
    });
    int low = 0;
    int high = m + 1;
    while (high - low > 1) {
        int mid = (high + low) >> 1;
        vector<vector<int>> g(n);
        for (int i = 0; i < mid; i++) {
            auto [x, y] = edges[i];
            g[x].emplace_back(y);
        }
        auto c = topsort(g);
        if (c.empty()) {
            high = mid;
            continue;
        }
        vector<int> dp(n);
        for (int v : c) {
            for (int to : g[v]) {
                dp[to] = max(dp[to], dp[v] + 1);
            }
        }
        if (*max_element(dp.begin(), dp.end()) >= k - 1) {
            high = mid;
        } else {
            low = mid;
        }
    }
    if (high == m + 1) {
        cout << -1 << '\n';
    } else {
        cout << max(a[edges[low].first], a[edges[low].second]) << '\n';
    }
    return 0;
}