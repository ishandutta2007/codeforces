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

const int MAXN = 1e5 + 5, MAXLOG = 18;

vector<int> g[MAXN];
int cnt[MAXN], dis[MAXN], tin[MAXN], tout[MAXN], _timer;

int p[MAXN][MAXLOG];

int prv, prva, prvb;

int is_prv(int prv, int a){
    return tin[prv] <= tin[a] && tout[prv] >= tout[a];
}

void lca(int a, int b){
    int i, a1, b1;
    if (is_prv(a, b)){
        prv = a;
        return;
    }
    if (is_prv(b, a)){
        prv = b;
        return;
    }
    prva = a;
    prvb = b;
    for(i = MAXLOG - 1; i >= 0; i--){
        if (!is_prv(p[prva][i], b)){
            prva = p[prva][i];
        }
        if (!is_prv(p[prvb][i], a)){
            prvb = p[prvb][i];
        }
    }
    prv = p[prva][0];
}

void get_prv_by_dis(int a, int dis){
    int i = MAXLOG - 1, j = 1 << (MAXLOG - 1);
    dis--;
    for(prva = a; dis; i--, j >>= 1){
        if (dis >= j){
            prva = p[prva][i];
            dis -= j;
        }
    }
    prv = p[prva][0];
}

void dfs(int s){
    int i, j, to;
    tin[s] = ++_timer;
    cnt[s] = 1;
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (to != p[s][0]){
            p[to][0] = s;
            for(j = 1; j < MAXLOG; j++){
                p[to][j] = p[p[to][j - 1]][j - 1];
            }
            dis[to] = dis[s] + 1;
            dfs(to);
            cnt[s] += cnt[to];
        }
    }
    tout[s] = ++_timer;
}

void solve(){
    int n, q, i, a, b, ans;
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    for(i = 0; i < MAXLOG; i++){
        p[1][i] = 1;
    }
    dfs(1);
    scanf("%d", &q);
    for(; q; q--){
        scanf("%d%d", &a, &b);
        if (a == b){
            printf("%d\n", n);
            continue;
        }
        if ((dis[a] + dis[b]) & 1){
            printf("0\n");
            continue;
        }
        if (dis[a] < dis[b]){
            swap(a, b);
        }
        lca(a, b);
        if (dis[a] == dis[b]){
            ans = n - cnt[prva] - cnt[prvb];
            printf("%d\n", ans);
            continue;
        }
        get_prv_by_dis(a, (dis[a] + dis[b]) / 2 - dis[prv]);
        ans = cnt[prv] - cnt[prva];
        printf("%d\n", ans);
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