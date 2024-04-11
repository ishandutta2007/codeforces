#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    int x = 0;
    for (int i = 2; i * i <= n; ++ i){
        if (n % i == 0){
            x = n / i;
            break;
        }
    }
    if (x == 0){
        printf("%d %d\n", 1, n - 1);
        return;
    }
    printf("%d %d\n", x, n - x);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}