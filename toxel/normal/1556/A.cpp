#include <bits/stdc++.h>

void solve(){
    int c, d;
    scanf("%d%d", &c, &d);
    if ((c + d) % 2 == 1){
        puts("-1");
        return;
    }
    if (c == 0 && d == 0){
        puts("0");
        return;
    }
    if (c == d || c + d == 0){
        puts("1");
        return;
    }
    puts("2");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}