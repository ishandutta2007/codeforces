#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
vector<int> g[maxn];
bool used[maxn][maxn];
int v[maxn], stk[maxn];

void dfs(int z, int m, int x, bool eq) {
    stk[z] = x;
    if (z == m) {
        if (eq) return;
        for (int i = 0; i < m + 1; ++i) printf("%d ", stk[i] + 1);
        puts("");
        exit(0);
    }

    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (!used[x][g[x][i]] && !used[g[x][i]][x]) {
            if (!eq || g[x][i] >= v[z + 1]) {
                used[x][g[x][i]] = true;
                dfs(z + 1, m, g[x][i], g[x][i] > v[z + 1] ? false : eq);
                used[x][g[x][i]] = false;
            }
        }
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m + 1; ++i) {
        scanf("%d", &v[i]);
        --v[i];
    }
    for (int i = 0; i < m; ++i) {
        g[v[i]].push_back(v[i + 1]);
        g[v[i + 1]].push_back(v[i]);
    }

    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(0, m, v[0], true);
    puts("No solution");
    return 0;
}