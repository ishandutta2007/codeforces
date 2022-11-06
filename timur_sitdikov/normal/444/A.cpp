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

#define file "cycle"

const int MAXN = 505;

int g[MAXN][MAXN];
int v[MAXN];

void solve(){
    int n, m, a, b, c, i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = c;
    }
    double ans = 0.;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if (g[i][j] && ans * g[i][j] < v[i] + v[j]){
                ans = (v[i] + v[j]) / (g[i][j] + 0.);
            }
        }
    }
    printf("%.12lf\n", ans);
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}