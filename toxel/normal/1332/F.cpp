#include <bits/stdc++.h>

const int N = 300010;
const int moder = 998244353;

// in independentset / not in ... / no edge
int dp[N][3];
std::vector <int> e[N];

void add(int &u, int v){u += v; u -= u >= moder ? moder : 0;}
void sub(int &u, int v){u -= v; u += u < 0 ? moder : 0;}
void mult(int &u, int v){u = 1ll * u * v % moder;}

void dfs(int u, int fa){
    dp[u][0] = dp[u][1] = dp[u][2] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        dp[u][0] = dp[u][0] * (dp[v][0] + 2ll * dp[v][1] + 2ll * dp[v][2]) % moder;
        dp[u][1] = dp[u][1] * (2ll * dp[v][0] + 2ll * dp[v][1] + 3ll * dp[v][2]) % moder;
        int sum = 0;
        for (int i = 0; i < 3; ++ i){
            add(sum, dp[v][i]);
        }
        mult(dp[u][2], sum);
    }
    sub(dp[u][0], dp[u][2]);
    sub(dp[u][1], dp[u][2]);
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
    int ans = 0;
    for (int i = 0; i < 3; ++ i){
        add(ans, dp[1][i]);
    }
    sub(ans, 1);
    printf("%d\n", ans);
    return 0;
}