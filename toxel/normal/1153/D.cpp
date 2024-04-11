#include <bits/stdc++.h>

const int N = 300010;

int fa[N], isleaf[N];
int type[N], dp[N];
std::vector <int> e[N];

void dfs(int u){
    if (e[u].size() == 0){
        dp[u] = 1;
        return;
    }
    int sum = 0, min = INT_MAX;
    for (auto v : e[u]){
        dfs(v);
        sum += dp[v];
        min = std::min(dp[v], min);
    }
    dp[u] = type[u] == 0 ? sum : min;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        isleaf[i] = true;
        scanf("%d", &type[i]);
    }
    for (int i = 2; i <= n; ++ i){
        scanf("%d", &fa[i]);
        e[fa[i]].push_back(i);
        isleaf[fa[i]] = false;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        cnt += isleaf[i];
    }
    dfs(1);
    printf("%d\n", cnt - dp[1] + 1);
    return 0;
}