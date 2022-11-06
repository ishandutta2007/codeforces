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

vector<int> g[MAXN], gg[MAXN];

int used[MAXN], col[MAXN], cnt[MAXN], bad[MAXN];

void dfs1(int s, int cl){
    int i, to;
    used[s] = 1;
    col[s] = cl;
    cnt[cl]++;
    for(i = 0; i < (int)gg[s].size(); i++){
        to = gg[s][i];
        if (!used[to]){
            dfs1(to, cl);
        }
    }
}

void dfs(int s){
    int i, to;
    used[s] = 1;
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (!used[to]){
            dfs(to);
        } else if (used[to] == 1) {
            bad[col[s]] = 1;
        } 
    }
    used[s] = 2;
}

void solve(){
    int n, m, i, a, b, cl;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        gg[a].pb(b);
        gg[b].pb(a);
    }
    int ans = 0;
    cl = 1;
    for(i = 1; i <= n; i++){
        if (!used[i]){
            dfs1(i, cl++);
        }
    }
    for(i = 1; i <= n; i++){
        used[i] = 0;
    }
    for(i = 1; i <= n; i++){
        if (!used[i]){
            dfs(i);
        }
    }
    for(i = 1; i < cl; i++){
        ans += cnt[i] - 1 + bad[i]; 
    }
    printf("%d\n", ans);
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