#include <bits/stdc++.h>

using ll = long long;
const int N = 43;
const int moder = int(1e9) + 7;

ll lcm[N];

void solve(){
    ll n;
    scanf("%lld", &n);
    int ans = 0;
    for (int i = 1; i < N - 1; ++ i){
        int sum = n / lcm[i] % moder;
        sum -= n / lcm[i + 1] % moder;
        ans = (ans + 1ll * sum * (i + 1)) % moder;
    }
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
}

int main(){
    lcm[1] = 1;
    for (int i = 2; i < N; ++ i){
        lcm[i] = lcm[i - 1] * i / std::gcd(lcm[i - 1], i);
        // printf("%d %lld\n", i, lcm[i]);
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}