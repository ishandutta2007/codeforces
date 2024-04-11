#include <bits/stdc++.h>

const int N = 500010;
const int moder = 998244353;

std::vector <int> e[N];
int dp[N][2], sz[N], power[N];
int n;
int ans;

void dfs(int u, int fa){
    dp[u][0] = dp[u][1] = 1;
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
        int x = dp[v][0] + dp[v][1];
        dp[u][0] = dp[u][0] * (0ll + dp[v][1] + x) % moder;
        dp[u][1] = 2ll * dp[u][1] * x % moder;
    }
    dp[u][1] -= dp[u][0];
    dp[u][1] += dp[u][1] < 0 ? moder : 0;
    ans = (ans + 1ll * dp[u][1] * power[n - sz[u]]) % moder;
}

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = power[i - 1] << 1;
        power[i] -= power[i] >= moder ? moder : 0;
    }
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    ans <<= 1;
    ans -= ans >= moder ? moder : 0;
    printf("%d\n", ans);
    return 0;
}