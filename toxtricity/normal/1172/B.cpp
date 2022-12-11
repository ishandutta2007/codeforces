#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;

std::vector <int> e[N];
int dp[N];
int n;

void dfs(int u, int fa){
    dp[u] = 1;
    int now = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        dp[u] = 1ll * dp[v] * dp[u] % moder;
        dp[u] = 1ll * dp[u] * now % moder;
        ++ now;
    }
    dp[u] = 1ll * dp[u] * (u == 1 ? n : now) % moder;
}

int main(){
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", dp[1]);
    return 0;
}