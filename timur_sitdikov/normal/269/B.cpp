#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int maxn = 5005, inf = 1 << 29;
int dp[maxn][maxn], tp[maxn];

int main(){
    int n, m, i, j, a, mn;
    double v;
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> tp[i] >> v;
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++){
            dp[i][j]= inf;
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if (j == tp[i])
                continue;
            dp[i][j] = dp[i - 1][j] + 1;
        }
        mn = i - 1;
        for(j = 1; j <= tp[i]; j++)
            mn = min(mn, dp[i - 1][j]);
        dp[i][tp[i]] = mn;
    }
    mn = n;
    for(j = 1; j <= m; j++)
        mn = min(mn, dp[n][j]);
    printf("%d", mn);
}