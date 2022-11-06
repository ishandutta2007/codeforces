#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 23;
int a[maxn], sz[maxn], fa[maxn], rev[maxn];
bool v[maxn];

int find(int u) {
    if (u == fa[u]) return u;
    return fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    fa[u] = v;
}

void dfs(int x, int f, int n) {
    v[x] = true;
    if (~rev[x]) merge(rev[x], f);
    if (x >> n & 1) {
        for (int i = 0; i < n; ++i) {
            if (!(x >> i & 1)) {
                if (!v[x ^ (1 << i)]) dfs(x ^ (1 << i), f, n);
            }
        }
        if (~rev[x ^ (1 << n) ^ ((1 << n) - 1)] && !v[x ^ ((1 << n) - 1) ^ (1 << n)]) dfs(x ^ ((1 << n) - 1) ^ (1 << n), f, n);
    } else {
        if (~rev[x] && !v[x ^ (1 << n)]) dfs(x ^ (1 << n), f, n); 
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    memset(rev, -1, sizeof(rev));
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
        rev[a[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        sz[i] = 1;
        fa[i] = i;
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) if (!v[a[i]]) dfs(a[i], i, n);
    for (int i = 0; i < m; ++i) if (find(i) == i) ++ans;
    printf("%d\n", ans);
    return 0;
}