#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 1000010;
const int inv2 = (moder + 1) / 2;
const int inv3 = (moder + 1) / 3;
const int inv6 = 1ll * inv2 * inv3 % moder;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

void sub(int &u, int v){
    u -= v;
    u += u < 0 ? moder : 0;
}

int dp[N];
int dp1[N];

int main(){
    dp[0] = dp[1] = 1;
    int pre = 1;
    for (int i = 2; i < N; ++ i){
        dp[i] = 1ll * (dp[i - 1]) * (dp[i - 1] - 1) % moder * inv2 % moder;
        dp[i] = (dp[i] + 1ll * dp[i - 1] * pre) % moder;
        dp[i] += dp[i] < 0 ? moder : 0;
        add(dp[i], dp[i - 1]);
        add(pre, dp[i - 1]);
    }
    pre = 0;
    for (int i = 1; i < N; ++ i){
        add(pre, dp[i]);
        dp1[i] = (dp1[i] + 1ll * pre * (pre - 1) % moder * inv2) % moder;
        dp1[i] += dp1[i] < 0 ? moder : 0;
    }
    for (int i = N - 1; i; -- i){
        sub(dp1[i], dp1[i - 1]);
    }
    for (int i = 1; i < N; ++ i){
        add(dp1[i], dp[i]);
    }
    pre = 0;
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n - 2; ++ i){
        add(pre, dp1[i]);
        ans = (ans + 1ll * dp1[n - 1 - i] * pre) % moder;
    }

    pre = 0;
    for (int i = 1; i <= n; ++ i){
        add(pre, dp[i]);
    }
    ans = (ans + 1ll * pre * (pre - 1)) % moder;
    ans = (ans + 2ll * pre) % moder;

    memset(dp1, 0, sizeof(dp1));
    pre = 0;
    for (int i = 1; i < N; ++ i){
        add(pre, dp[i]);
        dp1[i] = (dp1[i] + 1ll * pre * (pre - 1) % moder * (pre - 2) % moder * inv6) % moder;
        dp1[i] = (dp1[i] + 1ll * pre * (pre - 1)) % moder;
        add(dp1[i], pre);
    }
    for (int i = N - 1; i; -- i){
        sub(dp1[i], dp1[i - 1]);
    }
    ans = (ans + 2ll * dp1[n]) % moder;
    add(ans, 1);
    printf("%d\n", ans);
    return 0;
}