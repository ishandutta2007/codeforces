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

const int MAXN = 444444;

int tin[MAXN], tout[MAXN], dis[MAXN], val[MAXN], add[MAXN], tt, first[MAXN];
char col[MAXN], col1[MAXN];

int head[MAXN], nxt[MAXN], gg[MAXN], cur_ind[MAXN], tp;

int top;
int vv[MAXN], vval[MAXN], n;

void dfs(int s){
    int i, to;
    col[s] = 1;
    tin[s] = ++tt;
    first[tin[s]] = s;
    for(i = head[s]; i; i = nxt[i]){
        to = gg[i];
        if (!col[to]){
            dis[to] = dis[s] + 1;
            dfs(to);
        }
    }
    tout[s] = ++tt;
}

void dfs1(){
    int i, j, k, s, to;
    for(i = 0, j = 0; i < n; j++){
        if (first[j] == 0){
            continue;
        }
        s = first[j];
        for(k = head[s]; k; k = nxt[k]){
            to = gg[k];
            if (dis[to] > dis[s]){
                add[to] -= add[s];
            }
        }
        i++;
    }
    for(i = 1; i <= n; i++){
        val[i] += add[i];
        add[i] = 0;
    }
}

void solve(){
    int m, sqm, t, a, b, v, i, j, s, ans;
    scanf("%d%d", &n, &m);
    //n = m = 200000;
    for(i = 1; i <= n; i++){
        scanf("%d", &val[i]);
        //val[i] = 0;
    }
    tp = 1;
    for(i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        //a = i;
        //b = i + 1;

        nxt[tp] = head[a];
        gg[tp] = b;
        head[a] = tp;
        tp++;

        nxt[tp] = head[b];
        gg[tp] = a;
        head[b] = tp;
        tp++;
    }
    dfs(1);
    //sqm = (int)sqrt(m - 0.5) + 1;
    sqm = 8000;
    for(i = 0; i < m; i++){
        if (i % sqm == 0){
            for(j = 1; j <= n; j++){
                col1[j] = 0;
                cur_ind[j] = head[j];
                add[j] = 0;
            }
            for(j = 0; j < top; j++){
                add[vv[j]] += vval[j];
            }
            dfs1();
            top = 0;
        }
        scanf("%d", &t);
        //t = 1 + i % 2;
        if (t == 1){
            scanf("%d%d", &a, &v);
            //a = 1;
            //v = 100;
            vv[top] = a;
            vval[top] = v;
            top++;
        }
        else {
            scanf("%d", &a);
            //a = 200000;
            ans = val[a];
            for(j = 0; j < top; j++){
                s = vv[j];
                if (tin[s] <= tin[a] && tout[s] >= tout[a]){
                    if ((dis[a] - dis[s]) & 1){
                        ans -= vval[j];
                    }
                    else {
                        ans += vval[j];
                    }
                }
            }
            printf("%d\n", ans);
        }
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