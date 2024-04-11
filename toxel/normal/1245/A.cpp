#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int a, b;
        scanf("%d%d", &a, &b);
        puts(std::__gcd(a, b) > 1 ? "Infinite" : "Finite");
    }
    return 0;
}