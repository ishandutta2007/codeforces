#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int a, b;
        scanf("%d%d", &a, &b);
        if (2 * a <= b){
            printf("%d\n", (b + 1) / 2 - 1);
        }
        else{
            printf("%d\n", b - a);
        }
    }
    return 0;
}