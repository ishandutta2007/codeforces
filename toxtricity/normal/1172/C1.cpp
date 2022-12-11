#include <bits/stdc++.h>

const int N = 110;
const int moder = 998244353;

int dp[2][N][N];
int a[N], w[N];

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

void addmult(int &a, int b, int c){
    a = (a + 1ll * b * c) % moder;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        if (a[i] == 0){
            a[i] = -1;
        }
    }
    int sum = 0, sump = 0, sumn = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &w[i]);
        sum += w[i];
        (a[i] == 1 ? sump : sumn) += w[i];
    }
    for (int i = 0; i < n; ++ i){
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        int now = 0, ans = 0;
        (a[i] == 1 ? sump : sumn) -= w[i];
        for (int j = 1; j <= m; ++ j){
            memset(dp[now ^ 1], 0, sizeof(dp[now ^ 1]));
            for (int u = 0; u < N; ++ u){
                for (int v = 0; v < N; ++ v){
                    if (!dp[now][u][v]){
                        continue;
                    }
                    int nsum = sum + a[i] * u + v - (j - 1 - u - v);
                    nsum = powermod(nsum, moder - 2);
                    int nw = w[i] + a[i] * u;
                    if (nw) {
                        addmult(dp[now ^ 1][u + 1][v], nw, 1ll * dp[now][u][v] * nsum % moder);
                        addmult(ans, nw, 1ll * dp[now][u][v] * nsum % moder);
                    }
                    nw = sump + v;
                    if (nw) {
                        addmult(dp[now ^ 1][u][v + 1], nw, 1ll * dp[now][u][v] * nsum % moder);
                    }
                    nw = sumn - (j - 1 - u - v);
                    if (nw) {
                        addmult(dp[now ^ 1][u][v], nw, 1ll * dp[now][u][v] * nsum % moder);
                    }
                }
            }
            now ^= 1;
        }
        (a[i] == 1 ? sump : sumn) += w[i];
        ans = (w[i] + ans * a[i]) % moder;
        ans += ans < 0 ? moder : 0;
        printf("%d\n", ans);
    }
    return 0;
}