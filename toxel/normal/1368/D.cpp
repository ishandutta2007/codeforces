#include <bits/stdc++.h>

const int N = 200010;
const int BIT = 20;
using ll = long long;

int a[N], cnt[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        for (int j = 0; j < BIT; ++ j){
            cnt[j] += a[i] >> j & 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        int x = 0;
        for (int j = 0; j < BIT; ++ j){
            if (cnt[j] > 0){
                -- cnt[j];
                x |= 1 << j;
            }
        }
        ans += 1ll * x * x;
    }
    printf("%lld\n", ans);
    return 0;
}