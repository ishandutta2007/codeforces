#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int MAXN = 42;

int mx_r[MAXN][MAXN], mx_c[MAXN][MAXN];
char cc[MAXN][MAXN];
int ans[MAXN][MAXN][MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];

void solve(){
    int q, n, m, a, b, c, d, i, j, k, l, lim;
    scanf("%d%d%d", &n, &m, &q);
    for(i = 1; i <= n; i++){
        scanf("%s", &cc[i][1]);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cc[i][j] -= '0';
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if (cc[i][j] == 1){
                mx_r[i][j] = i;
                mx_c[i][j] = j;
            }
            else {
                mx_r[i][j] = mx_r[i - 1][j];
                mx_c[i][j] = mx_c[i][j - 1];
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            lim = 0;
            for(k = i; k > 0; k--){
                lim = max(lim, mx_c[k][j]);
                for(l = j; l > lim; l--){
                    dp[k][l][i][j] = dp[k][l + 1][i][j] + (i - k + 1);
                }
                for(; l > 0; l--){
                    dp[k][l][i][j] = dp[k + 1][l][i][j] + j - lim;
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            for(k = 1; k <= i; k++){
                for(l = 1; l <= j; l++){
                    ans[k][l][i][j] = ans[k][l][i - 1][j] + ans[k][l][i][j - 1] - ans[k][l][i - 1][j - 1];
                    ans[k][l][i][j] += dp[k][l][i][j];
                }
            }
        }
    }
    for(i = 0; i < q; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", ans[a][b][c][d]);
    }
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}