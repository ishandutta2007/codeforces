#include <bits/stdc++.h>

const int N = 210;
const int moder = int(1e9) + 7;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

std::vector <int> e[N];
int dep[N];
int ans = 0;
int dp[N][N];

void dfs(int u, int fa){
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

std::vector <int> solve(int u, int fa){
    std::vector <int> vec = {u};
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        std::vector <int> vec1 = solve(v, u);
        for (auto x : vec){
            for (auto y : vec1){
                if (x > y){
                    add(ans, dp[dep[x] - dep[u]][dep[y] - dep[u]]);
                }
                else{
                    add(ans, dp[dep[y] - dep[u]][dep[x] - dep[u]]);
                }
            }
        }
        for (auto y : vec1){
            vec.emplace_back(y);
        }
    }
    return vec;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    const int inv2 = powermod(2, moder - 2);
    for (int i = 1; i < N; ++ i){
        dp[i][0] = 0;
        dp[0][i] = 1;
    }
    for (int i = 1; i < N; ++ i){
        for (int j = 1; j < N; ++ j){
            dp[i][j] = 1ll * inv2 * (dp[i - 1][j] + dp[i][j - 1]) % moder;
        }
    }
    for (int i = 1; i <= n; ++ i){
        dep[i] = 0;
        dfs(i, 0);
        solve(i, 0);
    }
    ans = 1ll * ans * powermod(n, moder - 2) % moder;
    printf("%d\n", ans);
    return 0;
}