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

const int INF = 1e8;
const int MAXN = 5e5 + 5;

vector<pii> qq_left[MAXN];
pii a[MAXN];
int seg_left[MAXN];
int ans[MAXN];

int tt[4 * MAXN];

void build(int ind, int tl, int tr){
    tt[ind] = INF;
    if (tl == tr){
        return;
    }
    int tm = (tl + tr) >> 1;
    build(ind << 1, tl, tm);
    build((ind << 1) + 1, tm + 1, tr);
}

int get_mn(int ind, int tl, int tr, int l, int r){
    if (tl == l && tr == r){
        return tt[ind];
    }
    if (l > tr || r < tl){
        return INF;
    }
    int tm = (tl + tr) >> 1;
    return min(get_mn(ind << 1, tl, tm, l, min(r, tm)), get_mn((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

void upd(int ind, int tl, int tr, int pos, int val){
    if (tl == tr){
        tt[ind] = min(tt[ind], val);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm){
        upd(ind << 1, tl, tm, pos, val);
    } else {
        upd((ind << 1) + 1, tm + 1, tr, pos, val);
    }
    tt[ind] = min(tt[ind << 1], tt[(ind << 1) + 1]);
}

void solve(){
    int n, q, i, j, l, r, tmp, ind;
    scanf("%d%d", &n, &q);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    for(i = 0; i < n; i++){
        seg_left[i] = INF;
    }
    for(i = 1; i < n; i++){
        if (a[i - 1].first == a[i].first){
            seg_left[a[i].second] = a[i - 1].second;
        }
    }
    build(1, 0, n - 1);
    for(i = 0; i < q; i++){
        scanf("%d%d", &l, &r);
        l--;
        r--;
        qq_left[r].pb(mp(l, i));
    }
    for(i = 0; i < n; i++){
        tmp = seg_left[i];
        if (tmp != INF) {
            upd(1, 0, n - 1, tmp, i - tmp);
        }
        for(j = 0; j < (int)qq_left[i].size(); j++){
            tmp = qq_left[i][j].first;
            ind = qq_left[i][j].second;
            ans[ind] = get_mn(1, 0, n - 1, tmp, i);
            if (ans[ind] == INF){
                ans[ind] = -1;
            }
        }
    }
    for(i = 0; i < q; i++){
        printf("%d\n", ans[i]);
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