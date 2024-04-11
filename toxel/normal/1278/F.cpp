#include <bits/stdc++.h>

const int N = 5010;
const int moder = 998244353;

int s[N][N];

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

int main(){
    s[0][0] = 1;
    for (int i = 1; i < N; ++ i){
        for (int j = 1; j <= i; ++ j){
            s[i][j] = (1ll * j * s[i - 1][j] + s[i - 1][j - 1]) % moder;
        }
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (m == 1){
        printf("%d\n", powermod(n, k));
        return 0;
    }
    int coe = powermod(1ll * (m - 1) * powermod(m, moder - 2) % moder, n);
    int x = powermod(m - 1, moder - 2);
    int ans = 0;
    int coe1 = 1;
    for (int i = 0; i <= k; ++ i){
        int sum = 1ll * powermod(x + 1, n - i) * powermod(x, i) % moder * s[k][i] % moder * coe1 % moder;
        coe1 = 1ll * (n - i) * coe1 % moder;
        ans = (ans + 1ll * coe * sum) % moder;
    }
    printf("%d\n", ans);
    return 0;
}