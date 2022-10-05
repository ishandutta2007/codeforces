#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll p, q;
    scanf("%lld%lld", &p, &q);
    if (p % q){
        printf("%lld\n", p);
        return;
    }
    using pii = std::pair <ll, ll>;
    std::vector<pii> prime;
    for (int i = 2; i * i <= q; ++ i){
        if (q % i == 0){
            ll cnt = 1;
            while (q % i == 0){
                cnt *= i;
                q /= i;
            }
            prime.emplace_back(i, cnt);
        }
    }
    if (q > 1){
        prime.emplace_back(q, q);
    }
    ll min = LLONG_MAX;
    for (auto pair : prime){
        ll pp = p, cnt = 1;
        while (pp % pair.second == 0){
            pp /= pair.first;
            cnt *= pair.first;
        }
        min = std::min(min, cnt);
    }
    printf("%lld\n", p / min);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}