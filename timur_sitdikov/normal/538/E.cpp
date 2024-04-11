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

const int MAXN = 2e5 + 5, INF = 1e8;

vector<int> g[MAXN];

int cnt[MAXN], a1[MAXN], b1[MAXN], a2[MAXN], b2[MAXN], used[MAXN], dis[MAXN];

void dfs(int s){
    int i, to, mna1 = INF, mnb1 = INF, suma1 = 0, sumb1 = 0, mna2 = INF, mnb2 = INF, suma2 = 0, sumb2 = 0, st = 0;
    used[s] = 1;
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (used[to]){
            continue;
        }
        dis[to] = dis[s] + 1;
        dfs(to);
        st++;
        cnt[s] += cnt[to];
        mna1 = min(mna1, a1[to]);
        mnb1 = min(mnb1, cnt[to] - b1[to]);
        suma1 += a1[to];
        sumb1 += b1[to];
        mna2 = min(mna2, a2[to]);
        mnb2 = min(mnb2, cnt[to] - b2[to]);
        suma2 += a2[to];
        sumb2 += b2[to];

    }
    if (cnt[s] == 0){
        cnt[s] = 1;
        a1[s] = b1[s] = a2[s] = b2[s] = 1;
        return;
    }
    if (dis[s] & 1){
        b1[s] = suma1 - st + 1;
        b2[s] = mna2;
    } else {
        a1[s] = cnt[s] - mnb1;
        a2[s] = sumb2;
    }
}

void solve(){
    int n, i, aa, bb;
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d%d", &aa, &bb);
        g[aa].pb(bb);
        g[bb].pb(aa);
    }
    dfs(1);
    printf("%d %d\n", a1[1], a2[1]);
    /*for(i = 1; i <= n; i++){
        printf("%d: %d %d %d %d\n", i, a1[i], b1[i], a2[i], b2[i]);
    }*/
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