#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
vector<int> g[maxn];
bitset<maxn> dp[maxn];
int sz[maxn], fa[maxn];

void dfs(int x, int p) {
    sz[x] = 1;
    fa[x] = p;

    for (int u : g[x]) {
        if (u == p) continue;
        dfs(u, x);
        sz[x] += sz[u];
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);

    bitset<maxn> ans;

    for (int i = 0; i < n; ++i) {
        bitset<maxn> dp;
        dp.set(0);
        for (int j = 0; j < (int)g[i].size(); ++j) {
            int u = g[i][j];
            if (u == fa[i]) continue;
            dp |= dp << sz[u];
        }
        if (fa[i] >= 0) dp |= dp << (n - sz[i]);
        ans |= dp;
    }

    vector<int> v;
    for (int i = 1; i < n - 1; ++i) if (ans[i]) v.push_back(i);

    printf("%d\n", (int)v.size());
    for (int i = 0; i < (int)v.size(); ++i) printf("%d %d\n", v[i], n - 1 - v[i]);
    return 0;
}