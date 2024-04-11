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

const int MAXN = 5005;

char c[MAXN][MAXN];
int nxt[MAXN][MAXN];

int cnt[MAXN];

void solve(){
    int n, m, i, j, k, ans, cur, all;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%s", &c[i][0]);
        for(j = 0; j < m; j++){
            c[i][j] -= '0';
        }
    }
    for(i = 0; i < n; i++){
        nxt[i][m] = m;
        for(j = m - 1; j >= 0; j--){
            if (c[i][j] == 1){
                nxt[i][j] = nxt[i][j + 1];
            }
            else {
                nxt[i][j] = j;
            }
        }
    }
    ans = 0;
    for(j = 0; j < m; j++){
        for(k = j; k <= m; k++){
            cnt[k] = 0;
        }
        for(i = 0; i < n; i++){
            cnt[nxt[i][j]]++;
        }
        all = n;
        for(k = j; k < m; k++){
            all -= cnt[k];
            cur = all * (k - j + 1);
            if (cur > ans){
                ans = cur;
            }       
        }
    }
    printf("%d", ans);
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