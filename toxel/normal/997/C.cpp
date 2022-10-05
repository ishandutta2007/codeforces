#include<bits/stdc++.h>

typedef long long ll;
const ll moder = 998244353;
const ll N = 1000010;

ll powermod(ll a, ll exp){
    ll ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * a * ret % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

ll fac[N], inv[N];

ll comb(ll a, ll b){
    return 1ll * fac[a] * inv[b] % moder * inv[a - b] % moder;
}

int main(){
    fac[0] = 1;
    for (ll i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
    }
    inv[N - 1] = powermod(fac[N - 1], moder - 2);
    for (ll i = N - 1; i; -- i){
        inv[i - 1] = 1ll * inv[i] * i % moder;
    }
    ll n;
    scanf("%lld", &n);
    if (n == 1){
        puts("3");
        return 0;
    }
    ll ret = 0;
    for (ll i = 1; i <= n; ++ i){
        ll sum = (i & 1 ? -1ll : 1ll) * comb(n, i) % moder;
        sum += sum < 0 ? moder : 0;
        ll x = powermod(3, n - i);
        sum = (n & 1 ? -1ll : 1ll) * sum * (powermod(moder - x + 1, n) - powermod(moder - x, n)) % moder;
        sum += sum < 0 ? moder : 0;
        ret += sum;
        ret -= ret >= moder ? moder : 0;
    }
    ret = 3ll * ret % moder;
    ret -= ret >= moder ? moder : 0;
    for (ll i = 1; i <= n; ++ i){
        ret = (ret + (i & 1 ? -2ll : 2ll) * comb(n, i) * powermod(3, 1ll * n * (n - i) + i)) % moder;
    }
    ret = -ret;
    ret += ret < 0 ? moder : 0;
    printf("%lld\n", ret);
    return 0;
}