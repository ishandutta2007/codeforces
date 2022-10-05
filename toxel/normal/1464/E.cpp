#include <bits/stdc++.h>

const int N = 100010;
const int M = 512;
const int moder = 998244353;

void submult(int &a, int b, int c){
    a = (a - 1ll * b * c) % moder;
    a += a < 0 ? moder : 0;
}

int powermod(int a, int exp) {
    int ret = 1;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) {
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

std::vector<int> e[N];
int sg[N];
bool vis[N];
std::vector<int> topo;
int mat[M][M], inv[M][M];
int cnt[N];

void dfs(int u){
    vis[u] = true;
    for (auto v : e[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
    topo.emplace_back(u);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
    }
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            dfs(i);
        }
    }
    for (auto u : topo){
        std::set <int> set;
        for (auto v : e[u]){
            set.insert(sg[v]);
        }
        for (int i = 0; ; ++ i){
            if (!set.count(i)){
                sg[u] = i;
                break;
            }
        }
        ++ cnt[sg[u]];
    }
    for (int i = 0; i < M; ++ i){
        for (int j = 0; j < M; ++ j){
            mat[i][i ^ j] = 1ll * cnt[j] * powermod(n + 1, moder - 2) % moder;
        }
    }
    for (int i = 0; i < M; ++ i){
        for (int j = 0; j < M; ++ j){
            mat[i][j] = ((i == j ? 1 : 0) + moder - mat[i][j]) % moder;
        }
    }
    for (int i = 0; i < M; ++ i){
        inv[i][i] = 1;
    }
    for (int i = 0; i < M; ++ i){
        for (int j = i; j < M; ++ j){
            if (mat[j][i]){
                for (int k = 0; k < M; ++ k){
                    std::swap(mat[i][k], mat[j][k]);
                    std::swap(inv[i][k], inv[j][k]);
                }
                break;
            }
        }
        assert(mat[i][i] > 0);
        int rev = powermod(mat[i][i], moder - 2);
        for (int k = 0; k < M; ++ k){
            mat[i][k] = 1ll * mat[i][k] * rev % moder;
            inv[i][k] = 1ll * inv[i][k] * rev % moder;
        }
        for (int j = 0; j < M; ++ j){
            if (i == j){
                continue;
            }
            int coe = mat[j][i];
            for (int k = 0; k < M; ++ k){
                submult(mat[j][k], coe, mat[i][k]);
                submult(inv[j][k], coe, inv[i][k]);
            }
        }
    }
    int ans = inv[0][0];
    ans = 1ll * powermod(n + 1, moder - 2) * ans % moder;
    ans = (moder + 1 - ans) % moder;
    printf("%d\n", ans);
    return 0;
}