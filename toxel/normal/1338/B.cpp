#include <bits/stdc++.h>

const int N = 100010;

int deg[N], dep[N];
std::vector <int> e[N];

void dfs(int u, int fa){
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        ++ deg[u], ++ deg[v];
    }
    int max = n - 1;
    for (int i = 1; i <= n; ++ i){
        int cnt = 0;
        for (auto u : e[i]){
            cnt += deg[u] == 1;
        }
        if (cnt > 1){
            max -= cnt - 1;
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (deg[i] == 1){
            dfs(i, 0);
            break;
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (deg[i] == 1 && dep[i] % 2 == 1){
            printf("3 %d\n", max);
            return 0;
        }
    }
    printf("1 %d\n", max);
    return 0;
}