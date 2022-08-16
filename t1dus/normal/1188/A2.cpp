#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second

const int MX = 100005;

int n;
vector<pii> adj[MX];
vector<pair<pii,int> > ans;
int leaf[MX];

void dfs1(int u,int p){
    leaf[u] = u;
    for(auto v:adj[u]){
        if(v.F == p) continue;
        dfs1(v.F,u);
        leaf[u] = leaf[v.F];
    }
}

int find_leaf(int u,int p){
    if(adj[u].size() == 1) return u;
    for(auto v:adj[u]){
        if(v.F != p) return find_leaf(v.F,u);
    }
}

void add_path(int u,int p,int l,int val){
    if(u == l) return;
    int l1 = -1,l2 = -1;
    for(auto v:adj[u]){
        if(v.F == p) continue;
        if(leaf[v.F] == l) continue;
        if(l1 == -1) l1 = leaf[v.F];
        else{
            l2 = leaf[v.F];
            break;
        }
    }
    if(l2 == -1){
        l2 = find_leaf(p,u);
    }
    ans.pb({{l,l1},val/2});
    ans.pb({{l,l2},val/2});
    ans.pb({{l1,l2},-val/2});
}

void dfs2(int u,int p){
    for(auto v:adj[u]){
        if(v.F == p) continue;
        add_path(u,p,leaf[v.F],v.S);
        add_path(v.F,u,leaf[v.F],-v.S);
        dfs2(v.F,u);
    }
}

signed main(){
    cin >> n;
    REP(i,n-1){
        int u,v,w; cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    if(n == 2){
        cout << "YES\n1\n";
        cout << "1 2 " << adj[1][0].S << "\n";
        return 0;
    }
    FOR(i,1,n+1){
        if(adj[i].size() == 2){
            cout << "NO\n";
            return 0;
        }
    }
    FOR(i,1,n+1){
        if(adj[i].size() != 1){
            dfs1(i,i);
            dfs2(i,i);
            break;
        }
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto x: ans){
        cout << x.F.F << " " << x.F.S << " " << x.S << "\n";
    }
}