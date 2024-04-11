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

const int MAXN = 1005, MAXVAL = 1000000005;

int v[MAXN][MAXN];
char cnt[MAXN][MAXN];
int bads[MAXN], top;

void solve(){
    int n, m, i, j, k, l, r, mid, fl;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &v[i][j]);
        }
    }
    for(l = 0, r = MAXVAL; l + 1 < r; ){
        mid = (l + r) >> 1;
        for(i = 0; i < m; i++){
            for(j = i + 1; j < m; j++){
                cnt[i][j] = 0;
            }
        }
        fl = 0;
        for(i = 0; i < n; i++){
            top = 0;
            for(j = 0; j < m; j++){
                if (v[i][j] >= mid){
                    bads[top++] = j;
                }
            }       
            for(j = 0; j < top; j++){
                for(k = j + 1; k < top; k++){
                    if (cnt[bads[j]][bads[k]]){
                        fl = 1;
                        break;
                    }   
                    cnt[bads[j]][bads[k]] = 1;
                }
                if (fl == 1){
                    break;
                }
            }
            if (fl == 1){
                break;
            }
        }
        if (fl == 1){
            l = mid;
        }
        else {
            r = mid;
        }
    }
    printf("%d", l);
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