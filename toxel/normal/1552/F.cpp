#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

void sub(int &u, int v){
    u -= v;
    u += u < 0 ? moder : 0;
}

int x[N], y[N], s[N];
int dp[N], pre[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d%d", &x[i], &y[i], &s[i]);
    }
    for (int i = 1; i <= n; ++ i){
        int pos = std::upper_bound(x + 1, x + n + 1, y[i]) - x;
        dp[i] = (x[i] - y[i]) % moder;
        add(dp[i], pre[i - 1]);
        sub(dp[i], pre[pos - 1]);
        pre[i] = dp[i];
        add(pre[i], pre[i - 1]);
    }
    int ans = (x[n] + 1) % moder;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == 1){
            add(ans, dp[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}