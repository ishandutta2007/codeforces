#include<bits/stdc++.h>

const int BIT = 45;
typedef long long ll;

int main(){
    ll s, x;
    scanf("%lld%lld", &s, &x);
    bool carry = 0;
    ll ans = 1;
    for (int i = 0; i < BIT; ++ i){
        bool hascarry = (s >> (i + 1) & 1) != (x >> (i + 1) & 1);
        if (hascarry && !carry && (x >> i & 1)){
            puts("0");
            return 0;
        }
        if (!hascarry && carry && (x >> i & 1)){
            puts("0");
            return 0;
        }
        if ((carry ^ (s >> i & 1)) != (x >> i & 1)){
            puts("0");
            return 0;
        }
        if (x >> i & 1){
            ans <<= 1;
        }
        carry = hascarry;
    }
    if (s == x){
        ans -= 2;
    }
    printf("%lld\n", ans);
    return 0;
}