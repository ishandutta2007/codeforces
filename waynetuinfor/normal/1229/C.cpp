#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int>> g(n);
    vector<int> cnt(n);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
    vector<array<int, 2>> dg(n, array<int, 2>{});
    vector<int> a(n);
    vector<vector<int>> ind(n);
    for (int i = 0; i < n; ++i) a[i] = i;
    for (int i = 0; i < n; ++i) {
        for (int u : g[i]) {
            if (i < u) continue;
            if (a[i] > a[u]) {
                ++dg[i][0];
                ++dg[u][1];
                ind[u].push_back(i);
            } else {
                ++dg[i][1];
                ++dg[u][0];
                ind[i].push_back(u);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) ans += 1LL * dg[i][0] * dg[i][1];
    printf("%lld\n", ans);
    int q; scanf("%d", &q);
    for (int it = 0; it < q; ++it) {
        int v; scanf("%d", &v);
        v--;
        ans -= 1LL * dg[v][0] * dg[v][1];
        for (int u : ind[v]) {
            ans -= 1LL * dg[u][0] * dg[u][1];
            --dg[u][0];
            ++dg[u][1];
            ans += 1LL * dg[u][0] * dg[u][1];
            ind[u].push_back(v);
        }
        dg[v][0] = g[v].size();
        dg[v][1] = 0;
        ind[v].clear();
        printf("%lld\n", ans);
    }
}