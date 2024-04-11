#include <bits/stdc++.h>

const int N = 110;
const int M = 30;
const int moder = (int) 1e9 + 7;

int dp[N][M][M], sz[N], tmp[M][M];
int n, k;
std::vector <int> e[N];

inline void addmult(int &a, int b, int c){a = (a + 1ll * b * c) % moder;}
inline void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}
inline void sub(int &a, int b){a -= b; a += a < 0 ? moder : 0;}

void dfs(int u, int fa){
    sz[u] = 1;
    dp[u][0][0] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i <= k && i <= sz[u]; ++ i){
            for (int j = 0; j <= k && j <= sz[v]; ++ j){
                for (int a = 0; a <= k && a <= sz[u]; ++ a){
                    if (dp[u][i][a] == 0 || (j > 0 && a > 0 && j + a <= k)){
                        continue;
                    }
                    for (int b = 0; b <= k && b <= sz[v]; ++ b){
                        if (dp[v][j][b] == 0 || (i > 0 && b > 0 && i + b <= k)){
                            continue;
                        }
                        int ni = i == 0 ? j : j == 0 ? i : std::min(i, j);
                        int nj = a == 0 ? b : b == 0 ? a : std::min(a, b);
                        addmult(tmp[ni][nj], dp[u][i][a], dp[v][j][b]);
                    }
                }
            }
        }
        memcpy(dp[u], tmp, sizeof(tmp));
        sz[u] += sz[v];
    }
    memset(tmp, 0, sizeof(tmp));
    // illegal
    for (int j = 0; j <= k; ++ j){
        sub(tmp[0][1], dp[u][0][j]);
    }
    // black
    for (int i = 0; i <= k; ++ i){
        add(tmp[1][0], dp[u][i][0]);
    }
    // nothing
    for (int i = 0; i <= k; ++ i){
        for (int j = 0; j <= k; ++ j){
            int ni = i == 0 || i == k ? 0 : i + 1;
            int nj = j == 0 || j == k ? 0 : j + 1;
            add(tmp[ni][nj], dp[u][i][j]);
        }
    }
    memcpy(dp[u], tmp, sizeof(tmp));
}

int main(){
    srand((unsigned) time(nullptr));
    scanf("%d%d", &n, &k);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int root = rand() % n + 1;
    dfs(root, 0);
    int sum = 0;
    for (int i = 0; i <= k; ++ i){
        for (int j = 0; j <= k; ++ j){
            add(sum, dp[root][i][j]);
        }
    }
    printf("%d\n", sum);
    return 0;
}