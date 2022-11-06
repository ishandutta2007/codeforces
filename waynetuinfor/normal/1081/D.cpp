#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int fa[maxn], sz[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x; scanf("%d", &x);
        sz[x - 1] = 1;
    }
    for (int i = 0; i < n; ++i) fa[i] = i;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        edge.emplace_back(w, u, v);
    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int w, u, v; tie(w, u, v) = edge[i];
        if ((u = find(u)) == (v = find(v))) continue;
        if (sz[u] > 0 && sz[v] > 0) ans = w;
        fa[u] = v;
        sz[v] += sz[u];
    }
    for (int i = 0; i < k; ++i) printf("%d ", ans);
    puts("");
    return 0;
}