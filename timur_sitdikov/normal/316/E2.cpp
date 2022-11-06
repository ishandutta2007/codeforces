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

const int MAXN = 200005;
const int MOD = 1000000000;

int tt[5 * MAXN], tt1[5 * MAXN];
int a[MAXN], f[MAXN];

int unite(int p1, int p2, int p3, int offset){
    long long a = ((long long)f[offset] * (long long)p2) % MOD;
    int v = (p1 + (int)a);
    if (v >= MOD){
        v -= MOD;
    }
    if (offset){
        a = ((long long)f[offset - 1] * (long long)p3) % MOD;
        v = v + (int)a;
        if (v >= MOD){
            v -= MOD;
        }
    }
    return v;
}

void build(int ind, int tl, int tr){
    if (tl == tr){
        tt[ind] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(ind << 1, tl, tm);
    build((ind << 1) + 1, tm + 1, tr);
    tt[ind] = unite(tt[ind << 1], tt[(ind << 1) + 1], tt1[(ind << 1) + 1], tm + 1 - tl);
    tt1[ind] = unite(tt1[ind << 1], tt[(ind << 1) + 1], tt1[(ind << 1) + 1], tm - tl);
}

void set_val(int ind, int tl, int tr, int wh, int v){
    if (tl == tr){
        tt[ind] = v;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (wh <= tm){
        set_val(ind << 1, tl, tm, wh, v);
    }
    else{
        set_val((ind << 1) + 1, tm + 1, tr, wh, v);
    }
    tt[ind] = unite(tt[ind << 1], tt[(ind << 1) + 1], tt1[(ind << 1) + 1], tm + 1 - tl);
    tt1[ind] = unite(tt1[ind << 1], tt[(ind << 1) + 1], tt1[(ind << 1) + 1], tm - tl);
}

void sum(int ind, int tl, int tr, int l, int r, int &a1, int &a2){
    if (tl == l && tr == r){
        a1 = tt[ind];
        a2 = tt1[ind];
        return;
    }
    int tm = (tl + tr) >> 1;
    if (r <= tm){
        return sum(ind << 1, tl, tm, l, r, a1, a2);
    }
    if (l > tm){
        return sum((ind << 1) + 1, tm + 1, tr, l, r, a1, a2);
    }
    int v1, v2, u1, u2;
    sum(ind << 1, tl, tm, l, tm, v1, v2);
    sum((ind << 1) + 1, tm + 1, tr, tm + 1, r, u1, u2);
    a1 = unite(v1, u1, u2, tm + 1 - l);
    a2 = unite(v2, u1, u2, tm - l);
}

void add(int ind, int tl, int tr, int l, int r, int v){
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, t, l, r, i;
    int v;
    int ans1, ans2;
    scanf("%d %d", &n, &m);
    f[0] = f[1] = 1;
    for(i = 2; i <= n; i++){
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] >= MOD){
            f[i] -= MOD;
        }
    }
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    build(1, 0, n - 1);
    /*if (n == 12437){
        return 0;
    }*/
    for(i = 0; i < m; i++){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d %d", &l, &v);
            l--;
            set_val(1, 0, n - 1, l, v);
        }
        else if (t == 2){
            scanf("%d %d", &l, &r);
            l--;
            r--;
            sum(1, 0, n - 1, l, r, ans1, ans2);
            printf("%d\n", ans1);
        }
        else{
            scanf("%d %d %d", &l, &r, &v);
            l--;
            r--;
            add(1, 0, n - 1, l, r, v);
        }
    }
}