#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int a, b, n;
        scanf("%d%d%d", &a, &b, &n);
        n %= 3;
        printf("%d\n", n == 0 ? a : n == 1 ? b : (a ^ b));
    }
    return 0;
}