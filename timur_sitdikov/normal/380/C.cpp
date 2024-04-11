#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <list>
#include <complex>
using namespace std;

#define pb push_back 
#define mp make_pair

#define point complex<double>
#define xx real()
#define yy imag()

const int MAXN = 4444444;

int bb[MAXN], tt[MAXN];
char c[MAXN];

void build(int ind, int tl, int tr){
    if (tl == tr){
        tt[ind] = bb[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(ind << 1, tl, tm);
    build((ind << 1) + 1, tm + 1, tr);
    if (tt[ind << 1] <= tt[(ind << 1) + 1]){
        tt[ind] = tt[ind << 1];
    }
    else {
        tt[ind] = tt[(ind << 1) + 1];
    }
}

int get_min(int ind, int tl, int tr, int l, int r){
    if (tl == l && tr == r){
        return tt[ind];
    }
    int tm = (tl + tr) >> 1, v1, v2;
    if (r <= tm){
        return get_min(ind << 1, tl, tm, l, r);
    }
    if (l > tm){
        return get_min((ind << 1) + 1, tm + 1, tr, l, r);
    }
    v1 = get_min(ind << 1, tl, tm, l, tm);
    v2 = get_min((ind << 1) + 1, tm + 1, tr, tm + 1, r);
    if (v1 < v2){
        return v1;
    }
    return v2;
}

void solve(){
    int n, i, j, q, l, r, ans, tmp;
    scanf("%s", &c[1]);
    bb[0] = 0;
    for(i = 1; c[i]; i++){
        if (c[i] == '('){
            bb[i] = bb[i - 1] + 1;
        }
        else {
            bb[i] = bb[i - 1] - 1;
        }
    }
    n = i;
    build(1, 0, n - 1);
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d%d", &l, &r);
        tmp = get_min(1, 0, n - 1, l - 1, r);
        ans = r - l + 1 + 2 * tmp - bb[l - 1] - bb[r];
        printf("%d\n", ans);
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