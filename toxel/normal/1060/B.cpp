#include<bits/stdc++.h>

typedef long long ll;

int calc(ll n){
    int ret = 0;
    while (n){
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main(){
    ll n;
    scanf("%lld", &n);
    ll now = 0;
    while (true){
        if (now * 10 + 9 > n){
            break;
        }
        now = now * 10 + 9;
    }
    printf("%d\n", calc(now) + calc(n - now));
    return 0;
}