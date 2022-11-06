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
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 300005;

int tt[4 * MAXN], add[4 * MAXN], l[MAXN], r[MAXN], v[MAXN], ans[MAXN];

void push(int ind, int tl, int tr){
    if (tl == tr || tt[ind] == 0){
        return;
    }
    tt[ind << 1] = tt[ind];
    tt[(ind << 1) + 1] = tt[ind];
    tt[ind] = 0;
}

void set_val(int ind, int tl, int tr, int l, int r, int v){
    if (tl == l && tr == r){
        tt[ind] = v;
        return;
    }
    push(ind, tl, tr);
    int tm = (tl + tr) >> 1;
    if (l <= tm){
        set_val(ind << 1, tl, tm, l, min(r, tm), v);
    }
    if (r > tm){
        set_val((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r, v);
    }
}

void go(int ind, int tl, int tr){
    if (tl == tr){
        ans[tl] = tt[ind];
        return;
    }
    push(ind, tl, tr);
    int tm = (tl + tr) >> 1;
    go(ind << 1, tl, tm);
    go((ind << 1) + 1, tm + 1, tr);
}

void solve(){
    int n, m, i;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d%d%d", &l[i], &r[i], &v[i]);
        l[i]--;
        r[i]--;
        v[i]--;
    }
    for(i = m - 1; i >= 0; i--){
        if (l[i] < v[i]){
            set_val(1, 0, n - 1, l[i], v[i] - 1, v[i] + 1);
        }
        if (v[i] < r[i]){
            set_val(1, 0, n - 1, v[i] + 1, r[i], v[i] + 1);
        }
    }
    go(1, 0, n - 1);
    for(i = 0; i < n; i++){
        printf("%d ", ans[i]);
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