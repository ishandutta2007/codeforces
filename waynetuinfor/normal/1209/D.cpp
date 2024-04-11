#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> uf(n), ed(n), sz(n);
    for (int i = 0; i < n; ++i) {
        uf[i] = i;
        sz[i] = 1;
    }

    function<int(int)> Find = [&](int u) {
        if (uf[u] == u) return u;
        return uf[u] = Find(uf[u]);
    };

    auto Merge = [&](int u, int v) {
        if ((u = Find(u)) == (v = Find(v))) {
            ++ed[u];
            return;
        }
        uf[u] = v;
        ed[v] += ed[u] + 1;
        sz[v] += sz[u];
    };

    for (int i = 0; i < k; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        Merge(u, v);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (Find(i) == i) ans += ed[i] - sz[i] + 1;
    }
    printf("%d\n", ans);
    return 0;
}