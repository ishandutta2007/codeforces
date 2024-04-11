#include<bits/stdc++.h>

const int moder = 998244353;
const int N = 1000010;

int power[N];
int a[N];

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2 * power[i - 1] % moder;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    int ans = a[n];
    for (int i = 1; i < n; ++ i){
        ans = (ans + 1ll * (n - i + 2) * power[n - i - 1] % moder * a[i]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}