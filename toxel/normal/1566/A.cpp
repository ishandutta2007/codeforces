#include <bits/stdc++.h>

void solve(){
    int n, s;
    scanf("%d%d", &n, &s);
    /*if (n == 1){
        printf("%d\n", s);
        return;
    }*/
    printf("%d\n", s / (n / 2 + 1));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}