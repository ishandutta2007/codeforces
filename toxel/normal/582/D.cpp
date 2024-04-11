#include<bits/stdc++.h>

const int moder = 1e9 + 7;
const int N = 4010;
typedef long long ll;

int sum(int l, int r){
    int ret = (1ll * (l + r) * (r - l + 1) / 2) % moder;
    ret += ret < 0 ? moder : 0;
    return ret;
}

int dp[2][N][2][2];
char s[N];
int a[N];
int digit[N];

int main(){
    int p, e;
    scanf("%d%d%s", &p, &e, s);
    int n = strlen(s);
    for (int i = 0; i < n; ++ i){
        a[i] = s[i] - '0';
    }
    std::reverse(a, a + n);
    int cnt = 0;
    while (n){
        ll remain = 0;
        for (int i = n - 1; i >= 0; -- i){
            remain = remain * 10 + a[i];
            a[i] = remain / p;
            remain %= p;
        }
        digit[cnt ++] = remain;
        for ( ; n && !a[n - 1]; -- n);
    }
    int now = 0;
    dp[now][0][0][0] = 1;
    for (int i = 0; i < cnt; ++ i){
        memset(dp[now ^ 1], 0, sizeof(dp[now]));
        for (int car = 0; car < N; ++ car){
            for (int j = 0; j < 2; ++ j){
                for (int k = 0; k < 2; ++ k){
                    if (!dp[now][car][j][k]) continue;
                    int x = dp[now][car][j][k];
                    int limit = digit[i] - k;
                    int x1 = 0, x3 = 0;
                    if (limit >= 0){
                        x1 = sum(1, limit + 1 - j);
                        x3 = sum(p - limit - 1 + j, p - 1 + j);
                    }
                    int x2 = sum(0, p - j) - x1;
                    x2 += x2 < 0 ? moder : 0;
                    int x4 = sum(0, p - 1 + j) - x3;
                    x4 += x4 < 0 ? moder : 0;
                    int *p = dp[now ^ 1][car][0];
                    *p = (*p + 1ll * x * x1) % moder;
                    ++ p;
                    *p = (*p + 1ll * x * x2) % moder;
                    p = dp[now ^ 1][car + 1][1];
                    *p = (*p + 1ll * x * x3) % moder;
                    ++ p;
                    *p = (*p + 1ll * x * x4) % moder;
                }
            }
        }
        now ^= 1;
    }
    if (e >= N){
        puts("0");
        return 0;
    }
    int ans = 0;
    for (int i = e; i < N; ++ i){
        ans += dp[now][i][0][0];
        ans -= ans >= moder ? moder : 0;
    }
    printf("%d\n", ans);
    return 0;
}