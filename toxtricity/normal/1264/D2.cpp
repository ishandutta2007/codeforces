#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 3000010;

char s[N];
int fac[N], inv[N], invf[N];
int pre1[N], pre2[N];
int pre_l[N], pre_q[N], suf_r[N], suf_q[N];

int comb(int n, int m){
    return m < 0 || n < m ? 0 : 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int getpre(int *pre, int m){
    return m < 0 ? 0 : m >= N ? pre[N - 1] : pre[m];
}

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++ i){
        pre_l[i] = pre_l[i - 1] + (s[i] == '(');
        pre_q[i] = pre_q[i - 1] + (s[i] == '?');
    }
    for (int i = n; i >= 1; -- i){
        suf_r[i] = suf_r[i + 1] + (s[i] == ')');
        suf_q[i] = suf_q[i + 1] + (s[i] == '?');
    }
    int max = pre_q[n];
    for (int i = 0; i < N; ++ i){
        pre2[i] = (i ? pre2[i - 1] : 0) + comb(max, i);
        pre2[i] -= pre2[i] >= moder ? moder : 0;
    }
    if (max){
        for (int i = 0; i < N; ++ i){
            pre1[i] = (i ? pre1[i - 1] : 0) + comb(max - 1, i);
            pre1[i] -= pre1[i] >= moder ? moder : 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == '('){
            ans += getpre(pre2, suf_q[i + 1] + suf_r[i + 1] - pre_l[i - 1] - 1);
        }
        else if (s[i] == '?'){
            ans += getpre(pre1, suf_q[i + 1] + suf_r[i + 1] - pre_l[i - 1] - 1);
        }
        ans -= ans >= moder ? moder : 0;
    }
    printf("%d\n", ans);
}