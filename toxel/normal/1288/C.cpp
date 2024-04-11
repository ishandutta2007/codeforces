#include <bits/stdc++.h>

const int N = 1100;
const int moder = int(1e9) + 7;

int comb[N][N];

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = i; j <= n; ++ j){
            ans = (ans + 1ll * comb[i - 1 + m - 1][m - 1] * comb[n - j + m - 1][m - 1]) % moder;
        }
    }
    printf("%d\n", ans);
    return 0;
}