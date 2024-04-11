#include <bits/stdc++.h>
using namespace std;

const int kN = 1'000'000;
vector<int> g[kN], r[kN], topo;
int scc[kN], sat[kN];
bool v[kN];

void AddEdge(int u, int v) {
    g[u].push_back(v);
    r[v].push_back(u);
}

void Dfs(int x) {
    v[x] = true;
    for (int u : g[x]) {
        if (!v[u]) Dfs(u);
    }
    topo.push_back(x);
}

void RvDfs(int x, int z) {
    scc[x] = z;
    for (int u : r[x]) {
        if (scc[u] == -1) RvDfs(u, z);
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            r[i].clear();
            v[i] = false;
            scc[i] = -1;
            sat[i] = -1;
        }
        for (int i = 0; i < m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            if (u == v) continue;
            --u, --v;
            AddEdge(u, v);
        }
        topo.clear();
        for (int i = 0; i < n; ++i) {
            if (!v[i]) Dfs(i);
        }
        int sz = 0;
        for (int i = n - 1; i >= 0; --i) {
            int x = topo[i];
            if (scc[x] == -1) RvDfs(x, sz++);
        }
        if (sz == 1) {
            puts("No");
            continue;
        }

        vector<int> ans[2];
        for (int i = 0; i < n; ++i) {
            if (scc[i] == scc[topo.back()])
                ans[1].push_back(i);
            else
                ans[0].push_back(i);
        }

        puts("Yes");
        printf("%d %d\n", (int)ans[0].size(), (int)ans[1].size());
        for (int i = 0; i < 2; ++i) {
            for (int u : ans[i]) printf("%d ", u + 1);
            puts("");
        }
    }
    return 0;
}