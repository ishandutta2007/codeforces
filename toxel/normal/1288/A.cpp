#include <bits/stdc++.h>

void solve(){
    int n, d;
    scanf("%d%d", &n, &d);
    if (n > 1e5){
        puts("YES");
        return;
    }
    for (int i = 0; i <= n; ++ i){
        if (i + (i + d) / (i + 1) <= n){
            puts("YES");
            return;
        }
    }
    puts("NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}