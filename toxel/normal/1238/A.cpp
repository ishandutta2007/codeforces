#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        long long x, y;
        scanf("%lld%lld", &x, &y);
        if (x - y == 1){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
    return 0;
}