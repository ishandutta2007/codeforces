#include <bits/stdc++.h>

const int N = 18;

int a[1 << N];
int dp[2][N][N];
bool vis[1 << N];

void update(int &u, int v, int w){
    if (v == -1){
        return;
    }
    u = std::max(u, v + w);
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++ i){
        scanf("%d", &a[i]);
        -- a[i];
        vis[a[i]] = true;
    }
    std::sort(a, a + k);
    if (k == 0){
        puts("0");
        return 0;
    }
    int cur = 0;
    memset(dp, -1, sizeof(dp));
    dp[cur][1][1] = 0;
    for (int i = 0; i < k; ++ i){
        memset(dp[cur ^ 1], -1, sizeof(dp[cur]));
        int bit = -1;
        if (i == 0){
            bit = 1;
        }
        else{
            for (int v = n - 1; v >= 0; -- v){
                if ((a[i] >> v & 1) != (a[i - 1] >> v & 1)){
                    bit = v;
                    break;
                }
            }
            bit = n - 1 - bit;
            bit += 2;
        }
        for (int j = 0; j < N; ++ j){
            for (int u = 0; u < N; ++ u){
                update(dp[cur ^ 1][n][std::min(u, bit)], dp[cur][j][u], n - std::min(j, bit));
                update(dp[cur ^ 1][std::min(j, bit)][n], dp[cur][j][u], 2 * (n - std::min(u, bit)));
            }
        }
        cur ^= 1;
    }
    int ans = -1;
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            ans = std::max(ans, dp[cur][i][j]);
        }
    }
    ++ ans;
    for (int i = 0; i < 1 << n; i += 2){
        if (vis[i] || vis[i + 1]){
            ++ ans;
        }
    }
    printf("%d\n", ans);
}