#include <bits/stdc++.h>

using ll = long long;

int main(){
    ll x;
    scanf("%lld", &x);
    if (x == 1){
        puts("1 1");
        return 0;
    }
    int max = 0;
    for (int i = 1; 1ll * i * i < x; ++ i){
        if (i >= x / i){
            break;
        }
        if (x % i == 0 && std::__gcd(ll(i), x / i) == 1){
            max = std::max(max, i);
        }
    }
    printf("%d %lld\n", max, x / max);
    return 0;
}