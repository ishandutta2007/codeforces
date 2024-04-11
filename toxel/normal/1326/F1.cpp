#include <bits/stdc++.h>

const int N = 15;
using ll = long long;

int pre[N][1 << N], bitcnt[1 << N];
char mat[N][N];
int t[N][N];
std::vector <ll> dp[1 << N][N];

int main(){
    for (int i = 1; i < 1 << N; ++ i){
        bitcnt[i] = bitcnt[i ^ (i & -i)] + 1;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", mat[i]);
        for (int j = 0; j < n; ++ j){
            t[i][j] = mat[i][j] - '0';
        }
    }
    for (int i = 1; i < 1 << n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i >> j & 1){
                dp[i][j].resize(1 << (bitcnt[i] - 1));
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        dp[1 << i][i][0] = 1;
    }
    for (int i = 1; i < 1 << n; ++ i){
        if (bitcnt[i] == 1){
            continue;
        }
        std::vector <int> vec;
        for (int j = 0; j < n; ++ j){
            if (i >> j & 1){
                vec.emplace_back(j);
            }
        }
        for (auto u : vec){
            for (auto v : vec){
                if (u == v){
                    continue;
                }
                int sz = bitcnt[i] - 2;
                for (int k = 0; k < 1 << sz; ++ k){
                    dp[i][u][k | (t[u][v] << sz)] += dp[i ^ 1 << u][v][k];
                }
            }
        }
    }
    for (int i = 0; i < 1 << (n - 1); ++ i){
        ll ans = 0;
        for (int j = 0; j < n; ++ j){
            ans += dp[(1 << n) - 1][j][i];
        }
        printf("%lld%c", ans, " \n"[i == (1 << (n - 1)) - 1]);
    }
    return 0;
}