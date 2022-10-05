#include<bits/stdc++.h>

const int N = 250010;

std::vector <int> e[N];
int dep[N], fa[N], notleaf[N];
bool vis[N];

void dfs(int u, int fa){
    vis[u] = true;
    ::fa[u] = fa;
    for (auto v : e[u]){
        if (vis[v]) continue;
        dep[v] = dep[u] + 1;
        notleaf[u] = true;
        dfs(v, u);
    }
}

std::vector <int> getloop(int u, int v){
    std::vector <int> loop1, loop2;
    if (dep[u] < dep[v]){
        std::swap(u, v);
    }
    while (dep[u] > dep[v]){
        loop1.push_back(u);
        u = fa[u];
    }
    while (u != v){
        loop1.push_back(u);
        loop2.push_back(v);
        u = fa[u], v = fa[v];
    }
    loop1.push_back(u);
    for (int i = (int) loop2.size() - 1; i >= 0; -- i){
        loop1.push_back(loop2[i]);
    }
    return loop1;
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        if (dep[i] + 1 == (n + k - 1) / k){
            puts("PATH");
            printf("%d\n", (n + k - 1) / k);
            int u = i;
            while (u){
                printf("%d ", u);
                u = fa[u];
            }
            puts("");
            exit(0);
        }
    }
    std::vector <std::vector <int>> ans;
    for (int i = 1; i <= n; ++ i){
        if (notleaf[i]) continue;
        std::vector <int> vec = getloop(e[i][0], e[i][1]);
        if (vec.size() % 3 != 2){
            vec.push_back(i);
            ans.push_back(vec);
        }
        else{
            vec = getloop(e[i][0], e[i][2]);
            if (vec.size() % 3 != 2){
                vec.push_back(i);
                ans.push_back(vec);
            }
            else{
                vec = getloop(e[i][1], e[i][2]);
                vec.push_back(i);
                ans.push_back(vec);
            }
        }
    }
    puts("CYCLES");
    for (int i = 0; i < k; ++ i){
        printf("%d\n", (int) ans[i].size());
        std::reverse(ans[i].begin(), ans[i].end());
        for (auto u : ans[i]){
            printf("%d ", u);
        }
        puts("");
    }
    return 0;
}