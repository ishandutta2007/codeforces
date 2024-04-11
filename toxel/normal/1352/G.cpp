#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    if (n <= 3){
        puts("-1");
        return;
    }
    if (n == 4){
        puts("2 4 1 3");
        return;
    }
    if (n == 5){
        puts("2 4 1 3 5");
        return;
    }
    for (int i = 1; i <= n; i += 2){
        printf("%d ", i);
    }
    if (n % 2 == 0){
        printf("%d %d %d", n - 4, n, n - 2);
        for (int i = n - 6; i >= 1; i -= 2){
            printf(" %d", i);
        }
        puts("");
    }
    else{
        printf("%d %d", n - 3, n - 1);
        for (int i = n - 5; i >= 1; i -= 2){
            printf(" %d", i);
        }
        puts("");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}