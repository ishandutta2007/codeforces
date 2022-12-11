#include <bits/stdc++.h>

using ll = long long;

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        ll n;
        scanf("%lld", &n);
        if (n % 2050 != 0){
            puts("-1");
            continue;
        }
        n /= 2050;
        int sum = 0;
        while (n > 0){
            sum += n % 10;
            n /= 10;
        }
        printf("%d\n", sum);
    }
    return 0;
}