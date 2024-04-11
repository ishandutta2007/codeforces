#include<bits/stdc++.h>

const int N = 6010;
const int moder = 998244353;

int comb[N][N];

void init(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
}

int sol(int n, int sum){
    return comb[n + sum - 1][n - 1];
}

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    init();
    int p, s, r;
    scanf("%d%d%d", &p, &s, &r);
    int ans = 0;
    for (int i = r; i <= s; ++ i){
        for (int j = 0; j < p && (j + 1) * i <= s; ++ j){
            int sum = 0, cnt = p - j - 1, left = s - (j + 1) * i;
            if (!cnt){
                if (!left){
                    sum = 1;
                }
            }
            else{
                for (int k = 0; k <= cnt && k * i <= left; ++ k){
                    sum = (sum + (k & 1 ? -1ll : 1ll) * comb[cnt][k] * sol(cnt, left - k * i)) % moder;
                }
            }
            ans = (ans + 1ll * sum * comb[p - 1][j] % moder * powermod(j + 1, moder - 2)) % moder;
        }
    }
    ans += ans < 0 ? moder : 0;
    ans = 1ll * ans * powermod(sol(p, s - r), moder - 2) % moder;
    printf("%d\n", ans);
}