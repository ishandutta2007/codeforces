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

const int MAXN = 1000505, MAXL = 21;

int prv[MAXN][MAXL];
int dis[MAXN];

int lca(int a, int b){
    int i;
    for(i = MAXL - 1; i >= 0; i--){
        if (dis[prv[a][i]] >= dis[b]){
            a = prv[a][i];
        }
    }
    for(i = MAXL - 1; i >= 0; i--){
        if (dis[prv[b][i]] >= dis[a]){
            b = prv[b][i];
        }
    }
    if (a == b){
        return a;
    }
    for(i = MAXL - 1; i >= 0; i--){
        if (prv[a][i] != prv[b][i]){
            a = prv[a][i];
            b = prv[b][i];
        }
    }
    return prv[a][0];
}

int get_dis(int a, int b){
    int cur = lca(a, b);
    return dis[a] + dis[b] - 2 * dis[cur];
}

void solve(){
    int n, q, i, j, a, b, da, db, cur, maxdis;
    dis[1] = dis[2] = dis[3] = 1;
    maxdis = 2;
    a = 1;
    b = 2;
    n = 4;
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &cur);
        cur--;
        prv[n][0] = cur;
        dis[n] = dis[cur] + 1;
        for(j = 1; j < MAXL; j++){
            prv[n][j] = prv[prv[n][j - 1]][j - 1];
        }
        dis[n + 1] = dis[n];
        for(j = 0; j < MAXL; j++){
            prv[n + 1][j] = prv[n][j];
        }
        da = get_dis(n, a);
        db = get_dis(n, b);
        if (da >= db && da >= maxdis){
            maxdis = da;
            b = n;
        }
        else if (db >= da && db >= maxdis){
            maxdis = db;
            a = n;
        }
        n += 2;
        printf("%d\n", maxdis);
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