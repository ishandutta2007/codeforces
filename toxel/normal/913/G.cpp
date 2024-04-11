#include <bits/stdc++.h>

using ll = long long;
const int BIT = 18;
const ll mod1 = 3'814'697'265'625; // 5^18
const ll phi = mod1 / 5 * 4;
const ll mod2 = 1 << 18;
const ll mod3 = 78'125; // 5 ^ 7
const ll mod4 = 1 << 7;

ll powermod(ll a, ll exp, ll mod){
    ll ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1) ret = __int128(ret) * a % mod;
        a = __int128(a) * a % mod;
    }
    return ret;
}

void solve(){
    ll n;
    scanf("%lld", &n);
    n *= mod3 * mod4;
    n += (mod2 - n % mod2);
    if (n % 5 == 0){
        n += mod2;
    }
    n %= mod1;
    ll cur_mod = 1, cur_phi = 1, cur_ans = 0;
    for (int i = 0; i < BIT; ++ i){
        cur_mod *= 5;
        int to_try = i == 0 ? 4 : 5;
        for (int j = 0; j < to_try; ++ j){
            if (powermod(2, cur_phi * j + cur_ans, cur_mod) == n % cur_mod){
                cur_ans = cur_phi * j + cur_ans;
                break;
            }
        }
        cur_phi *= to_try;
    }
    cur_ans += phi;
    printf("%lld\n", cur_ans);
    // printf("%lld\n", powermod(2, cur_ans, mod1 * mod2));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}