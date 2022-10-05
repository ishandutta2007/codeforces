#include <bits/stdc++.h>

const int moder = (int) 1e9 + 7;
const int N = 5010;
const int M = 27;

int dp[M][N], sum[N], tmp[N];
char s[N];
int fac[N], inv[N], invf[N];

void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}
void sub(int &a, int b){a -= b; a += a < 0 ? moder : 0;}

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int n;
    scanf("%d%s", &n, s);
    dp[26][0] = 1;
    sum[0] = 1;
    for (int i = 0; i < n; ++ i){
        int sit = s[i] - 'a';
        memcpy(tmp, dp[sit], sizeof(tmp));
        for (int len = 1; len < N; ++ len){
            dp[sit][len] = sum[len - 1];
            sub(dp[sit][len], tmp[len - 1]);
        }
        for (int len = 1; len < N; ++ len){
            sub(sum[len], tmp[len]);
            add(sum[len], dp[sit][len]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans = (ans + 1ll * fac[n - 1] * invf[i - 1] % moder * invf[n - i] % moder * sum[i]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}