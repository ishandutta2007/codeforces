#include <bits/stdc++.h>

using ll = long long;

void solve(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ll ans = 1ll * (b - a + 1) * (c - b + 1) * (d - c + 1);
    for (int i = a; i <= b; ++ i){
        int lessC = std::max(0, c - i - b);
        ans -= 1ll * lessC * (d - c + 1);
        int left = std::min(d + 1, i + b);
        left = std::max(c, left);
        int right = std::min(i + c, d + 1);
        left = d - left + 1, right = d - right + 1;
        ans -= 1ll * (right + left) * (left - right + 1) / 2;
    }
    printf("%lld\n", ans);
}

int main(){
    solve();
    return 0;
}