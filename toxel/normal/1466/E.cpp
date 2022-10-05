#include <bits/stdc++.h>

const int N = 500010;
using ll = long long;
const int moder = int(1e9) + 7;
const int BIT = 61;

ll x[N];
int cnt[BIT][2];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &x[i]);
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < BIT; ++ j){
            ++ cnt[j][x[i] >> j & 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        int and_sum = 0, or_sum = 0;
        for (int j = 0; j < BIT; ++ j){
            if (!(x[i] >> j & 1)){
                continue;
            }
            and_sum = (and_sum + ((1ll << j) % moder) * cnt[j][1]) % moder;
        }
        for (int j = 0; j < BIT; ++ j){
            if (!(x[i] >> j & 1)){
                or_sum = (or_sum + ((1ll << j) % moder) * cnt[j][1]) % moder;
            }
            else{
                or_sum = (or_sum + ((1ll << j) % moder) * n) % moder;
            }
        }
        ans = (ans + 1ll * and_sum * or_sum) % moder;
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}