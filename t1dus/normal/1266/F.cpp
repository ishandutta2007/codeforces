#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define FORD(i,a,b) for(int i = a; i >= b; i --)
#define vi vector<int>
#define pb push_back
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define F first
#define S second

const int MAXN = 500005;

int n;
vi adj[MAXN],gg[MAXN];
map<int,int> freq[MAXN];
int par[MAXN],dep[MAXN],dp[MAXN],dp_par[MAXN],ans[MAXN];

void dfs(int u,int p,int d){
    par[u] = p;
    dep[u] = d;
    dp[u] = 0;
    for(auto v:adj[u]){
        if(v != p){
            dfs(v,u,d+1);
            remax(dp[u],1+dp[v]);
        }
    }
}

void dfs2(int u){
    if(u != 1) remax(dp_par[u],dp_par[par[u]]+1);
    int mx1 = -1,mx2 = -1;
    for(auto v:adj[u]){
        if(v != par[u]){
            if(dp[v] > mx1){
                mx2 = mx1;
                mx1 = dp[v];
            }
            else if(dp[v] > mx2) mx2 = dp[v];
        }
    }
    for(auto v:adj[u]){
        if(v != par[u]){
            if(dp[v] == mx1) dp_par[v] = mx2+2;
            else dp_par[v] = mx1+2;
            dfs2(v);
        }
    }
}

signed main(){
    cin >> n;
    REP(i,n-1){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1,0);
    dp_par[1] = 0;
    dfs2(1);
    FOR(i,1,n+1) ans[i] = 1;
    FOR(i,1,n+1){
        gg[i].pb(0);
        for(auto u:adj[i]){
            if(u == par[i]) gg[i].pb(dp_par[i]);
            else gg[i].pb(1+dp[u]);
        }
        sort(all(gg[i]));
        int sz = (int)gg[i].size();
        // cout << i << ":::::" << sz << endl;
        // for(auto x:gg[i]) cout << x << " ";
        // cout << "\n";
        for(int j = sz-1; j >= 0; j --){
            freq[i][-gg[i][j]] ++;
            remax(ans[gg[i][j]*2],sz-j);
            remax(ans[gg[i][j]*2-1],sz-j);
            if(j == sz-1 or gg[i][j] != gg[i][j+1]){
                remax(ans[gg[i][j]*2+1],sz-j);
            }
        }
    }
    FOR(i,1,n+1){
        for(auto u:adj[i]){
            if(u == par[i]) continue;
            // i is parent of u
            // gg[i] contains 1+dp[u] extra
            // gg[u] contains dp_par[u] extra
            auto it1 = freq[i].begin();
            auto it2 = freq[u].begin();
            int cnt = 0;
            int mn = n;
            // cout << i << "--" << u << "\n";
            while(it1 != freq[i].end() or it2 != freq[u].end()){
                if(it2 == freq[i].end()){
                    cnt += (*it1).S;
                    remin(mn,-(*it1).F);
                    if(-(*it1).F == 1+dp[u]) cnt--;
                    it1++;
                }
                else if(it1 == freq[u].end()){
                    cnt += (*it2).S;
                    remin(mn,-(*it2).F);
                    if(-(*it2).F == dp_par[u]) cnt--;
                    it2++;
                }
                else if(-(*it1).F > -(*it2).F){
                    cnt += (*it1).S;
                    remin(mn,-(*it1).F);
                    if(-(*it1).F == 1+dp[u]) cnt--;
                    it1++;
                }
                else{
                    cnt += (*it2).S;
                    remin(mn,-(*it2).F);
                    if(-(*it2).F == dp_par[u]) cnt--;
                    it2++;
                }
                // cout << mn << " " << cnt << "\n";
                remax(ans[2*mn],cnt);
            }
        }
    }
    FORD(i,n,1) remax(ans[i],ans[i+2]);
    FOR(i,1,n+1) cout << ans[i] << " ";
    cout << "\n";
}