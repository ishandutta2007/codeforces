#include<bits/stdc++.h>

typedef long long ll;

int main(){
    ll n, m;
    int a, b;
    scanf("%lld%lld%d%d", &n, &m, &a, &b);
    if (n % m == 0){
        puts("0");
        return 0;
    }
    printf("%lld\n", std::min(n % m * b, (m - n % m) * a));
    return 0;
}