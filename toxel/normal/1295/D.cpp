#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll a, m;
    scanf("%lld%lld", &a, &m);
    ll gcd = std::__gcd(a, m);
    m /= gcd;
    ll ans = 1;
    for (ll i = 2; i * i <= m; ++ i){
        if (m % i == 0){
            bool flag = true;
            while (m % i == 0){
                if (flag){
                    ans *= i - 1;
                    flag = false;
                }
                else{
                    ans *= i;
                }
                m /= i;
            }
        }
    }
    if (m > 1){
        ans *= m - 1;
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}