#include <bits/stdc++.h>

const int N = 200010;

std::vector<int> e[N];
int dep[N], cnt[2];

void dfs(int u, int fa){
    ++ cnt[dep[u]];
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] ^ 1;
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
    }
    dfs(1, 0);
    printf("%d\n", std::min(cnt[0], cnt[1]) - 1);
    return 0;
}