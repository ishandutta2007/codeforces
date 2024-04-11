#include<bits/stdc++.h>

const int N = 100010;
const int M = 110;

std::vector <int> e[N];
int a[N];
int dis[N][M];
bool vis[N];

int main(){
    int n, m, k, s;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= k; ++ i){
        memset(vis, 0, sizeof(vis));
        std::queue <int> queue;
        for (int j = 1; j <= n; ++ j){
            if (a[j] == i){
                vis[j] = true;
                queue.push(j);
            }
        }
        while (!queue.empty()){
            int u = queue.front();
            queue.pop();
            for (auto v : e[u]){
                if (!vis[v]){
                    dis[v][i] = dis[u][i] + 1;
                    queue.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        std::sort(dis[i] + 1, dis[i] + k + 1);
        long long sum = 0;
        for (int j = 1; j <= s; ++ j){
            sum += dis[i][j];
        }
        printf("%lld%c", sum, " \n"[i == n]);
    }
    return 0;
}