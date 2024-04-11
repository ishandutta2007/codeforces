#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
vector<int> g[maxn];
int sz[maxn], fa[maxn];

void dfs(int x, int p) {
    sz[x] = 1; fa[x] = p;
    for (int u : g[x]) if (u != p) {
        dfs(u, x);
        sz[x] += sz[u];
    }
}

int main() {
    int n, x, y; scanf("%d %d %d", &n, &x, &y);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        g[a].push_back(b), g[b].push_back(a);
    }
    dfs(y, 0);
    int t = x, f = -1;
    while (true) {
        if (fa[t] == y) {
            f = t;
            break;
        }
        t = fa[t];
    }
    long long all = n * 1ll * (n - 1);
    long long sub = (n - sz[t]) * 1ll * sz[x];
    printf("%lld\n", all - sub);
    return 0;
}