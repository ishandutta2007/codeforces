#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, a[MAXN], b[MAXN], c[MAXN], minA[MAXN];
long long ans;
vector<int> tree[MAXN];

int dfs(int u, int par) {
    int deltaU = c[u] - b[u];
    for(int v: tree[u]) {
        if (v == par)
            continue;
        minA[v] = min(minA[u], a[v]);
        int deltaV = dfs(v, u);
        if (1LL * deltaU * deltaV < 0)
            ans += 2LL * minA[u] * min(abs(deltaU), abs(deltaV));
        deltaU += deltaV;
    }
    return deltaU;
}

int main() {
    scanf("%d", &n);
    for(int u = 1; u <= n; ++u)
        scanf("%d%d%d", &a[u], &b[u], &c[u]);

    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int root = 1;
    minA[root] = a[root];
    int delta = dfs(root, -1);
    if (delta != 0) 
        puts("-1");
    else
        printf("%lld", ans);

    return 0;
}