#include <bits/stdc++.h>

void solve(){
    int n0, n1, n2;
    scanf("%d%d%d", &n0, &n1, &n2);
    if (n1 == 0){
        if (n0 > 0){
            for (int i = 0; i <= n0; ++ i){
                putchar('0');
            }
        }
        else{
            for (int i = 0; i <= n2; ++ i){
                putchar('1');
            }
        }
        puts("");
        return;
    }
    if (n1 % 2 == 0){
        if (n0 == 0){
            for (int i = 0; i < n1 / 2; ++ i){
                printf("10");
            }
            for (int i = 0; i <= n2; ++ i){
                putchar('1');
            }
            puts("");
            return;
        }
        for (int i = 0; i < n1 / 2; ++ i){
            printf("01");
        }
        for (int i = 0; i < n2; ++ i){
            putchar('1');
        }
        for (int i = 0; i <= n0; ++ i){
            putchar('0');
        }
        puts("");
        return;
    }
    for (int i = 0; i < n1 / 2; ++ i){
        printf("01");
    }
    for (int i = 0; i <= n0; ++ i){
        putchar('0');
    }
    for (int i = 0; i <= n2; ++ i){
        putchar('1');
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