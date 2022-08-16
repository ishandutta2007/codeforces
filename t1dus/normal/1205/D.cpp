#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define vi vector<int>
#define pb push_back

int n;
vi adj[1005];
int sz[1005];
int par[1005];
int centroid;

void dfs(int u,int p){
    sz[u] = 1;
    par[u] = p;
    for(auto v:adj[u]){
        if(v != p){
            dfs(v,u);
            sz[u] += sz[v];
        }
    }
}

void solve(int u,int p,int jump){
    int cur = jump;
    for(auto v:adj[u]){
        if(v == p) continue;
        cout << u << " " << v << " " << cur << "\n";
        solve(v,u,jump);
        cur += jump*sz[v];
    }
}

signed main(){
    cin >> n;
    REP(i,n-1){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
    FOR(i,1,n+1){
        bool flag = 1;
        for(auto u:adj[i]){
            if(u != par[i]){
                if(sz[u] > n/2) flag = 0;
            }
        }
        if(n-sz[i] > n/2) flag = 0;
        if(flag){
            centroid = i;
            break;
        }
    }
    dfs(centroid,centroid);
    vector<pair<int,int> > gg;
    vi v1,v2;
    for(auto u:adj[centroid]){
        gg.pb({sz[u],u});
    }
    sort(gg.begin(),gg.end());
    reverse(gg.begin(),gg.end());
    int cur = 0;
    for(auto x:gg){
        if(cur+x.first < n/2){
            cur += x.first;
            v1.pb(x.second);
        }
        else v2.pb(x.second);
    }
    cur = 1;
    for(auto x:v1){
        cout << centroid << " " << x << " " << cur << "\n";
        solve(x,centroid,1);
        cur += sz[x];
    }
    int cur2 = cur;
    for(auto x:v2){
        cout << centroid << " " << x << " " << cur2 << "\n";
        solve(x,centroid,cur);
        cur2 += cur*sz[x];
    }
}