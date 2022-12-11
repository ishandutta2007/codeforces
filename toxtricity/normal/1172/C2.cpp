#include <bits/stdc++.h>

const int N = 200010;
const int M = 3010;
const int moder = 998244353;
const int MAX = 64010;
typedef long long ll;

int dp[2][M], dp1[M];
int a[N], w[N];
int ans[2][MAX];
int premod[2][MAX];
int n, m;
int sum = 0, sump = 0, sumn = 0;

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

int solve(int w, int type){
    int ntype = type == 1 ? 1 : 0;
    if (w < MAX && ans[ntype][w] != -1){
        return ans[ntype][w];
    }
    int ret = 0, exp = w;
    for (int i = 0; i <= m; ++ i){
        int prob = type == 1 ? dp1[i] : dp1[m - i];
        addmult(ret, exp, prob);
        exp = (exp + (ll) type * exp * premod[ntype][i]) % moder;
        exp += exp < 0 ? moder : 0;
    }
    if (w < MAX){
        ans[ntype][w] = ret;
    }
    return ret;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        if (a[i] == 0){
            a[i] = -1;
        }
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &w[i]);
        sum += w[i];
        (a[i] == 1 ? sump : sumn) += w[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int now = 0;
    for (int j = 1; j <= m; ++ j){
        memset(dp[now ^ 1], 0, sizeof(dp[now ^ 1]));
        for (int u = 0; u < M; ++ u){
            if (!dp[now][u]){
                continue;
            }
            int nsum = sum + u - (j - 1 - u);
            nsum = powermod(nsum, moder - 2);
            int nw = sump + u;
            if (nw) {
                addmult(dp[now ^ 1][u + 1], nw, 1ll * dp[now][u] * nsum % moder);
            }
            nw = sumn - (j - 1 - u);
            if (nw) {
                addmult(dp[now ^ 1][u], nw, 1ll * dp[now][u] * nsum % moder);
            }
        }
        now ^= 1;
    }
    memcpy(dp1, dp[now], sizeof(dp1));
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < MAX; ++ i){
        premod[1][i] = powermod(sump + i, moder - 2);
        premod[0][i] = powermod(sumn - i, moder - 2);
    }
    for (int i = 0; i < n; ++ i){
        printf("%d\n", solve(w[i], a[i]));
    }
    return 0;
}