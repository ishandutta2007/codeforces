#include <bits/stdc++.h>

const int N = 100010;

std::vector <int> e[N];
int dp[N][3], dp1[N][3];
// 0: not choose, 1: choose, 2: end

void update(int &a, int b, int c){
    if (b == -1){
        return;
    }
    a = std::max(a, b + c);
}

void dfs(int u, int fa){
    std::vector <int> to_dp;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        to_dp.emplace_back(v);
    }
    int sz = to_dp.size();
    memset(dp1, -1, sizeof(dp1[0]) * (sz + 1));
    dp1[0][0] = 0;
    for (int i = 0; i < sz; ++ i){
        int v = to_dp[i];
        memcpy(dp1[i + 1], dp1[i], sizeof(dp1[i]));
        for (int j = 0; j < 2; ++ j){
            if (dp[v][1] != -1){
                update(dp1[i + 1][j + 1], dp1[i][j], dp[v][1]);
            }
        }
    }
    dp[u][0] = dp1[sz][1];
    dp[u][2] = dp1[sz][2] + 1;
    memset(dp1, -1, sizeof(dp1[0]) * (sz + 1));
    dp1[0][0] = sz;
    for (int i = 0; i < sz; ++ i){
        int v = to_dp[i];
        memcpy(dp1[i + 1], dp1[i], sizeof(dp1[i]));
        for (int j = 0; j < 2; ++ j){
            if (dp[v][1] != -1){
                update(dp1[i + 1][j + 1], dp1[i][j], dp[v][1] - 1);
            }
            if (dp[v][0] != -1){
                update(dp1[i + 1][j + 1], dp1[i][j], dp[v][0]);
            }
        }
    }
    dp[u][1] = std::max(dp1[sz][0], dp1[sz][1]);
    dp[u][2] = std::max(dp[u][2], dp1[sz][2] + (fa != 0));
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    memset(dp, -1, sizeof(dp));
    int rt = 1;
    dfs(rt, 0);
    int ans = -1;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < 3; ++ j){
            ans = std::max(ans, dp[i][j] + (j != 2 && i != rt));
        }
    }
    printf("%d\n", ans);
    return 0;
}