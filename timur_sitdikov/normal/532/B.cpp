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

const int MAXN = 2e5 + 5;
const ll INF = 1e15;

vector<int> g[MAXN];

ll dp1[MAXN], dp2[MAXN];
int v[MAXN];

void solve(){
    int i, j, n, a;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d%d", &a, &v[i]);
        if (i != 1){
            g[a].pb(i);
        }
    }
    for(i = n; i >= 1; i--){
        if (g[i].size() == 0){
            dp1[i] = v[i];
            dp2[i] = 0;
            continue;
        }
        ll sum = 0, dif = INF, v1;
        int sz = g[i].size();
        for(j = 0; j < sz; j++){
            int to = g[i][j];
            sum += dp1[to];
            dif = min(dif, dp1[to] - dp2[to]);
        }
        if (sz & 1){
            dp2[i] = sum - dif;
            v1 = sum;
        } else {
            dp2[i] = sum;
            v1 = sum - dif;
        }
        dp1[i] = max(dp2[i] + v[i], v1);
    }
    cout << dp1[1] << endl; 
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