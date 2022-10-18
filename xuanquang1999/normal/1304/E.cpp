#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MAXK = 20;

int n, k, q, dist[MAXN], par[MAXN], b[MAXK][MAXN];
vector<int> tree[MAXN];

void dfs(int u) {
    for(int v: tree[u]) {
        if (v == par[u])
            continue;
        par[v] = u;
        dist[v] = dist[u] + 1;
        dfs(v);
    }
}

int lca(int u, int v) {
    if (dist[u] < dist[v])
        swap(u, v);

    int t = dist[u] - dist[v];
    for(int i = 0; i <= k; ++i)
        if ((t>>i)&1)
            u = b[i][u];

    for(int i = k; i >= 0; --i) {
        if (b[i][u] != b[i][v]) {
            u = b[i][u];
            v = b[i][v];
        }
    }
    return (u == v) ? u : b[0][u];
}

int getDist(int u, int v) {
    int w = lca(u, v);
    return dist[u] + dist[v] - 2*dist[w];
}

bool check(int dist, int k) {
    return k >= dist && (k - dist) % 2 == 0;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    k = log2(n);
    for(int u = 1; u <= n; ++u)
        b[0][u] = par[u];
    for(int i = 1; i <= k; ++i)
        for(int u = 1; u <= n; ++u)
            b[i][u] = b[i-1][b[i-1][u]];

    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        int x, y, a, b, k;
        scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);

//        printf("i: %d\n", i);

        int d1 = getDist(a, b);
        int d2 = min(getDist(a, x) + getDist(y, b), getDist(a, y) + getDist(x, b)) + 1;

//        printf("%d %d\n", d1, d2);

        bool ans = (check(d1, k) || check(d2, k));
        puts(ans ? "YES" : "NO");
    }

    return 0;
}