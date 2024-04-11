#include <bits/stdc++.h>

const int N = 260010;

int fac[N];

int main(){
    int n, moder;
    scanf("%d%d", &n, &moder);
    fac[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * i * fac[i - 1] % moder;
    }
    int ans = 0;
    for (int len = 1; len <= n; ++ len){
        int num = n - len + 1;
        num = 1ll * num * num % moder;
        ans = (ans + 1ll * num * fac[len] % moder * fac[n - len]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}