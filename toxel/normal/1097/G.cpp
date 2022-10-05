#include<bits/stdc++.h>

const int N = 100010;
const int M = 210;
const int moder = (int) 1e9 + 7;

int dp[N][M], ans[M], tmp[M];
int fac[M], stir[M][M];
int sz[N];
std::vector <int> e[N];
int n, k;

inline void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}
inline void sub(int &a, int b){a -= b; a += a < 0 ? moder : 0;}

void dfs(int u, int fa){
    sz[u] = 1;
    dp[u][0] = 2;
    for (auto v : e[u]){
        if (v == fa) continue;
        dfs(v, u);
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0, sz1 = std::min(k, sz[u]); i <= sz1; ++ i){
            for (int j = 0, sz2 = std::min(k, sz[v]); j <= sz2; ++ j){
                if (i + j > k){
                    break;
                }
                add(tmp[i + j], 1ll * dp[u][i] * dp[v][j] % moder);
            }
        }
        sz[u] += sz[v];
        memcpy(dp[u], tmp, sizeof(tmp));
    }
    if (fa != 0){
        sub(dp[u][0], 1);
        for (int i = 0; i < k; ++ i){
            sub(ans[i + 1], dp[u][i]);
        }
        for (int i = k; i; -- i){
            add(dp[u][i], dp[u][i - 1]);
        }
        add(dp[u][0], 1);
    }
}

void init(){
    fac[0] = 1;
    for (int i = 1; i < M; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
    }
    stir[0][0] = 1;
    for (int i = 1; i < M; ++ i){
        for (int j = 1; j <= i; ++ j){
            add(stir[i][j], stir[i - 1][j - 1]);
            add(stir[i][j], 1ll * stir[i - 1][j] * j % moder);
        }
    }
}

int main(){
    init();
    scanf("%d%d", &n, &k);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int ret = 0;
    for (int i = 1; i <= k; ++ i){
        add(ans[i], dp[1][i] % moder);
        add(ret, 1ll * stir[k][i] * fac[i] % moder * ans[i] % moder);
    }
    printf("%d\n", ret);
    return 0;
}