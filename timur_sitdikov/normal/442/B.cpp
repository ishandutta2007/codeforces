#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

const int MAXN = 105;

double dp0[MAXN][MAXN], dp1[MAXN][MAXN];
double p[MAXN];

void solve(){
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%lf", &p[i]);
    }
    sort(p, p + n);
    for(i = 0; i < n; i++){
        dp0[i][i] = 1. - p[i];
        dp1[i][i] = p[i];
    }
    for(i = n - 2; i >= 0; i--){
        for(j = i + 1; j < n; j++){
            dp0[i][j] = dp0[i][j - 1] * (1. - p[j]);
            dp1[i][j] = dp0[i][j - 1] * p[j] + dp1[i][j - 1] * (1. - p[j]);
        }
    }
    double ans = 0.;
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            ans = max(ans, dp1[i][j]);
        }
    }
    printf("%.12lf\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = 1;
    while(t--){
        solve();    
    }
}