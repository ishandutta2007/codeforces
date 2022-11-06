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

const int MAXN = (1 << 18) + 5;

char ff[MAXN];

int tt[4 * MAXN], aa[MAXN];

void set_val(int ind, int sz){
    if (ff[sz] == 0){
        tt[ind] = tt[ind << 1] ^ tt[(ind << 1) + 1];
    }
    else {
        tt[ind] = tt[ind << 1] | tt[(ind << 1) + 1];
    }
}

void build(int ind, int tl, int tr){
    if (tl == tr){
        tt[ind] = aa[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(ind << 1, tl, tm);
    build((ind << 1) + 1, tm + 1, tr);
    set_val(ind, tr - tl + 1);
}

void update(int ind, int tl, int tr, int pos, int v){
    if (tl == tr){
        tt[ind] = v;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm){
        update(ind << 1, tl, tm, pos, v);
    }
    else {
        update((ind << 1) + 1, tm + 1, tr, pos, v);
    }
    set_val(ind, tr - tl + 1);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, i, a, ind;
    scanf("%d%d", &n, &m);
    for(i = 0; i < (1 << n); i++){
        scanf("%d", &aa[i]);
    }
    for(i = 1; i <= n + 1; i++){
        ff[1 << i] = (i & 1);
    }
    build(1, 0, (1 << n) - 1);
    for(i = 0; i < m; i++){
        scanf("%d%d", &ind, &a);
        update(1, 0, (1 << n) - 1, ind - 1, a);
        printf("%d\n", tt[1]);
    }
}