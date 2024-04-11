#include <bits/stdc++.h>

int moder;
typedef long long ll;

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

int main(){
    std::map <int, int> map, map1;
    int n, k;
    scanf("%d%d%d", &n, &moder, &k);
    for (int i = 0; i < n; ++ i){
        int a;
        scanf("%d", &a);
        ++ map[a];
        int x = (powermod(a, 4) - 1ll * k * a) % moder;
        x += x < 0 ? moder : 0;
        ++ map1[x];
    }
    ll ans = 0;
    for (auto u : map1){
        ans += 1ll * u.second * (u.second - 1) / 2;
    }
    for (auto u : map){
        int x = 4ll * powermod(u.first, 3) % moder;
        if (x != k){
            ans -= 1ll * u.second * (u.second - 1) / 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}