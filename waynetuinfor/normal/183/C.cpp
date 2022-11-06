#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn], r[maxn];
int c[maxn], fa[maxn], cl[maxn];
bool v[maxn];

void dfs(int x, int z) {
    c[x] = z;
    v[x] = true;
    for (int u : g[x]) 
        if (!v[u]) dfs(u, z + 1);
    for (int u : r[x]) 
        if (!v[u]) dfs(u, z - 1);
}   

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
    cl[y] = min(cl[y], cl[x]);
}


int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        if (x == y) {
            puts("1");
            return 0;
        }
        g[x].push_back(y);
        r[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        sort(r[i].begin(), r[i].end());
        r[i].resize(unique(r[i].begin(), r[i].end()) - r[i].begin());
    }
    for (int i = 0; i < n; ++i) {
        if (!v[i]) dfs(i, 0);
    }
    for (int i = 0; i < n; ++i) fa[i] = i, cl[i] = c[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) merge(i, g[i][j]);
        for (int j = 0; j < r[i].size(); ++j) merge(i, r[i][j]);
    }
    for (int i = 0; i < n; ++i) {
        int p = find(i);
        c[i] += cl[p];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            int d = c[g[i][j]] - c[i] - 1;
            ans = __gcd(ans, abs(d));
        }
    }
    if (ans == 0) ans = n;
    printf("%d\n", ans);
    return 0;
}