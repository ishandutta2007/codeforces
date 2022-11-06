#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    vector<int> a(k);
    for (int i = 0; i < k; ++i) scanf("%d", &a[i]), a[i]--;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto Bfs = [&](int r) {
        vector<int> d(n, -1);
        d[r] = 0;
        queue<int> q;
        q.push(r);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int u : g[x]) {
                if (d[u] == -1) {
                    d[u] = d[x] + 1;
                    q.push(u);
                }
            }
        }
        return d;
    };

    auto d1 = Bfs(0);
    auto d2 = Bfs(n - 1);
    int ans = 0;
    sort(a.begin(), a.end(), [&](int i, int j) { return d1[i] - d2[i] < d1[j] - d2[j]; });
    multiset<int> s;
    for (int i = 0, j = 0; i < k; ++i) {
        while (j < k && d1[a[j]] - d2[a[j]] <= d1[a[i]] - d2[a[i]]) s.insert(d1[a[j++]]);
        if (s.size() > 1) {
            s.erase(s.find(d1[a[i]]));
            ans = max(ans, d2[a[i]] + *s.rbegin() + 1);
            s.insert(d1[a[i]]);
        }
    }
    sort(a.begin(), a.end(), [&](int i, int j) { return d1[i] - d2[i] > d1[j] - d2[j]; });
    s.clear();
    for (int i = 0, j = 0; i < k; ++i) {
        while (j < k && d1[a[j]] - d2[a[j]] >= d1[a[i]] - d2[a[i]]) s.insert(d2[a[j++]]);
        if (s.size() > 1) {
            s.erase(s.find(d2[a[i]]));
            ans = max(ans, d1[a[i]] + *s.rbegin() + 1);
            s.insert(d2[a[i]]);
        }
    }
    if (ans > d1[n - 1]) ans = d1[n - 1];
    printf("%d\n", ans);
}