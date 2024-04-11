#include<bits/stdc++.h>

const int moder = (int) 1e9 + 7;

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
    int k, p;
    scanf("%d%d", &p, &k);
    if (k == 0){
        printf("%d\n", powermod(p, p - 1));
        return 0;
    }
    if (k == 1){
        printf("%d\n", powermod(p, p));
        return 0;
    }
    int x = k, cnt = 1;
    while (x != 1){
        x = 1ll * x * k % p;
        ++ cnt;
    }
    printf("%d\n", powermod(p, (p - 1) / cnt));
    return 0;
}