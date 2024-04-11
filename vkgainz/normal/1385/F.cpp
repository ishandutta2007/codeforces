#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
vector<int> adj[200001];
int root;
int sz[200001];
int ret;
int dfs(int i,int p){
    int ans = 0;
    for(int next : adj[i]){
        if(next!=p){
          int x = dfs(next,i);
          ans+=x;
        }       
    }
    vector<int> leaves;
    for(int next : adj[i]){
        if(next!=p && sz[next]==1) leaves.push_back(next);
    }
    for(int j=0;j<leaves.size()/k*k;j++){
        --sz[i];
        --sz[leaves[j]];
    }
    ans+=leaves.size()/k;
    return ans;
}
int dfs2(int i,int p){
    vector<int> leaves;
    int ans= 0 ;
    for(int next : adj[i]){
        if(sz[next]==1) leaves.push_back(next);
    }
    for(int j=0;j<leaves.size()/k*k;j++){
        --sz[i];
        --sz[leaves[j]];
    }
    ans+=leaves.size()/k;
    if(sz[i]!=1) return ans;
    for(int next : adj[i]){
        if(next!=p && sz[next]>0){
            ans+=dfs2(next,i);
        }
    }
    return ans;
}
void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++) adj[i].clear();
    for(int i=0;i<n;i++) sz[i] = 0;
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++sz[v];
        ++sz[u];
    }
    ret =dfs(0,-1)+dfs2(0,-1);
    cout << ret << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}