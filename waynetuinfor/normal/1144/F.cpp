#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> g[maxn];
int c[maxn], u[maxn], v[maxn];

bool dfs(int x, int y) {
    c[x] = y;
    bool res = true;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (c[u] >= 0) {
            if (c[u] == c[x]) 
                res = false;
            continue;
        }
        res &= dfs(u, y ^ 1);
    }
    return res;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        --u[i], --v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    memset(c, -1, sizeof(c));
    bool bipartite = true;
    for (int i = 0; i < n; ++i) {
        if (c[i] == -1)
            bipartite &= dfs(i, 0);
    }
    if (!bipartite) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < m; ++i) 
        printf("%d", c[u[i]]);
    return 0;
}