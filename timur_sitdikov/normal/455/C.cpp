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

const int MAXN = 3e5 + 5;

vector<int> g[MAXN];
int par[MAXN], c[MAXN], l[MAXN], dis[MAXN], prv[MAXN];
int used[MAXN];
vector<int> inds;

int get_par(int v){
    return par[v] == v ? v: par[v] = get_par(par[v]);
}

void dfs(int s, int fl){
    int i, to;
    used[s] = 1;
    if (fl == 0){
        inds.pb(s); 
    }
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (!used[to]){
            dis[to] = dis[s] + 1;
            //prv[to] = s;
            if (fl == 0){
                par[to] = par[s];
            }
            dfs(to, fl);
        }
    }
}

void solve(){
    int n, m, q, a, b, i, t;
    scanf("%d%d%d", &n, &m, &q);
    for(i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    for(i = 1; i <= n; i++){
        par[i] = i;
    }
    for(i = 1; i <= n; i++){
        if (!used[i]){
            inds.clear();
            dfs(i, 0);
            int mx = -1, maxi = 0;
            for(int j = 0; j < (int)inds.size(); j++){
                if (dis[inds[j]] > mx){
                    mx = dis[inds[j]];
                    maxi = inds[j];
                }
                used[inds[j]] = 0;
                dis[inds[j]] = 0;
            }
            dfs(maxi, 1);
            mx = -1, maxi = 0;
            for(int j = 0; j < (int)inds.size(); j++){
                if (dis[inds[j]] > mx){
                    mx = dis[inds[j]];
                    maxi = inds[j];
                }
            }
            /*a = maxi;
            for(int j = 0; j < maxi / 2; j++, a = prv[a]);
            c[i] = a;*/
            l[i] = mx;
        }
    }
    for(; q; q--){
        scanf("%d%d", &t, &a);
        if (t == 1){
            a = get_par(a);
            printf("%d\n", l[a]);
        } else {
            scanf("%d", &b);
            a = get_par(a);
            b = get_par(b);
            if (a == b){
                continue;
            }
            if (l[a] < l[b]){
                swap(a, b);
            }
            par[b] = a;
            l[a] = max(l[a], (l[a] + 1) / 2 + (l[b] + 1) / 2 + 1);
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