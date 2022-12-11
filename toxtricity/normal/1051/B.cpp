#include<bits/stdc++.h>

typedef long long ll;

int main(){
    ll l, r;
    scanf("%lld%lld", &l, &r);
    puts("YES");
    for (ll i = l; i <= r; i += 2){
        printf("%lld %lld\n", i, i + 1);
    }
    return 0;
}