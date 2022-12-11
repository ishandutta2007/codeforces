#include<bits/stdc++.h>

typedef long long ll;

int main(){
    ll a, b, x, y;
    scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
    ll gcd = std::__gcd(x, y);
    x /= gcd, y /= gcd;
    printf("%lld\n", std::min(a / x, b / y));
    return 0;
}