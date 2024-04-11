#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> g[maxn];
int sz[maxn], dfn[maxn], rev[maxn], t;

void dfs(int x) {
    sz[x] = 1;
    dfn[x] = t++;
    rev[dfn[x]] = x;
    for (int u : g[x]) {
        dfs(u);
        sz[x] += sz[u];
    }
}

int main() {
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int p; scanf("%d", &p); --p;
        g[p].push_back(i);
    }
    for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());
    dfs(0);
    while (q--) {
        int u, k; scanf("%d %d", &u, &k); --u;
        if (sz[u] < k) puts("-1");
        else printf("%d\n", rev[dfn[u] + k - 1] + 1);
    }
}