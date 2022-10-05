#include <bits/stdc++.h>

const int N = 200010;
using pii = std::pair <int, int>;

std::vector <int> e[N];
int dis[N], dis1[N];
int a[N];
int pre[N], suf[N];
pii p[N];

void bfs(int s, int *dis){
    memset(dis, -1, sizeof(int) * N);
    dis[s] = 0;
    std::queue <int> queue;
    queue.emplace(s);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            if (dis[v] == -1){
                dis[v] = dis[u] + 1;
                queue.emplace(v);
            }
        }
    }
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    bfs(1, dis);
    bfs(n, dis1);
    for (int i = 1; i <= k; ++ i){
        p[i] = {dis[a[i]] - dis1[a[i]], dis1[a[i]]};
    }
    std::sort(p + 1, p + k + 1);
    for (int i = k; i >= 1; -- i){
        suf[i] = std::max(suf[i + 1], p[i].second);
    }
    int max = 0;
    for (int i = 1; i < k; ++ i){
        max = std::max(max, p[i].first + p[i].second + suf[i + 1] + 1);
    }
    max = std::min(max, dis[n]);
    printf("%d\n", max);
    return 0;
}