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

vector<int> g[MAXN];
int v[MAXN], used[MAXN], prv[MAXN];
vector<int> ans;

void dfs(int s){
    int i, to;
    used[s] = 1;
    v[s] ^= 1;
    ans.pb(s);
    for(i = 0; i < (int)g[s].size(); i++){
        to = g[s][i];
        if (!used[to]){
            prv[to] = s;
            dfs(to);
            v[s] ^= 1;
            ans.pb(s);
        }   
    }
    if (v[s] && prv[s]){
        v[s] ^= 1;
        v[prv[s]] ^= 1;
        ans.pb(prv[s]);
        ans.pb(s);
    }
}

void solve(){
    int n, m, a, b, i, s;
    scanf("%d%d", &n, &m);
    for(; m; m--){
        scanf("%d%d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    s = 0;
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
        if (v[i] == 1){
            s = i;
        }
    }
    if (s == 0){
        printf("0\n");
        return;
    }
    dfs(s);
    if (v[s]){
        ans.pop_back();
        v[s] ^= 1;
    }
    for(i = 1; i <= n; i++){
        if (v[i]){
            printf("-1\n");
            return;
        }
    }
    printf("%d\n", (int)ans.size());
    for(i = 0; i < (int)ans.size(); i++){
        printf("%d ", ans[i]);
    }
    putchar('\n');

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