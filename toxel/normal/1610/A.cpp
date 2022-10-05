#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n, m;
        scanf("%d%d", &n, &m);
        if (n == 1 && m == 1){
            puts("0");
        }
        else if (n == 1 || m == 1){
            puts("1");
        }
        else{
            puts("2");
        }
    }
    return 0;
}