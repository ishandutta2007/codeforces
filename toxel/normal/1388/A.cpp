#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    int nn = n - 6 - 10 - 14;
    if (nn <= 0){
        puts("NO");
        return;
    }
    if (nn == 6){
        puts("YES\n5 6 10 15");
        return;
    }
    if (nn == 10){
        puts("YES\n6 10 15 9");
        return;
    }
    if (nn == 14){
        puts("YES\n6 10 15 13");
        return;
    }
    puts("YES");
    printf("%d %d %d %d\n", 6, 10, 14, nn);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}