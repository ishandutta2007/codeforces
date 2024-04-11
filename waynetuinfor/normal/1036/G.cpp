#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> g[maxn];
int indeg[maxn], outdeg[maxn];
int mark[maxn], mask[maxn];
bool v[maxn];

void dfs(int x, int p) {
    v[x] = true;
    if (~mark[x]) mask[p] |= (1 << mark[x]);
    for (int u : g[x]) {
        if (v[u]) continue;
        dfs(u, p);
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        ++outdeg[x], ++indeg[y];
    }
    memset(mark, -1, sizeof(mark));
    int sz = 0;
    for (int i = 0; i < n; ++i) if (outdeg[i] == 0) mark[i] = sz++;
    sz = 0;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] > 0) continue;
        memset(v, false, sizeof(v));
        dfs(i, sz);
        sz++;
    }
    for (int i = 1; i < (1 << sz) - 1; ++i) {
        int all = 0;
        for (int j = 0; j < sz; ++j) if (i >> j & 1) all |= mask[j];
        if (__builtin_popcount(i) >= __builtin_popcount(all)) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}