#include <bits/stdc++.h>

const int N = 6000010;
const int moder = int(1e9) + 7;
int fac[N], inv[N], invf[N];
int dp[N][3];

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

void sub(int &u, int v){
    u -= v;
    u += u < 0 ? moder : 0;
}

int comb(int n, int m){
    if (n < m || m < 0){
        return 0;
    }
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int n, test;
    scanf("%d%d", &n, &test);
    for (int i = 0; i < 3; ++ i){
        for (int j = 3; j <= 3 * n; j += 3){
            add(dp[1][i], comb(j - i, 1));
        }
    }
    for (int i = 2; i <= 3 * n; ++ i){
        int total = comb(3 * n, i + 1);
        add(total, comb(3 * n, i));
        int c0 = dp[i - 1][1];
        int c1 = dp[i - 1][2];
        int c2 = dp[i - 1][0];
        sub(c2, comb(3 * n, i));
        sub(c2, comb(3 * n, i - 1));
        dp[i][0] = (2ll * c0 + c1 + total) * inv[3] % moder;
        dp[i][1] = (2ll * c1 + c2 + total) * inv[3] % moder;
        dp[i][2] = (2ll * c2 + c0 + total) * inv[3] % moder;
    }
    while (test --){
        int x;
        scanf("%d", &x);
        printf("%d\n", dp[x][0]);
    }
    return 0;
}