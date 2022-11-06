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

const int maxn = 80005;

vector<int> g[maxn];

long long dp[maxn], dp1[maxn], v[maxn], sz[maxn], sz1[maxn], sz2[maxn];
char col[maxn];
int prv[maxn];
long long ans;
int n;

void dfs(int s){
    int i, to;
    long long tmp_cnt;
    col[s] = 1;
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (!col[to]){
            prv[to] = s;
            dfs(to);
            sz[s] += sz[to] + 1;
        }
    }
    dp[s] = sz[s] * (sz[s] + 1) / 2;
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (to != prv[s]){

            sz1[s] += sz[to] * (sz[to] + 1) / 2;

            dp[s] -= sz[to] * (sz[to] + 1) / 2;
            tmp_cnt = (long long)n - sz[to] - 1;
            ans += dp[to] * tmp_cnt * (tmp_cnt - 1) / 2;
        }
    }
}

/*void dfs1(int s){
    int i, to;
    ans += v[s];
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (to != prv[s]){
            v[to] = v[s] - dp[to];
            dfs1(to);
        }
    }
}*/

void dfs1(int s){
    int i, to;
    long long tmp_cnt, tmp_cnt1;
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (to != prv[s]){
            sz2[to] = sz2[s] + sz1[s] - sz[to] * (sz[to] + 1) / 2;
            tmp_cnt = (long long)n - sz[to] - 1;
            tmp_cnt1 = tmp_cnt * (tmp_cnt - 1) / 2 - sz2[to];
            ans += dp[to] * tmp_cnt1;
            dfs1(to);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int i, a, b;
    scanf("%d", &n);
    if (n < 4){
        printf("0");
        return 0;
    }
    for(i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    for(i = 1; i <= n; i++){
        if (g[i].size() == 1){
            dfs(i);
            //v[i] = (long long)(n - 1) * (long long)(n - 2) / 2ll;
            dfs1(i);
            //ans -= (long long)(n - 1) * (long long)(n - 2) / 2ll;
            cout << ans;
            return 0;
        }
    }
    i = i;
}