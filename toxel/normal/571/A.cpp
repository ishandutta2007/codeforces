#include<bits/stdc++.h>

typedef long long ll;

int main(){
    int a, b, c, l;
    scanf("%d%d%d%d", &a, &b, &c, &l);
    ll ans = 1ll * (l + 3) * (l + 2) * (l + 1) / 6;
    for (int i = 0; i <= l; ++ i){
        int x = std::max(std::min(a + i - b - c, l - i), -1);
        ans -= 1ll * (x + 2) * (x + 1) / 2;
        x = std::max(std::min(b + i - a - c, l - i), -1);
        ans -= 1ll * (x + 2) * (x + 1) / 2;
        x = std::max(std::min(c + i - b - a, l - i), -1);
        ans -= 1ll * (x + 2) * (x + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}