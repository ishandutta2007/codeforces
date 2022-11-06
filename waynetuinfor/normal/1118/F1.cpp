#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], sz[3][maxn], c[3];
vector<int> g[maxn];

int dfs(int x, int p) {
    sz[a[x]][x] = 1;
    int res = 0;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == p) continue;
        res += dfs(u, x);
        sz[0][x] += sz[0][u];
        sz[1][x] += sz[1][u];
        sz[2][x] += sz[2][u];
        if (sz[1][u] == 0) {
            if (sz[2][u] == c[2]) ++res;
        } else if (sz[2][u] == 0) {
            if (sz[1][u] == c[1]) ++res;
        }
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), ++c[a[i]];
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    printf("%d\n", dfs(0, -1));
    return 0;
}