#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll a, k;
    scanf("%lld%lld", &a, &k);
    for (ll i = 0; i < k - 1; ++ i){
        ll min = INT_MAX, max = INT_MIN;
        ll x = a;
        while (x > 0){
            min = std::min(min, x % 10);
            max = std::max(max, x % 10);
            x /= 10;
        }
        if (min == 0){
            break;
        }
        a += min * max;
    }
    printf("%lld\n", a);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}