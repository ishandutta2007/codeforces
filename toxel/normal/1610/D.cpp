#include <bits/stdc++.h>

const int N = 200010;
const int BIT = 35;
const int moder = int(1e9) + 7;

int a[N];
int cnt[N], ccnt[BIT], power[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    memset(ccnt, 0, sizeof(ccnt));
    for (int i = 1; i <= n; ++ i){
        cnt[i] = 0;
        while (a[i] % 2 == 0){
            ++ cnt[i];
            a[i] /= 2;
        }
        ++ ccnt[cnt[i]];
    }
    int ans = 0;
    for (int i = 1; i < BIT - 1; ++ i){
        if (ccnt[i] > 0){
            int sum = 0;
            for (int j = i + 1; j < BIT; ++ j){
                sum += ccnt[j];
            }
            ans = (ans + 1ll * power[ccnt[i] - 1] * power[sum]) % moder;
        }
    }
    ans = (power[n] - 1 - ans) % moder;
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
}

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2 * power[i - 1] % moder;
    }
    int test;
    // scanf("%d", &test);
    test = 1;
    while (test --){
        solve();
    }
    return 0;
}