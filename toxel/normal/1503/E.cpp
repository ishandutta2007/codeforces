#include <bits/stdc++.h>

const int N = 5010;
const int moder = 998244353;

void add(int &a, int b){
    a += b;
    a -= a >= moder ? moder : 0;
}

int comb[N][N];

int get(int a, int b){
    if (a < 0 || b < 0) return 0;
    return comb[a + b][a];
}

int calc(int n, int m, int row, int column){
    return 1ll * get(row - 1, column - 1 + 1) * get(n - row, column - 1) % moder;
}

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] -= comb[i][j] >= moder ? moder : 0;
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int j = 1; j <= m; ++ j){
        int sum = 0;
        for (int i = n; i >= 1; -- i){
            int coe = calc(n, m, i, j);
            ans = (ans + 1ll * sum * coe) % moder;
            add(sum, calc(n, m, n - i + 1, m - j));
        }
    }
    for (int j = 1; j <= n; ++ j){
        int sum = 0;
        for (int i = m; i >= 1; -- i){
            int coe = calc(m, n, i, j);
            ans = (ans + 1ll * sum * coe) % moder;
            if (i < m){
                add(sum, calc(m, n, m - i, n - j));
            }
        }
    }
    ans = 2ll * ans % moder;
    printf("%d\n", ans);
    return 0;
}