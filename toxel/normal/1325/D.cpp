#include <bits/stdc++.h>

using ll = long long;

int main(){
    ll u, v;
    scanf("%lld%lld", &u, &v);
    if (u > v){
        puts("-1");
        return 0;
    }
    if (u % 2 != v % 2){
        puts("-1");
        return 0;
    }
    if (u == v){
        if (u == 0){
            puts("0");
            return 0;
        }
        printf("1\n%lld\n", u);
        return 0;
    }
    ll retx = 0, rety = 0;
    ll uu = u, vv = v;
    for (int i = 0; i <= 60; ++ i){
        if ((uu >> (i + 1) & 1) != (vv >> (i + 1) & 1)){
            if ((uu >> i & 1) != 0){
                retx = -1;
                break;
            }
            retx |= 1ll << i;
            rety |= 1ll << i;
            uu = u ^ retx ^ rety;
            vv = v - retx - rety;
        }
        else{
            if (uu >> i & 1){
                retx |= 1ll << i;
            }
        }
    }
    if (retx != -1){
        printf("2\n%lld %lld\n", retx, rety);
        assert((retx ^ rety) == u);
        assert(retx + rety == v);
        return 0;
    }
    printf("3\n%lld %lld %lld\n", u, (v - u) / 2, (v - u) / 2);
    return 0;
}