#include <bits/stdc++.h>

const int N = 100010;

std::vector<int> e[N];
int sz[N], max[N], fafa[N];
int n;

void dfs(int u, int fa){
    fafa[u] = fa;
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void calc(int u, int fa){
    max[u] = n - sz[u];
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        calc(v, u);
        max[u] = std::max(max[u], sz[v]);
    }
}

void solve(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        e[i].clear();
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    calc(1, 0);
    for (int i = 1; i <= n; ++ i){
        fafa[i] = 0;
    }
    int min = *std::min_element(max + 1, max + 1 + n);
    std::vector<int> pos;
    for (int i = 1; i <= n; ++ i){
        if (max[i] == min){
            pos.emplace_back(i);
        }
    }
    if (pos.size() == 1){
        printf("%d %d\n%d %d\n", 1, e[1].front(), 1, e[1].front());
        return;
    }
    dfs(pos[0], pos[1]);
    for (int i = 1; i <= n; ++ i){
        if (e[i].size() == 1 && fafa[i]){
            printf("%d %d\n%d %d\n", i, fafa[i], i, pos[1]);
            break;
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}