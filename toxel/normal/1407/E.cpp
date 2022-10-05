#include <bits/stdc++.h>

const int N = 500010;

std::vector<int> e_[N][2];
int ans[N], dis[N][2];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        e_[v][w].emplace_back(u);
    }
    memset(dis, -1, sizeof(dis));
    std::queue<int> queue;
    queue.emplace(n);
    dis[n][0] = dis[n][1] = 0;
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        int dis1 = std::max(dis[u][0], dis[u][1]);
        for (auto v : e_[u][0]){
            if (dis[v][0] == -1){
                dis[v][0] = dis1 + 1;
                if (dis[v][1] != -1){
                    queue.emplace(v);
                }
            }
        }
        for (auto v : e_[u][1]){
            if (dis[v][1] == -1){
                dis[v][1] = dis1 + 1;
                if (dis[v][0] != -1){
                    queue.emplace(v);
                }
            }
        }
    }
    if (dis[1][0] == -1 || dis[1][1] == -1){
        puts("-1");
    }
    else{
        printf("%d\n", std::max(dis[1][0], dis[1][1]));
    }
    for (int i = 1; i <= n; ++ i){
        if (dis[i][0] == -1){
            putchar('0');
        }
        else if (dis[i][1] == -1){
            putchar('1');
        }
        else{
            putchar(dis[i][0] > dis[i][1] ? '0' : '1');
        }
    }
    puts("");
    return 0;
}