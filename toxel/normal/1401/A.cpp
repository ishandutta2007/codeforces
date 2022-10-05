#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n, k;
        scanf("%d%d", &n, &k);
        if (n < k){
            printf("%d\n", k - n);
        }
        else{
            printf("%d\n", (k + n) % 2);
        }
    }
}