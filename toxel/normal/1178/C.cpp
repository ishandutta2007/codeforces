#include <bits/stdc++.h>

const int moder = 998244353;

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * a * ret % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    int w, h;
    scanf("%d%d", &w, &h);
    printf("%d\n", powermod(2, w + h));
    return 0;
}