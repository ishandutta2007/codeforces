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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 5005;
int col[MAXN];
int time[MAXN], prv[MAXN], tt, n, top;
queue<int> qq;

set<pair<int, int> > ww[MAXN], tmp;
set<pair<int, int> >::iterator it;

vector<pair<int, int> > g[MAXN];

int per[MAXN], lim[MAXN];

void bfs(){
    int i, s, to, j;
    for(i = 0; i < top; i++){
        to = per[i];
        s = prv[to];
        if (ww[to].empty())
            continue;
        for(j = 0, it = ww[to].begin(); it != ww[to].end() && j < lim[i]; it++, j++){
            if (s == 1){
                time[it->second] = tt;
            }
        }
        if (j < 3 * (ww[to].size() + ww[s].size()) / 5){
            ww[s].insert(ww[to].begin(), it);
            ww[to].erase(ww[to].begin(), it);
        }
        else{
            swap(ww[s], ww[to]);
            tmp = ww[to];
            ww[to].clear();
            ww[to].insert(it, ww[s].end());
            ww[s].erase(it, ww[s].end());
            ww[s].insert(tmp.begin(), tmp.end());
        }
    }
}

void bfs1(){
    qq.push(1);
    int i, s, to, j;
    col[1] = 1;
    while(!qq.empty()){
        s = qq.front(); 
        qq.pop();
        for(i = 0; i < (int)g[s].size(); i++){
            to = g[s][i].first;
            if (col[to])
                continue;
            prv[to] = s;
            lim[top] = g[s][i].second;
            per[top++] = to;
            col[to] = 1;
            qq.push(to);
        }
    }
}
    
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a, b, i, c;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a);
        ww[i].insert(mp(a, i));
    }
    for(i = 1; i < n; i++){
        scanf("%d%d%d", &a, &b, &c);
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }
    bfs1();
    time[1] = 0;
    while(1){
        if (ww[1].size() == n)
            break;
        tt++;
        bfs();
    }
    for(i = 1; i <= n; i++){
        printf("%d ", time[i]);
    }
}