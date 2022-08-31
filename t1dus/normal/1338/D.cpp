#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define vi vector<int>
#define pb push_back
#define remax(a,b) a = max(a,b)
#define pii pair<int,int>
#define F first
#define S second

const int MX = 100005;

int n;
vi adj[MX];
int dp[MX][2];
int ans = 0;

void dfs(int u,int p){
    int child = adj[u].size();
    if(u > 1) child--;
    dp[u][1] = 0;
    dp[u][0] = 1;
    pii mx0 = {-n,-n},mx1 = {-n,-n};
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v,u);
        
        int x = dp[v][0],y = dp[v][1];
        
        if(x > mx0.F){
            mx0.S = mx0.F;
            mx0.F = x;
        }
        else if(x > mx0.S) mx0.S = x;

        if(y > mx1.F){
            mx1.S = mx1.F;
            mx1.F = y;
        }
        else if(y > mx1.S) mx1.S = y;
        
        remax(dp[u][1],child-1+x);
        remax(dp[u][0],1+y);
    }
    remax(dp[u][0],dp[u][1]);
    remax(ans,dp[u][0]);
    remax(ans,1+mx1.F+mx1.S);
    remax(ans,(u!=1)+child-2+mx0.F+mx0.S);
}

signed main(){
    cin >> n;
    REP(i,n-1){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
    cout << ans << "\n";
}