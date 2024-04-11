#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 1000010;

int power[N];

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2 * power[i - 1] % moder;
    }
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int j = 1; j <= n; ++ j){
        for (int i = j; i <= n; i += j){
            ans += i == n ? 1 : power[n - i - 1];
            ans -= ans >= moder ? moder : 0;
        }
    }
    ans %= moder;
    printf("%d\n", ans);
    return 0;
}