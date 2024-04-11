#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int p[maxn], ok[maxn], deg[maxn];
vector<int> g[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);

    while (m--) {
        int u, v; scanf("%d%d", &u, &v);
        g[v].push_back(u);
    }

    for (int i = 0; i < (int)g[p[n - 1]].size(); ++i)
        ok[g[p[n - 1]][i]] = 1;

    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (ok[p[i]] && i + ans + 1 + deg[p[i]] == n - 1)
            ++ans;
        else
            for (int j = 0; j < (int)g[p[i]].size(); ++j)
                ++deg[g[p[i]][j]];
    }
    printf("%d\n", ans);
    return 0;
}