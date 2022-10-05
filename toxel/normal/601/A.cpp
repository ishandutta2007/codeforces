#include<bits/stdc++.h>

const int N = 410;

std::vector <int> e1[N], e2[N];
int dis1[N], dis2[N];
bool vis[N];
int n;
int mat[N][N];

void bfs(std::vector <int> *e, int *dis, int s){
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++ i){
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    vis[s] = true;
    std::queue <int> queue;
    queue.push(s);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            if (!vis[v]){
                vis[v] = true;
                dis[v] = dis[u] + 1;
                queue.push(v);
            }
        }
    }
}

int main(){
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        mat[u][v] = mat[v][u] = 1;
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (i != j){
                if (mat[i][j]){
                    e1[i].push_back(j);
                }
                else{
                    e2[i].push_back(j);
                }
            }
        }
    }
    bfs(e1, dis1, 1);
    bfs(e2, dis2, 1);
    int ans = std::max(dis1[n], dis2[n]);
    if (ans == INT_MAX){
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}