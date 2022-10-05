#include <bits/stdc++.h>

const int BIT = 40;
using ll = long long;

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        ll u, v;
        scanf("%lld%lld", &u, &v);
        if (u > v){
            puts("NO");
            continue;
        }
        bool flag = true;
        for (int i = 1; i < BIT; ++ i){
            ll x = u & ((1ll << i) - 1);
            ll y = v & ((1ll << i) - 1);
            if (__builtin_popcountll(x) < __builtin_popcountll(y)){
                puts("NO");
                flag = false;
                break;
            }
        }
        if (flag){
            puts("YES");
        }
    }
    return 0;
}