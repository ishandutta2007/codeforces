#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int n, par[N];
vector<int> g[N], cyc;
bool vis[N];

void dfs(int u, int p = -1) {
        vis[u] = true;
        for (int v : g[u]) {
                if (v == p) continue;
                if (vis[v]) {
                        if (!cyc.empty())
                                continue;
                        int x = u;
                        for (; x != v; x = par[x])
                                cyc.push_back(x);
                        cyc.push_back(v);
                        return;
                }
                par[v] = u;
                dfs(v, par[v]);
        }
}

int dist[N];

void bfs() {
        for (int i = 0; i < n; i++)
                dist[i] = 1e9;
        set<pair<int, int>> que;
        for (int i : cyc)
                que.insert({0, i}), dist[i] = 0;
        while (!que.empty()) {
                int u = que.begin() -> second;
                que.erase(que.begin());
                for (int v : g[u]) {
                        if (dist[v] > dist[u] + 1) {
                                que.erase({dist[v], v});
                                dist[v] = dist[u] + 1;
                                que.insert({dist[v], v});
                        }
                }
        }
}

int main() {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                int u, v;
                scanf("%d%d", &u, &v);
                --u, --v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        par[0] = -1;
        dfs(0, -1);
        bfs();
        for (int i = 0; i < n; i++)
                printf("%d ", dist[i]);
}