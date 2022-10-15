#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> E(n);
    vector<int> l(m), r(m);
    for (int j = 0; j < m; ++j) {
        int a, b;
        cin >> a >> b >> l[j] >> r[j];
        --a, --b;
        E[a].push_back({j, b});
        E[b].push_back({j, a});
    }
    for (int u = 0; u < n; ++u) {
        sort(begin(E[u]), end(E[u]), [&](auto e, auto f) { return l[e[0]] < l[f[0]]; });
    }
    vector<array<int, 2>> ptr(n);
    priority_queue<array<int, 3>> pq;
    vector<int> dist(n, inf);
    dist[0] = 0;
    pq.push({0, 0, -1});
    auto maxt = [&](int t, int j) {
        if (j == -1) return t;
        int x = r[j] - t;
        x -= x % 2;
        return t + x;
    };
    while (not empty(pq)) {
        auto [t, u, p] = pq.top();
        t *= -1;
        pq.pop();
        dist[u] = min(dist[u], t);
        int b = t % 2;
        while (ptr[u][b] < (int)size(E[u])) {
            auto [j, v] = E[u][ptr[u][b]];
            int e = max(l[j] + (l[j] % 2 != b), t);
            if (e >= r[j]) {
                ++ptr[u][b];
                continue;
            }
            if (e > maxt(t, p)) break;
            ++ptr[u][b];
            pq.push({-(e + 1), v, j});
        }
    }
    int ans = dist[n - 1];
    if (ans == inf) ans = -1;
    cout << ans << endl;
    exit(0);
}