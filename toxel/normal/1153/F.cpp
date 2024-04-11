#include <bits/stdc++.h>

const int N = 4010;
const int moder = 998244353;

int comb[N][N];
int poly[N];
int inv[N];
int coe[N], power[N];

int main(){
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2 * power[i - 1] % moder;
    }
    inv[1] = 1;
    for (int i = 2; i < N; ++ i){
        inv[i] = moder - 1ll * inv[moder % i] * (moder / i) % moder;
    }
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % moder;
        }
    }
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    int ans = 0;
    poly[0] = 1;
    for (int i = 1; i <= n; ++ i){
        for (int j = N - 1; j; -- j){
            poly[j] = poly[j - 1];
        }
        poly[0] = 0;
        for (int j = N - 1; j; -- j){
            poly[j] = (1ll * poly[j - 1] * (moder - 1) + poly[j]) % moder;
        }
        int sum = 1ll * power[i] * comb[n][i] % moder;
        for (int j = 0; j < N - 1; ++ j){
            coe[i] = (coe[i] + 1ll * inv[j + 1] * poly[j] % moder * sum) % moder;
        }
    }
    for (int i = k; i <= n; ++ i){
        int sum = 0;
        for (int j = i; j <= n; ++ j){
            sum = (sum + (j - i & 1 ? -1ll : 1ll) * comb[j][i] * coe[j]) % moder;
        }
        sum += sum < 0 ? moder : 0;
        ans = (ans + sum) % moder;
    }
    ans = 1ll * ans * l % moder;
    printf("%d\n", ans);
    return 0;
}