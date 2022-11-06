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

const int MAXN = 100005, INF = 1e9;

vector<int> g[MAXN];
int dis[MAXN], dis2[MAXN], used[MAXN], goods[MAXN], n;
queue<int> qq;
vector<int> ss, ans;

void bfs(){
    int i, s, to;
    for(i = 1; i <= n; i++){
        dis[i] = INF;
        used[i] = 0;
    }
    for(i = 0; i < (int)ss.size(); i++){
        dis[ss[i]] = 0;
        used[ss[i]] = 1;
        qq.push(ss[i]);
    }
    while(!qq.empty()){
        s = qq.front();
        qq.pop();
        for(i = 0; i < (int)g[s].size(); i++){
            to = g[s][i];
            if (dis[to] > dis[s] + 1){
                used[to] = 1;
                dis[to] = dis[s] + 1;
                qq.push(to);
            }
        }
    }

}

void solve(){
    int m, d, a, b, i;
    scanf("%d%d%d", &n, &m, &d);
    for(i = 1; i <= m; i++){
        scanf("%d", &a);
        goods[a] = 1;
    }
    for(i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    for(i = 1; i <= n; i++){
        if (goods[i]){
            a = i;
            break;
        }
    }
    ss.pb(a);
    bfs();
    ss.clear();
    int mini = a;
    for(i = 1; i <= n; i++){
        if (goods[i] && dis[i] > dis[mini]){
            mini = i;
        }
    }
    ss.pb(mini);
    bfs();
    a = mini;
    ss.clear();
    for(i = 1; i <= n; i++){
        dis2[i] = dis[i];
    }
    for(i = 1; i <= n; i++){
        if (goods[i] && dis[i] > dis[mini]){
            mini = i;
        }
    }
    ss.pb(mini);
    bfs();
    int r = dis[a];
    ss.clear();
    for(i = 1; i <= n; i++){
        if (r % 2 == 0 && dis[i] == dis2[i] && dis[i] == r / 2){
            ss.pb(i);
        }
        else if (r % 2 == 1 && (dis[i] == r / 2 || dis2[i] == r / 2) && dis[i] + dis2[i] == r){
            ss.pb(i);
        }
    }
    bfs();
    for(i = 1; i <= n; i++){
        if (dis[i] <= d - (r + 1) / 2){
            ans.pb(i);
        }
    }
    printf("%d\n", ans.size());
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