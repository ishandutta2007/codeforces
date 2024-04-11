#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m, k, par[MAXN], color[MAXN];
vector<int> graph[MAXN], cycle;
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
        
    for(int v: graph[u]) {
        if (!cycle.empty())
            return;

        if (v == par[u])
            continue;
        if (visited[v]) {
            for(int w = u; w != v; w = par[w])
                cycle.push_back(w);            
            cycle.push_back(v);
        } else {
            color[v] = 1 - color[u];
            par[v] = u;
            dfs(v);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    if (cycle.empty()) {
        vector<int> vtx[2];
        for(int u = 1; u <= n; ++u)
            vtx[color[u]].push_back(u);

        int id = (vtx[0].size() > vtx[1].size()) ? 0 : 1;
        puts("1");
        for(int i = 0; i < (k+1)/2; ++i)
            printf("%d ", vtx[id][i]);
    } else {
        while (true) {
            // for(int u: cycle)
            //     printf("%d ", u);
            // puts("");

            int p = cycle.size();
            vector<int> ind(n+1, -1);
            for(int i = 0; i < p; ++i)
                ind[cycle[i]] = i;
            
            vector<int> nxtCycle;
            for(int i = 0; i < p; ++i) {
                if (!nxtCycle.empty())
                    break;
                int prv = cycle[(i+p-1)%p], u = cycle[i], nxt = cycle[(i+1)%p];
                for(int v: graph[u]) {
                    if (v != prv && v != nxt && ind[v] > i) {                        
                        int l = i, r = ind[v];
                        // printf("%d %d\n", l, r);
                        if (r-l <= n-(r-l)) {
                            for(int j = l; j <= r; ++j)
                                nxtCycle.push_back(cycle[j]);                                
                        } else {
                            for(int j = 0; j <= l; ++j)
                                nxtCycle.push_back(cycle[j]);
                            for(int j = r; j < p; ++j)
                                nxtCycle.push_back(cycle[j]);
                        }
                        break;                            
                    }
                }
            }

            if (nxtCycle.empty())
                break;
            cycle = nxtCycle;
        }

        if (cycle.size() <= k) {
            puts("2");
            printf("%d\n", cycle.size());
            for(int u: cycle)
                printf("%d ", u);
        } else {
            puts("1");
            for(int i = 0; i < (k+1)/2; ++i)
                printf("%d ", cycle[2*i]);
        }
    }

    return 0;
}