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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 500005;

int a[MAXN], b[MAXN];
pair<int, int> tt[MAXN];
int offset, time, last_time;

void build(int v, int tl, int tr) {
    if (tl == tr){
        tt[v] = mp(0, 0);
    }
    else {
        int tm = (tl + tr) / 2;
        build (v * 2, tl, tm);
        build (v * 2 + 1, tm + 1, tr);
        tt[v] = mp(0, 0);
    }
}
 
void update(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return;
    if (l == tl && tr == r){
        tt[v]= mp(time, offset);
    }
    else {
        int tm = (tl + tr) >> 1;
        update (v * 2, tl, tm, l, min(r, tm));
        update (v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

int get_val(int v, int tl, int tr, int pos) {
    if (tt[v].first > last_time){
        last_time = tt[v].first;
        offset = tt[v].second;
    }
    if (tl == tr){
        if (last_time == 0){
            return b[pos];
        }
        else{
            return a[pos - offset];
        }
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        return get_val(v * 2, tl, tm, pos);
    else
        return get_val(v * 2 + 1, tm + 1, tr, pos);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, n1, m, k, x, y, t, i;
    scanf("%d %d", &n, &m);
    build(1, 0, n - 1);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d", &t);
        time++;
        if (t == 1){
            scanf("%d %d %d", &x, &y, &k);
            offset = y - x;
            update(1, 0, n - 1, y - 1, y - 1 + k - 1);
        }
        else{
            scanf("%d", &k);
            last_time = 0;
            x = get_val(1, 0, n - 1, k - 1);
            printf("%d\n", x);
        }
    }
}