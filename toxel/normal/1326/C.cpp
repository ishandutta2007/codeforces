#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;
using ll = long long;

int p[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    ll sum = 0;
    for (int i = n; i >= n - k + 1; -- i){
        sum += i;
    }
    int prod = 1, pre = 0;
    for (int i = 1; i <= n; ++ i){
        if (p[i] < n - k + 1){
            continue;
        }
        if (pre > 0){
            prod = 1ll * prod * (i - pre) % moder;
        }
        pre = i;
    }
    printf("%lld %d\n", sum, prod);
    return 0;
}