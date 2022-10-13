#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
int subtreesz[200001];
int dp[200001], depth[200001], par[200001];
vector<int> adj[200001];
int a,b;
void dfs(int i){
    ++subtreesz[i];
    for(int next : adj[i]){
        if(depth[next]==0){
            depth[next] = depth[i]+1;
            par[next] = i;
            dfs(next);
            dp[i]+=dp[next];
            subtreesz[i]+=subtreesz[next];
        }
        else{
            if(depth[next]<depth[i]-1 && next!=b){
                ++dp[i];
            }
            if(depth[next]>depth[i]+1){
                --dp[i];
            }
        }
    }
}
void solve(){
    int n,m;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    --a; --b;
    for(int i=0;i<n;i++){
        dp[i] = 0;
        depth[i] = 0;
        par[i] = 0;
        subtreesz[i] = 0;
        adj[i].clear();
    }
    ans = 0;
    depth[a] = 1;
    par[a] = -1;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        sort(adj[i].begin(),adj[i].end());
        auto last = unique(adj[i].begin(),adj[i].end());
        adj[i].erase(last,adj[i].end());
    }
    dfs(a);
    int x =0 ;
    for(auto child : adj[b]){
        if(depth[child]==depth[b]+1 && dp[child]==0){
            x+=subtreesz[child];
        }
    }
    int y = 0;
    while(par[b]!=a){
        b = par[b];
    }
    y = n-subtreesz[b]-1;
    ans = x*1LL*y;
    printf("%lld\n",ans);
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}