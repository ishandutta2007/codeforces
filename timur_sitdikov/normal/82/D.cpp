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

const int MAXN = 1005;

int dp[MAXN][MAXN], prv[MAXN][MAXN], prvn[MAXN][MAXN], inds[MAXN][MAXN][2];

const int INF = 1000000000;

int a[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(i = 2; i <= n + 2; i++){
        for(j = 1; j < i; j++){
            dp[i][j] = INF;
        }
    }
    dp[2][1] = 0;
    for(i = 2; i <= n + 1; i++){
        for(j = 1; j < i; j++){
            if (dp[i][j] == INF)
                continue;
            if (i == n + 1){
                if (dp[n + 2][n + 1] > dp[n + 1][j] + a[j]){
                    dp[n + 2][n + 1] = dp[n + 1][j] + a[j];
                    prv[n + 2][n + 1] = j;
                    prvn[n + 2][n + 1] = n + 1;
                    inds[n + 2][n + 1][0] = j;
                }
                continue;
            }
            if (i == n){
                if (dp[n + 2][n + 1] > dp[n][j] + max(a[j], a[n])){
                    dp[n + 2][n + 1] = dp[n][j] + max(a[j], a[n]);
                    prv[n + 2][n + 1] = j;
                    prvn[n + 2][n + 1] = n;
                    inds[n + 2][n + 1][0] = j;
                    inds[n + 2][n + 1][1] = n;
                }
                continue;
            }
            if (dp[i + 2][i + 1] > dp[i][j] + max(a[j], a[i])){
                dp[i + 2][i + 1] = dp[i][j] + max(a[j], a[i]);
                prv[i + 2][i + 1] = j;
                prvn[i + 2][i + 1] = i;
                inds[i + 2][i + 1][0] = j;
                inds[i + 2][i + 1][1] = i;
            }
            if (dp[i + 2][i] > dp[i][j] + max(a[j], a[i + 1])){
                dp[i + 2][i] = dp[i][j] + max(a[j], a[i + 1]);
                prv[i + 2][i] = j;
                prvn[i + 2][i] = i;
                inds[i + 2][i][0] = j;
                inds[i + 2][i][1] = i + 1;
            }
            if (dp[i + 2][j] > dp[i][j] + max(a[i], a[i + 1])){
                dp[i + 2][j] = dp[i][j] + max(a[i], a[i + 1]);
                prv[i + 2][j] = j;
                prvn[i + 2][j] = i;
                inds[i + 2][j][0] = i;
                inds[i + 2][j][1] = i + 1;
            }
        }
    }
    printf("%d\n", dp[n + 2][n + 1]);
    vector<pair<int, int> > ans;
    int i1, j1;
    for(i = n + 2, j = n + 1; i != 0; i = i1, j = j1){
        ans.pb(mp(inds[i][j][0], inds[i][j][1]));
        i1 = prvn[i][j];
        j1 = prv[i][j];
    }
    for(i = ans.size() - 2; i >= 0; i--){
        printf("%d ", ans[i].first);
        if (ans[i].second){
            printf("%d", ans[i].second);
        }
        putchar('\n');
    }
}