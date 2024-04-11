#include<bits/stdc++.h>

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int gcd = k;
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        gcd = std::__gcd(gcd, x);
    }
    int sz = k / gcd;
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", i * gcd, " \n"[i == sz - 1]);
    }
    return 0;
}