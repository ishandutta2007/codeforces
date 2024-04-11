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

const int maxn = 205, inf = 1 << 27;
int g[maxn][maxn], g1[maxn][maxn];
int qq[maxn], h, t, n, dis[maxn];
char col[maxn];
int aa[maxn], dd[maxn], x[maxn], bb[maxn], l;

int find_min(){
    int i, ind, ind1, ans;
    ind = 1;
    for(i = 2; i <= n; i++){
        if (aa[i] > aa[ind] || aa[i] == aa[ind] && x[i] > x[ind]){
            ind = i;
        }
    }
    ans = aa[ind];
    while(x[ind] < l){
        ind1 = -1;
        for(i = 1; i <= n; i++){
            if (x[i] + dd[i] > x[ind] + dd[ind] && 
                (ind1 == -1 || aa[i] > aa[ind1] ||
                aa[i] == aa[ind1] && dd[i] > dd[ind1])){
                    ind1 = i;
            }
        }
        if (ind1 == -1)
            break;
        ans = min(ans, (x[ind] + dd[ind] + aa[ind1]) / 2);
        ind = ind1;
    }
    return ans;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, i, j, k, a, b, w;
    int cur, ans;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &w);
        g[a][b] = g[b][a] = 2 * w;
    }
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            g1[i][j] = g1[j][i] = (g[i][j]? g[i][j]: inf);
        }
    }
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
            }
        }
    }
    ans = inf;
    for(i = 1; i <= n; i++){
        cur = 0; 
        for(j = 1; j <= n; j++){
            cur = max(cur, g1[i][j]);
        }
        ans = min(ans, cur);
    }
    for(i = 1; i <= n; i++){
        for(j = i + 1; j <= n; j++){
            if (!g[i][j])
                continue;
            cur = 0;
            l = g[i][j];
            for(k = 1; k <= n; k++){
                aa[k] = g1[i][k];
                bb[k] = g1[j][k];
                x[k] = (bb[k] + l - aa[k]) / 2;
                dd[k] = aa[k] + x[k];
            }
            cur = find_min();
            ans = min(ans, cur);
        }
    }
    printf("%d.%d", ans / 2, 5 * (ans % 2));
}