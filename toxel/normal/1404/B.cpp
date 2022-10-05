#include <bits/stdc++.h>

const int N = 100010;

std::vector<int> e[N];
int dis[N];

void dfs(int u, int fa){
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}

void solve(){
    int n, a, b, da, db;
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    for (int i = 1; i <= n; ++ i){
        e[i].clear();
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if (2 * da >= db){
        puts("Alice");
        return;
    }
    dis[b] = 0;
    dfs(b, 0);
    if (dis[a] <= da){
        puts("Alice");
        return;
    }
    int max = std::max_element(dis + 1, dis + n + 1) - dis;
    dis[max] = 0;
    dfs(max, 0);
    max = *std::max_element(dis + 1, dis + n + 1);
    puts(max >= 2 * da + 1 ? "Bob" : "Alice");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}