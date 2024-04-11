#include<bits/stdc++.h>

typedef long long ll;

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    ll a = 1ll * n * m, b = k;
    ll gcd = std::__gcd(a, b);
    a /= gcd, b /= gcd;
    if (b > 2){
        puts("NO");
        return 0;
    }
    puts("YES");
    if (b == 1){
        a *= 2;
    }
    ll x = std::__gcd((ll) n, a), y = a / x;
    if (x <= n && y <= m){
        printf("0 0\n%lld 0\n0 %lld\n", x, y);
    }
    else{
        y = std::__gcd((ll) m, a);
        x = a / y;
        printf("0 0\n%lld 0\n0 %lld\n", x, y);
    }
    return 0;
}