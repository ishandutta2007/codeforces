#include <bits/stdc++.h>

void solve(){
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &y, &a, &b);
    if ((y - x) % (a + b)){
        puts("-1");
    }
    else{
        printf("%d\n", (y - x) / (a + b));
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}