#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define vi vector<int>
#define pb push_back

const int MX = 100005;

int n;
vi adj[MX];

signed main(){
    cin >> n;
    REP(i,n-1){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i,1,n+1){
        if(adj[i].size() == 2){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}