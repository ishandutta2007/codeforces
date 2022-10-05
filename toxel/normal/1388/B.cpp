#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    int x = (n + 3) / 4;
    for (int i = 0; i < n - x; ++ i){
        putchar('9');
    }
    for (int i = 0; i < x; ++ i){
        putchar('8');
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}