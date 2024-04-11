#include<bits/stdc++.h>

const int N = 300010;
const int moder = 998244353;
typedef long long ll;

std::vector <int> e[N];
int dp[N][2][2];


void dfs(int u, int fa){
    dp[u][1][0] = 1;
    int prod1 = 1, prod2 = 1;
    std::vector <int> son;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        son.push_back(v);
        dfs(v, u);
        dp[u][1][0] = 1ll * dp[u][1][0] * (dp[v][1][0] + dp[v][0][1]) % moder;
        prod1 = (2ll * dp[v][0][1] + dp[v][1][0]) * prod1 % moder;
        prod2 = (1ll * dp[v][0][1] + dp[v][1][0]) * prod2 % moder;
    }
    dp[u][0][0] = prod1 - prod2;
    dp[u][0][0] += dp[u][0][0] < 0 ? moder : 0;
    if (son.empty()){
        dp[u][1][0] = 1;
        return;
    }
    int n = son.size();
    std::vector <int> pre(n), suf(n);
    for (int i = 0; i < n; ++ i){
        pre[i] = (i ? (ll) pre[i - 1] : 1ll) * (2ll * dp[son[i]][0][1] + dp[son[i]][1][0]) % moder;
    }
    for (int i = n - 1; i >= 0; -- i){
        suf[i] = (i == n - 1 ? 1ll : (ll) suf[i + 1]) * (2ll * dp[son[i]][0][1] + dp[son[i]][1][0]) % moder;
    }
    for (int i = 0; i < n; ++ i){
        dp[u][0][1] = (dp[u][0][1] + 1ll * (dp[son[i]][1][0] + dp[son[i]][0][0]) * (i ? pre[i - 1] : 1) % moder * (i == n - 1 ? 1 : suf[i + 1])) % moder;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", (dp[1][0][1] + dp[1][1][0]) % moder);
    return 0;
}