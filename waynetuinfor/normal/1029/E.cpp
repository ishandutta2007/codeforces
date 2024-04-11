#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> g[maxn];
int ans;
bool cn[maxn];

int dfs(int x, int fa, int d) {
    int c = 0;
    bool ok = false;
    for (int u : g[x]) if (u != fa) {
        int y = dfs(u, x, d + 1);
        c += y;
        if (cn[u]) ok = true;
    }
    if (c > 0 && d > 1) {
        ++ans;
        cn[x] = true;
        return 0;
    }
    if (ok) return 0;
    return 1;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1, 0);
    printf("%d\n", ans);
}