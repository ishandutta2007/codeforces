#include<bits/stdc++.h>

const int N = 200010;
const int moder = (int) 1e9 + 7;

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

typedef std::pair <int, int> pii;

int fac[N], inv[N];
int dp[N];
pii p[N];

int comb(int n, int m){
    if (n < m || m < 0) return 0;
    return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

int main(){
    fac[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * i * fac[i - 1] % moder;
    }
    inv[N - 1] = powermod(fac[N - 1], moder - 2);
    for (int i = N - 1; i; -- i){
        inv[i - 1] = 1ll * i * inv[i] % moder;
    }
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 0, x, y; i < n; ++ i){
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }
    p[n] = {h, w};
    std::sort(p, p + n + 1);
    for (int i = 0; i <= n; ++ i){
        dp[i] = comb(p[i].first + p[i].second - 2, p[i].first - 1);
        for (int j = 0; j < i; ++ j){
            dp[i] = (dp[i] - 1ll * dp[j] * comb(p[i].first + p[i].second - p[j].first - p[j].second, p[i].first - p[j].first)) % moder;
        }
        dp[i] += dp[i] < 0 ? moder : 0;
    }
    printf("%d\n", dp[n]);
    return 0;
}