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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"
#define pii pair<int, int>

const int MAXN = 305;
const int INF = 2e9;

int v[MAXN][MAXN];

map<int, int> mm[MAXN];
map<int, int>::iterator it, it1;
int add[MAXN];

int sum1[MAXN][MAXN], sum2[MAXN][MAXN], sum3[MAXN][MAXN], sum4[MAXN][MAXN];

void solve(){
    int n, m, i, j, k, l, tp, tu, td, t;
    scanf("%d%d%d%d%d%d", &n, &m, &t, &tp, &tu, &td);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            scanf("%d", &v[i][j]);
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 2; j <= m; j++){
            sum1[i][j] = sum1[i][j - 1] + (v[i][j] > v[i][j - 1]? tu: (v[i][j] < v[i][j - 1]? td: tp));
        }
        for(j = m - 1; j >= 1; j--){
            sum2[i][j] = sum2[i][j + 1] + (v[i][j] > v[i][j + 1]? tu: (v[i][j] < v[i][j + 1]? td: tp));
        }
    }
    for(j = 1; j <= m; j++){
        for(i = 2; i <= n; i++){
            sum3[i][j] = sum3[i - 1][j] + (v[i][j] > v[i - 1][j]? tu: (v[i][j] < v[i - 1][j]? td: tp));
        }
        for(i = n - 1; i >= 1; i--){
            sum4[i][j] = sum4[i + 1][j] + (v[i][j] > v[i + 1][j]? tu: (v[i][j] < v[i + 1][j]? td: tp));
        }
    }
    
    /*for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            printf("%d %d: %d %d %d %d\n", i, j, sum1[i][j], sum2[i][j], sum3[i][j], sum4[i][j]);
        }
    }*/

    int ans = INF, ansi1, ansj1, ansi2, ansj2;
    int dif1, dif2, dif3, dif4, tmp;
    for(i = 1; i <= n - 2; i++){
        for(k = i + 2; k <= n; k++){
            mm[k].clear();
            add[k] = 0;
            dif1 = sum1[i][m] - sum1[i][m - 1];
            dif2 = sum2[k][m - 1] - sum2[k][m];
            dif3 = sum3[k][m] - sum3[i][m];
            dif4 = sum4[i][m - 1] - sum4[k][m - 1];
            //mm[k].insert(mp(dif1 + dif2 + dif3 + dif4, m));
            add[k] = dif4;
        }
        for(j = m - 2; j >= 1; j--){
            for(k = i + 2; k <= n; k++){
                dif1 = sum1[i][j + 1] - sum1[i][j];
                dif2 = sum2[k][j] - sum2[k][j + 1];
                dif3 = sum4[i][j + 1] - sum4[k][j + 1];
                //dif3 = dif4;
                dif4 = sum4[i][j] - sum4[k][j];
                add[k] += dif1 + dif2 - dif3 + dif4;
                    
                dif1 = sum1[i][j + 2] - sum1[i][j];
                dif2 = sum2[k][j] - sum2[k][j + 2];
                dif3 = sum3[k][j + 2] - sum3[i][j + 2];
                //dif4 = sum4[i][j] - sum4[k + 1][j];
                mm[k].insert(mp(dif1 + dif2 + dif3 + dif4 - add[k], j + 2));
                
                tmp = t - add[k];               
                it = mm[k].lower_bound(tmp);

                for(l = 0; l < 2; l++){
                    /*if (i == 4 && j == 3 && k == 6){
                        printf("%d %d %d %d\n", t, add[k], it->first, it->second);
                    }*/
                    if (it != mm[k].end()){
                        if (abs(it->first - tmp) < ans){
                            ans = abs(it->first - tmp);
                            ansi1 = i;
                            ansj1 = j;
                            ansi2 = k;
                            ansj2 = it->second;
                        }
                    }
                    if (it != mm[k].begin()){
                        it--;
                    }
                    else {
                        break;
                    }
                }
            }   
        }
    }
    //printf("%d\n", ans);
    printf("%d %d %d %d\n", ansi1, ansj1, ansi2, ansj2);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}