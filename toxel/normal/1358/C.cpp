#include <bits/stdc++.h>

void solve(){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int diffx = x2 - x1, diffy = y2 - y1;
    int x = std::min(diffx, diffy);
    long long ans = 1ll * x * x + 1ll * x * std::abs(diffx - diffy) + 1;
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}