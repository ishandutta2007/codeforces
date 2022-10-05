#include<bits/stdc++.h>

typedef long long ll;

int main(){
    ll x, y;
    scanf("%lld%lld", &x, &y);
    if (std::__gcd(x, y) > 1){
        puts("Impossible");
        return 0;
    }
    while (x > 1 || y > 1){
        if (x > y){
            ll cnt = x / y - (y == 1);
            printf("%lldA", cnt);
            x %= y;
        }
        else{
            ll cnt = y / x - (x == 1);
            printf("%lldB", cnt);
            y %= x;
        }
    }
    putchar('\n');
    return 0;
}