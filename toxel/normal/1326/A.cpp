#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        if (n == 1){
            puts("-1");
        }
        else{
            putchar('2');
            for (int i = 0; i < n - 1; ++ i){
                putchar('3');
            }
            puts("");
        }
    }
    return 0;
}