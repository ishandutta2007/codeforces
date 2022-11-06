#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

vector<int> graf[maxn], cur;
int deg[maxn];
bool v[maxn];

void dfs(int x) {
    v[x] = true;
    cur.push_back(x);
    for (int u : graf[x]) if (!v[u]) dfs(u); 
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        graf[a].push_back(b), graf[b].push_back(a);
        ++deg[a], ++deg[b];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        cur.clear();
        dfs(i);
        bool f = true;
        for (int u : cur) f &= (deg[u] == 2);
        if (f) ++ans; 
    }
    printf("%d\n", ans);
}