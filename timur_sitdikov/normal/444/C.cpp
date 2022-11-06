#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

const int MAXN = 1e5 + 5;

ll sum[4 * MAXN], add[4 * MAXN], col[4 * MAXN];

void push(int ind, int tl, int tr){
    int ind1 = ind << 1, ind2 = (ind << 1) + 1, tm = (tl + tr) >> 1;
    if (col[ind]){
        add[ind1] += add[ind];
        add[ind2] += add[ind];
        col[ind1] = col[ind];
        col[ind2] = col[ind];
        sum[ind1] += add[ind] * (tm - tl + 1);
        sum[ind2] += add[ind] * (tr - tm);
        add[ind] = 0;
    }
}

void build(int ind, int tl, int tr){
    if (tl == tr){
        col[ind] = tl + 1;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(ind << 1, tl, tm);
    build((ind << 1) + 1, tm + 1, tr);
}

ll get_sum(int ind, int tl, int tr, int l, int r){
    if (tl == l && tr == r){
        return sum[ind];
    }
    if (tl > r || tr < l){
        return 0ll;
    }
    push(ind, tl, tr);
    int tm = (tl + tr) >> 1;
    return get_sum(ind << 1, tl, tm, l, min(r, tm)) + get_sum((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

void upd(int ind, int tl, int tr, int l, int r, int val){
    if (tl == l && tr == r && col[ind]){
        ll dif = val - col[ind];
        if (dif < 0){
            dif = -dif;
        }
        sum[ind] += dif * (tr - tl + 1);
        add[ind] += dif;
        col[ind] = val;
        return;
    }
    if (tl > r || tr < l){
        return;
    }
    push(ind, tl, tr);
    int tm = (tl + tr) >> 1, ind1 = ind << 1, ind2 = (ind << 1) + 1;
    upd(ind1, tl, tm, l, min(r, tm), val);
    upd(ind2, tm + 1, tr, max(l, tm + 1), r, val);
    sum[ind] = sum[ind1] + sum[ind2];
    if (col[ind1] == col[ind2]){
        col[ind] = col[ind1];
    } else {
        col[ind] = 0;
    }
}

void solve(){
    int n, q, i, l, r, x, t;
    scanf("%d%d", &n, &q);
    build(1, 0, n - 1);
    /*printf("#");
    return;*/
    for(; q; q--){
        scanf("%d%d%d", &t, &l, &r);
        l--;
        r--;
        if (t == 1){
            scanf("%d", &x);
            upd(1, 0, n - 1, l, r, x);
        } else {
            ll tmp = get_sum(1, 0, n - 1, l, r);
            printf("%lld\n", tmp);
        }
    }
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}