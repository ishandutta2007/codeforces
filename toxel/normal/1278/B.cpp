#include <bits/stdc++.h>

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    int x = std::abs(a - b), now = 0;
    while (x > 0){
        x -= ++ now;
    }
    while (x % 2 != 0){
        x -= ++ now;
    }
    printf("%d\n", now);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}