#include <bits/stdc++.h>

const int N = 2010;
const int moder = 998244353;

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) ret = 1ll * ret * a % moder;
        a = 1ll * a * a % moder;
    }
    return ret;
}

void addmult(int &a, int b, int c){a = (a + 1ll * b * c) % moder;}
void submult(int &a, int b, int c){a = (a - 1ll * b * c) % moder;}

int dp[N][N];
int power[N], power1[N];
int strong[N];
int ans[N], ans1[N];

int main(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int prob = 1ll * a * powermod(b, moder - 2) % moder;
    int prob1 = (moder + 1 - prob) % moder;
    power[0] = power1[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 1ll * power[i - 1] * prob % moder;
        power1[i] = 1ll * power1[i - 1] * prob1 % moder;
    }
    dp[0][0] = 1;
    for (int i = 0; i < N - 1; ++ i){
        for (int j = 0; j <= i; ++ j){
            addmult(dp[i + 1][j + 1], dp[i][j], power1[i - j]);
            addmult(dp[i + 1][j], dp[i][j], power[j]);
        }
    }
    for (int i = 1; i < N; ++ i){
        strong[i] = 1;
        for (int j = 1; j < i; ++ j){
            submult(strong[i], strong[j], dp[i][j]);
        }
        strong[i] += strong[i] < 0 ? moder : 0;
    }
    for (int i = 2; i < N; ++ i){
        int tot = i * (i - 1) / 2;
        for (int j = 1; j < i; ++ j){
            addmult(tot, strong[j], 1ll * dp[i][j] * (ans[j] + ans1[i - j]) % moder);
        }
        tot = 1ll * tot * powermod(1 - strong[i], moder - 2) % moder;
        tot += tot < 0 ? moder : 0;
        ans[i] = tot;
        ans1[i] = ans[i] - i * (i - 1) / 2;
        ans1[i] += ans1[i] < 0 ? moder : 0;
    }
    printf("%d\n", ans[n]);
    return 0;
}