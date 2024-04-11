#include <bits/stdc++.h>

typedef long long ll;

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ll ans = 2 * c;
    int x = std::min(a, b);
    ans += 2 * x;
    a -= x, b -= x;
    ans += std::min(a, 1) + std::min(b, 1);
    printf("%lld\n", ans);
    return 0;
}