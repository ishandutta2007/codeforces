#include <bits/stdc++.h>

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    int x = n * m;
    x = (x + 1) / 2;
    printf("%d\n", x);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}