#include <bits/stdc++.h>

void solve(){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int ans = std::abs(x1 - x2) + std::abs(y1 - y2);
    ans += x1 != x2 && y1 != y2 ? 2 : 0;
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}