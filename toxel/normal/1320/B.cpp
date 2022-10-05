#include <bits/stdc++.h>

const int N = 200010;

std::vector <int> e[N], _e[N];
int dis[N], a[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        _e[v].emplace_back(u);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++ i){
        scanf("%d", &a[i]);
    }
    int s = a[0], t = a[k - 1];
    memset(dis, -1, sizeof(dis));
    dis[t] = 0;
    std::queue <int> queue;
    queue.emplace(t);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : _e[u]){
            if (dis[v] == -1){
                dis[v] = dis[u] + 1;
                queue.emplace(v);
            }
        }
    }
    int min = 0, max = 0;
    for (int i = 0; i < k - 1; ++ i){
        if (dis[a[i]] != dis[a[i + 1]] + 1){
            ++ min, ++ max;
        }
        else{
            for (auto v : e[a[i]]){
                if (v == a[i + 1]){
                    continue;
                }
                if (dis[a[i]] == dis[v] + 1){
                    ++ max;
                    break;
                }
            }
        }
    }
    printf("%d %d\n", min, max);
    return 0;
}