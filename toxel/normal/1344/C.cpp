#include <bits/stdc++.h>

const int N = 200010;

std::vector<int> e[2][N];
bool vis[2][N], vis1[N];
std::vector<int> topo;
int inv[N];
char ans[N];

void dfs(int u, std::vector<int> *e){
    if (vis1[u]){
        return;
    }
    vis1[u] = true;
    for (const auto &v : e[u]){
        dfs(v, e);
    }
    topo.emplace_back(u);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[0][u].emplace_back(v);
        e[1][v].emplace_back(u);
    }
    for (int i = 1; i <= n; ++ i){
        if (!vis1[i]){
            dfs(i, e[0]);
        }
    }
    std::reverse(topo.begin(), topo.end());
    for (int i = 0; i < n; ++ i){
        inv[topo[i]] = i;
    }
    for (int i = 1; i <= n; ++ i){
        for (auto u : e[0][i]){
            if (inv[i] > inv[u]){
                puts("-1");
                return 0;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        if (vis[0][i] || vis[1][i]){
            ans[i] = 'E';
        }
        else{
            ans[i] = 'A';
            ++ cnt;
        }
        for (int j = 0; j < 2; ++ j){
            if (vis[j][i]){
                continue;
            }
            std::queue <int> queue;
            vis[j][i] = true;
            queue.emplace(i);
            while (!queue.empty()){
                int u = queue.front();
                queue.pop();
                for (auto v : e[j][u]){
                    if (!vis[j][v]){
                        vis[j][v] = true;
                        queue.emplace(v);
                    }
                }
            }
        }
    }
    printf("%d\n%s\n", cnt, ans + 1);
    return 0;
}