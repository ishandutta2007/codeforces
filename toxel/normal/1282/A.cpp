#include <bits/stdc++.h>

void solve(){
    int a, b, c, r;
    scanf("%d%d%d%d", &a, &b, &c, &r);
    if (a > b){
        std::swap(a, b);
    }
    int ll = std::max(a, c - r), rr = std::min(b, c + r);
    int len = std::max(0, rr - ll);
    printf("%d\n", b - a - len);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}