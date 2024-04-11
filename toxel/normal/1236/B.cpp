#include <bits/stdc++.h>

const int moder = (int) 1e9 + 7;

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", powermod(powermod(2, m) - 1, n));
    return 0;
}