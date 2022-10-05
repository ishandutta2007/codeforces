#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n, k;
        scanf("%d%d", &n, &k);
        if (n % 2 != k % 2){
            puts("NO");
        }
        else{
            puts(n >= 1ll * k * k ? "YES" : "NO");
        }
    }
    return 0;
}