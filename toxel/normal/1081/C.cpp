#include<bits/stdc++.h>

const int moder = 998244353;
const int N = 2010;

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

int comb[N][N];

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int ans = 1ll * m * powermod(m - 1, k) % moder * comb[n - 1][k] % moder;
    printf("%d\n", ans);
    return 0;
}