#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define vi vector<int>
#define pb push_back

const int MX = 1500005;

int n;
vi adj[MX];
int dep[MX];

void dfs(int u,int p,int d){
    dep[u] = d;
    for(auto v:adj[u]){
        if(v != p) dfs(v,u,d+1);
    }
}

signed main(){
    int t; cin >> t;
    FOR(cs,1,t+1){
        cin >> n;
        int n0 = n;
        REP(i,3*n+1) adj[i].clear();
        REP(i,n-1){
            int u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        FOR(i,1,n0+1){
            char c; cin >> c;
            if(c == 'W'){
                n++;
                adj[i].pb(n);
                adj[n].pb(i);
                n++;
                adj[n].pb(n-1);
                adj[n-1].pb(n);
                n++;
                adj[n].pb(n-2);
                adj[n-2].pb(n);
            }
        }
        bool flag = 0;
        FOR(i,1,n+1){
            if(adj[i].size() >= 4){
                flag = 1;
            }
            else if(adj[i].size() == 3){
                int cnt2 = 0;
                for(auto x:adj[i]){
                    if(adj[x].size() >= 2) cnt2++;
                }
                if(cnt2 >= 2) flag = 1;

            }
        }
        if(flag){
            cout << "White\n";
            continue;
        }
        int u = -1,v = -1;
        FOR(i,1,n+1){
            if(adj[i].size() == 3){
                if(u == -1) u = i;
                else v = i;
            }
        }
        if(v == -1){
            cout << "Draw\n";
            continue;
        }
        dfs(u,u,0);
        if(dep[v]%2) cout << "Draw\n";
        else cout << "White\n";
    }
}