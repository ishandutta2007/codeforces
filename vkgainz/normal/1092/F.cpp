#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[200001];
ll ans[200001];
ll vals[200001];
ll depth[200001];
ll sub[200001];
ll tot = 0;
void dfsdist(int curr,int par){
    depth[curr] = depth[par]+1;
    for(int next : adj[curr]){
        if(next!=par){
            dfsdist(next,curr);
        }
    }
}
void dfssubtree(int curr,int par){
    sub[curr]+=vals[curr];
    for(int next : adj[curr]){
        if(next!=par){
            dfssubtree(next,curr);
            sub[curr]+=sub[next];
        }
    }
}
void dfs(int curr,int par){
    if(par!=-1){
        ans[curr] = ans[par]+tot-2*sub[curr];
    }
    for(int next : adj[curr]){
        if(next!=par){
            dfs(next,curr);
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> vals[i];
    for(int i=0;i<n;i++) tot+=vals[i];
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsdist(0,-1);
    for(int i=0;i<n;i++){
        ans[0]+=vals[i]*(depth[i]-depth[0]);
    }
    dfssubtree(0,-1);
    dfs(0,-1);
    ll ret = 0;
    for(int i=0;i<n;i++)
        ret = max(ret,ans[i]);
    cout << ret << endl;
}