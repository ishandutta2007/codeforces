#include <bits/stdc++.h>

int num[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt = 0;
    for (auto u : num){
        cnt += u <= b;
    }
    printf("%lld\n", 1ll * a * cnt);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}