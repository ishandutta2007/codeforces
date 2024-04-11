#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<pair<int,int>,int> weights;
vector<int> adj[300001];
int depth[300001];
int par[300001];
int dp[300001];
int ans[300001][2];
void dfs(int curr){
    for(int next : adj[curr]){
        if(depth[next]==0){
            depth[next] = depth[curr]+1;
            par[next]= curr;
            dfs(next);
            dp[curr]+=dp[next];
        }
    }
    for(int next : adj[curr]){
        if(depth[next]<depth[curr]-1)
            ++dp[curr];
        if(depth[next]>depth[curr]+1)
            --dp[curr];
    }
    if(dp[curr]==0 && par[curr]!=-1){
        weights[make_pair(curr,par[curr])] = 1;
        weights[make_pair(par[curr],curr)] = 1;
    }
}
void dfs2(int curr,int par){
    for(int next : adj[curr]){
        if(depth[next]==depth[curr]+1){
            dfs2(next,curr);
            ans[curr][0] = max(ans[curr][0],ans[next][0]+weights[make_pair(curr,next)]);
        }
    }
}
void dfs3(int curr,int par){
    if(par!=-1){
        ans[curr][1] = max(ans[curr][1],ans[par][1]+weights[make_pair(curr,par)]);
    }
    multiset<int,greater<int>> m;
    m.insert(0);
    for(int next : adj[curr]){
        if(depth[next]==depth[curr]+1){
            m.insert(ans[next][0]+weights[make_pair(curr,next)]);
        }
    }
    for(int next : adj[curr]){
        if(depth[next]==depth[curr]+1){
            m.erase(m.lower_bound(ans[next][0]+weights[make_pair(curr,next)]));
            auto it = m.begin();
            ans[next][1] = max(ans[next][1],(*it)+weights[make_pair(curr,next)]);
            m.insert(ans[next][0]+weights[make_pair(curr,next)]);
            dfs3(next,curr);
        }
    }
}
int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[0] = -1;
    depth[0] = 1;
    dfs(0);
    dfs2(0,-1);
    dfs3(0,-1);
    int ret = 0;
    for(int i=0;i<n;i++) ret = max(ret,max(ans[i][0],ans[i][1]));
    cout << ret << "\n";
}