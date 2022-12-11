#include<bits/stdc++.h>

const int N = 60;
const int moder = (int) 1e9 + 7;
typedef long long ll;

int dp[N];
int inv[N];

void init(){
    inv[1] = 1;
    for (int i = 2; i < N; ++ i){
        inv[i] = moder - 1ll * (moder / i) * inv[moder % i] % moder;
    }
}

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

int calc(ll p, int n, int k){
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;
    for (int i = 0; i < k; ++ i){
        for (int j = 0; j <= n; ++ j){
            for (int k = 0; k < j; ++ k){
                dp[k] = (dp[k] + 1ll * inv[j + 1] * dp[j]) % moder;
            }
            dp[j] = 1ll * dp[j] * inv[j + 1] % moder;
        }
    }
    p %= moder;
    int ans = 0;
    for (int i = 0; i <= n; ++ i){
        ans = (ans + 1ll * powermod(p, i) * dp[i]) % moder;
    }
    return ans;
}

int main(){
    init();
    ll n;
    int k;
    scanf("%lld%d", &n, &k);
    int ans = 1;
    for (int i = 2; 1ll * i * i <= n; ++ i){
        if (n % i == 0){
            int cnt = 0;
            while (n % i == 0){
                n /= i;
                ++ cnt;
            }
            ans = 1ll * ans * calc(i, cnt, k) % moder;
        }
    }
    if (n > 1){
        ans = 1ll * ans * calc(n, 1, k) % moder;
    }
    printf("%d\n", ans);
    return 0;
}