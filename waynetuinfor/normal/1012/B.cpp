#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
vector<int> g[maxn];
bool v[maxn];

void dfs(int x) {
    v[x] = true;
    for (int u : g[x]) 
        if (!v[u]) dfs(u);
}

int main() {
    int n, m, q; scanf("%d %d %d", &n, &m, &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        --x, --y;
        g[x].push_back(n + y);
        g[n + y].push_back(x);
    }
    int c = 0;
    for (int i = 0; i < n + m; ++i) 
        if (!v[i]) ++c, dfs(i);
    printf("%d\n", c - 1);
    return 0;
}