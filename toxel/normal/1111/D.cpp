#include<bits/stdc++.h>

const int moder = (int) 1e9 + 7;
const int N = 100010;
const int M = 210;

int fac[N], inv[N], invf[N];

void init(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
}

inline void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}
inline void sub(int &a, int b){a -= b; a += a < 0 ? moder : 0;}

int cnt[M], ans[M][M];
int dp[N], tmp[N], tmp1[N];
char s[N];

int main(){
    init();
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++ i){
        ++ cnt[(int) s[i]];
    }
    int prod = 1;
    dp[0] = 1;
    for (int i = 0; i < M; ++ i){
        if (!cnt[i]) continue;
        for (int j = N - 1; j >= cnt[i]; -- j){
            add(dp[j], dp[j - cnt[i]]);
        }
        prod = 1ll * prod * invf[cnt[i]] % moder;
    }
    for (int i = 0; i < M; ++ i){
        if (!cnt[i]) continue;
        memcpy(tmp, dp, sizeof(dp));
        for (int j = N - 1; j >= cnt[i]; -- j){
            sub(tmp[j - cnt[i]], tmp[j]);
        }
        ans[i][i] = tmp[n / 2];
        for (int j = i + 1; j < M; ++ j){
            memcpy(tmp1, tmp, sizeof(tmp));
            if (cnt[j] == 0) continue;
            for (int k = N - 1; k >= cnt[j]; -- k){
                sub(tmp1[k - cnt[j]], tmp1[k]);
            }
            ans[i][j] = tmp1[n / 2];
        }
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int x, y;
        scanf("%d%d", &x, &y);
        -- x, -- y;
        int sit1 = s[x], sit2 = s[y];
        if (sit1 > sit2){
            std::swap(sit1, sit2);
        }
        int ret = 2ll * fac[n / 2] * fac[n / 2] % moder * ans[sit1][sit2] % moder * prod % moder;
        printf("%d\n", ret);
    }
    return 0;
}