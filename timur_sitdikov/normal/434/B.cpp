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
#define pii pair<int, int>
#define ll long long

#define FILE "file"

const int MAXN = 1010;

int c[2][MAXN][MAXN];

int sumg[2][MAXN][MAXN];
//int  sumv[2][MAXN][MAXN];
int n[2], m[2];

int _l[MAXN], _r[MAXN];

int calc(int ind, int i0, int j0){
    int i, j, l, r, u, d;
    if (c[ind][i0][j0] == 0){
        return 0;
    }
    for(l = j0; c[ind][i0][l]; l--);
    l++;
    for(r = j0; c[ind][i0][r]; r++);
    r--;
    for(d = i0; c[ind][d][j0]; d--);
    d++;
    for(u = i0; c[ind][u][j0]; u++);
    u--;
    _l[i0] = l;
    _r[i0] = r;
    for(i = i0 - 1; i >= d; i--){
        for(j = _l[i + 1]; sumg[ind][i][j0] - sumg[ind][i][j - 1] != j0 - j + 1; j++);
        _l[i] = j;
        for(j = _r[i + 1]; sumg[ind][i][j] - sumg[ind][i][j0 - 1] != j - j0 + 1; j--);
        _r[i] = j;
    }
    for(i = i0 + 1; i <= u; i++){
        for(j = _l[i - 1]; sumg[ind][i][j0] - sumg[ind][i][j - 1] != j0 - j + 1; j++);
        _l[i] = j;
        for(j = _r[i - 1]; sumg[ind][i][j] - sumg[ind][i][j0 - 1] != j - j0 + 1; j--);
        _r[i] = j;
    }
    int ans = r - l + 1;
    //printf("%d %d %d %d\n", l, r, d, u);
    for(i = d; i <= u; i++){
        //printf("%d %d %d\n", i, _l[i], _r[i]);
        int a = abs(i0 - i) + 1;
        ans = max(ans, a * (_r[i] - _l[i] + 1));
    }
    return ans;
}

int recalc(int ind, int i0, int j0){
    int j;
    c[ind][i0][j0] ^= 1;
    /*for(i = 1; i <= n[ind] + 1; i++){
        sumv[ind][i][j0] = sumv[ind][i - 1][j0] + c[ind][i][j0];
    }*/
    for(j = 1; j <= m[ind] + 1; j++){
        sumg[ind][i0][j] = sumg[ind][i0][j - 1] + c[ind][i0][j];
    }
}

void solve(){
    int i, j, k, q, t, i0, j0;
    scanf("%d%d%d", &n[0], &m[0], &q);
    n[1] = m[0];
    m[1] = n[0];
    for(i = 1; i <= n[0]; i++){
        for(j = 1; j <= m[0]; j++){
            scanf("%d", &c[0][i][j]);
            c[1][j][i] = c[0][i][j];
        }
    }
    for(k = 0; k < 2; k++){
        for(i = 1; i <= n[k] + 1; i++){
            for(j = 1; j <= m[k] + 1; j++){
                sumg[k][i][j] = sumg[k][i][j - 1] + c[k][i][j];
                //sumv[k][i][j] = sumv[k][i - 1][j] + c[k][i][j];
            }
        }
    }
    int ans1, ans2, ans;
    for(; q; q--){
        scanf("%d%d%d", &t, &i0, &j0);
        if (t == 1){
            recalc(0, i0, j0);
            recalc(1, j0, i0);
        }
        else {
            ans1 = calc(0, i0, j0);
            ans2 = calc(1, j0, i0);
            ans = max(ans1, ans2);
            printf("%d\n", ans);
        }
    }
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