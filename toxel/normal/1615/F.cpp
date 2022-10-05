#include <bits/stdc++.h>

const int N = 2010;
const int moder = int(1e9) + 7;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

void addmult(int &u, int v, int w){
    u = (u + 1ll * v * w) % moder;
}

int dp[N][N * 2], dp1[N][N * 2];
char a[N], b[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; ++ i){
        for (int j = 0; j <= 2 * n + 1; ++ j){
            dp[i][j] = dp1[i][j] = 0;
        }
    }
    scanf("%s%s", a + 1, b + 1);
    dp[0][n] = 1;
    dp1[0][n] = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < 2; ++ j){
            if (a[i] != '?' && a[i] != j + '0'){
                continue;
            }
            for (int k = 0; k < 2; ++ k){
                if (b[i] != '?' && b[i] != k + '0'){
                    continue;
                }
                for (int w = 0; w <= 2 * n; ++ w){
                    int delta = 0;
                    if (j){
                        delta += i % 2 ? 1 : -1;
                    }
                    if (k){
                        delta += i % 2 ? -1 : 1;
                    }
                    int nw = w + delta;
                    int cost = 0;
                    if ((w < n && delta == 1) || (w > n && delta == -1)){
                        cost = i;
                    }
                    else if (delta != 0){
                        cost = moder - i;
                    }
                    add(dp[i][nw], dp[i - 1][w]);
                    addmult(dp1[i][nw], dp[i - 1][w], cost);
                    add(dp1[i][nw], dp1[i - 1][w]);
                }
            }
        }
    }
    printf("%d\n", dp1[n][n]);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}