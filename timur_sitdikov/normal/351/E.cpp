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

const int MAXN = 2005, MAXV = 100005;

int p[MAXN], used[MAXN];

vector<int> inds[MAXV];
vector<int> lc, rc;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, k, a, ans, sz, cur, mn, ind;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        inds[abs(a)].pb(i);
    }
    ans = 0;
    for(i = 0; i < MAXV; i++){
        if (inds[i].empty()){
            continue;
        }
        sz = inds[i].size();
        lc.assign(sz, 0);
        rc.assign(sz, 0);
        k = 0;

        for(j = 0; j < n; j++){
            if (k < sz && j > inds[i][k]){
                k++;
            }
            if (used[j] && k < sz){
                lc[k]++;
            }
        }
        for(k = 1; k < sz; k++){
            lc[k] += lc[k - 1];
        }

        k = sz - 1;
        for(j = n - 1; j >= 0; j--){
            if (k >= 0 && j < inds[i][k]){
                k--;
            }
            if (used[j] && k >= 0){
                rc[k]++;
            }
        }
        for(k = sz - 2; k >= 0; k--){
            rc[k] += rc[k + 1];
        }

        mn = 0;
        for(k = 0; k < sz; k++){
            mn += rc[k];
        }
        cur = mn;
        for(k = 0; k < sz; k++){
            cur = cur - rc[k] + lc[k];
            if (cur < mn){
                mn = cur;
            }
        }
        ans += mn;
        for(k = 0; k < sz; k++){
            used[inds[i][k]] = 1;
        }
    }
    printf("%d", ans);
    
}