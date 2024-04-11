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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"

const int MAXN = 100005;

vector<int> g[MAXN][2];

vector<int> sorted;
int col[MAXN], cl;
vector<int> vals[MAXN];
int cost[MAXN];

void dfs(int s, int ind){
    col[s] = cl;
    if (ind){
        vals[cl].pb(cost[s]);
    }
    for(int i = 0; i < (int)g[s][ind].size(); i++){
        int to = g[s][ind][i];
        if (!col[to]){
            dfs(to, ind);
        }
    }
    if (ind == 0){
        sorted.pb(s);
    }
}

const int INF = 2e9;
const long long MOD = 1000000007;

void solve(){
    int n, m, a, b, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &cost[i]);
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        g[a][0].pb(b);
        g[b][1].pb(a);
    }
    cl = 1;
    for(i = 1; i <= n; i++){
        if (!col[i]){
            dfs(i, 0);
    //      cout << "*";
        }
    }
    /*for(i = 0; i < n; i++){
        printf("%d ", sorted[i]);
    }*/
    //putchar('\n');
    cl = 1;
    for(i = 1; i <= n; i++){
        col[i] = 0;
    }
    for(i = n - 1; i >= 0; i--){
        if (!col[sorted[i]]){
    //      printf("%d ", sorted[i]);
            dfs(sorted[i], 1);
            cl++;
        }
    }
    long long ans = 1;
    long long ans_cost = 0;
    for(i = 1; i < cl; i++){
        int mn = INF;
        long long num = 1;
        for(j = 0; j < (int)vals[i].size(); j++){
            if (vals[i][j] < mn){
                mn = vals[i][j];
                num = 0;
            }
            if (vals[i][j] == mn){
                num++;
            }
        }
        ans = (ans * num) % MOD;
        ans_cost += mn;
    }
    cout << ans_cost << endl << ans << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}