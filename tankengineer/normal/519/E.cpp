#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, LOG = 17;

vector<int> edge[N];

int fa[N][LOG], dep[N], size[N];

void dfs(int u) {
    size[u] = 1;
    for (int i = 0; i < (int)edge[u].size(); ++i) {
        int v = edge[u][i];
        if (v == fa[u][0]) {
            continue;
        }
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        dfs(v);
        size[u] += size[v];
    }
}

int jump(int u, int d) {
    for (int i = LOG - 1; i >= 0; --i) {
        if (d >> i & 1) {
            u = fa[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    u = jump(u, dep[u] - dep[v]);
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(fa, -1, sizeof(fa));
    dfs(0);
    for (int i = 1; i < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            if (fa[j][i - 1] == -1) {
                continue;
            }
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int u , v;
        scanf("%d%d", &u, &v);
        --u, --v;
        if (u == v) {
            printf("%d\n", n);
            continue;
        }
        if (dep[u] + dep[v] & 1) {
            printf("%d\n", 0);
        } else {
            int w = lca(u, v), ans = 0;
            if (dep[u] == dep[v]) {
                ans = n - size[jump(u, dep[u] - dep[w] - 1)] - size[jump(v, dep[v] - dep[w] - 1)];
            } else {
                if (dep[u] < dep[v]) {
                    swap(u, v);
                }
                int d = dep[u] + dep[v] - 2 * dep[w], x = jump(u, d >> 1);
                ans = size[x] - size[jump(u, dep[u] - dep[x] - 1)];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}