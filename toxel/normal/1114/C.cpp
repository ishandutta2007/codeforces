#include<bits/stdc++.h>

typedef long long ll;

ll calc(ll n, ll p){
    ll ret = 0;
    while (n){
        ret += n / p;
        n /= p;
    }
    return ret;
}

int main(){
    ll n, d;
    scanf("%lld%lld", &n, &d);
    ll ans = LLONG_MAX;
    for (int i = 2; 1ll * i * i <= d; ++ i){
        if (d % i == 0){
            int cnt = 0;
            while (d % i == 0){
                d /= i;
                ++ cnt;
            }
            ans = std::min(ans, calc(n, i) / cnt);
        }
    }
    if (d > 1){
        ans = std::min(ans, calc(n, d));
    }
    printf("%lld\n", ans);
    return 0;
}