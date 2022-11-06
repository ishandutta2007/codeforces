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

const int MAXN = 8e5 + 5;

const ll INF = 1e17;

struct edge{
    int s, to, w, tt;
    edge(){}
    edge(int _s, int _to, int _w, int _tt){
        s = _s, to = _to, w = _w, tt = _tt;
    }
} ee[2 * MAXN];

vector<int> g[MAXN];
int val[MAXN];
ll dis[MAXN];
int prv_fl[MAXN];

int n;

set<pair<ll, int> > st;

void go(){
    int i, s, to, ind;
    for(i = 1; i <= n; i++){
        dis[i] = INF;
        prv_fl[i] = 1;
    }
    dis[1] = 0;
    for(i = 1; i <= n; i++){
        st.insert(mp(dis[i], i));
    }
    while(!st.empty()){
        s = st.begin()->second;
        st.erase(st.begin());
        for(i = 0; i < (int)g[s].size(); i++){
            ind = g[s][i];
            to = ee[ind].to;
            ll d = ee[ind].w + dis[s];
            if (dis[to] > d){
                //printf("%d %d %d\n", s, to, ee[ind].tt);
                prv_fl[to] = ee[ind].tt;
                st.erase(mp(dis[to], to));
                dis[to] = d;
                st.insert(mp(dis[to], to));
                //printf("%d\n", prv_fl[to]);
            } else if (dis[to] == d){
                //printf("%d %d %d\n", s, to, ee[ind].tt);
                prv_fl[to] = min(prv_fl[to], ee[ind].tt);
                //printf("%d\n", prv_fl[to]);
            }
        }
    }
}

void solve(){
    int m, k, i, cnt, a, b, c;
    scanf("%d%d%d", &n, &m, &k);
    cnt = 0;
    for(i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        ee[cnt] = edge(a, b, c, 0);
        g[a].pb(cnt);
        cnt++;
        ee[cnt] = edge(b, a, c, 0);
        g[b].pb(cnt);
        cnt++;
    }
    for(i = 0; i < k; i++){
        a = 1;
        scanf("%d%d", &b, &c);
        val[b]++;
        ee[cnt] = edge(a, b, c, 1);
        g[a].pb(cnt);
        cnt++;
        ee[cnt] = edge(b, a, c, 1);
        g[b].pb(cnt);
        cnt++;
    }
    go();
    int ans = 0;
    for(i = 2; i <= n; i++){
        //printf("%d %d\n", i, val[i]);
        //printf("%d %lld\n", i, dis[i]);
        if (!prv_fl[i]){
            ans += val[i];
        } else {
            ans += val[i] - 1;
        }
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