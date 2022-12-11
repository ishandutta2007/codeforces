#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 2010;

char s[N];
int comb[N][N];
int pre_comb[N][N];
int pre_l[N], pre_q[N], suf_r[N], suf_q[N];

int getcomb(int n, int m){
    if (n < m || m < 0){
        return 0;
    }
    return comb[n][m];
}

int getpre(int n, int m){
    return m < 0 ? 0 : m > n ? pre_comb[n][n] : pre_comb[n][m];
}

int getpre(int n, int l, int r){
    if (l > r){
        return 0;
    }
    int x = getpre(n, r) - getpre(n, l - 1);
    x += x < 0 ? moder : 0;
    return x;
}

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
        for (int j = 0; j < N; ++ j){
            pre_comb[i][j] = (j ? pre_comb[i][j - 1] : 0) + comb[i][j];
            pre_comb[i][j] -= pre_comb[i][j] >= moder ? moder : 0;
        }
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
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == '(' || s[i] == '?'){
            for (int j = 1; j <= n; ++ j){
                int coe = getcomb(pre_q[i - 1], j - pre_l[i - 1] - 1);
                int coe1 = getpre(suf_q[i + 1], j - suf_r[i + 1], suf_q[i + 1]);
                ans = (ans + 1ll * coe * coe1) % moder;
            }
        }
    }
    printf("%d\n", ans);
}