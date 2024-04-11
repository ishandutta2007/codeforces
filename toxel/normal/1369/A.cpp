#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int x;
        scanf("%d", &x);
        puts(x % 4 ? "NO" : "YES");
    }
    return 0;
}