#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[3001];
int subtreesz[3001];
int depth[3001];
int dist[3001][3001];
ll dp[3001][3001];
void dfs(int curr=0,int par=-1){
    ++subtreesz[curr];
    for(int next : adj[curr]){
        if(next!=par){
            depth[next] = depth[curr]+1;
            dfs(next,curr);
            subtreesz[curr]+=subtreesz[next];
        }
    }
}
int main(){
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    for(int i=0;i<n;i++){
        queue<int> q;
        q.push(i);
        for(int j=0;j<n;j++) dist[i][j] = 5000;
        dist[i][i] = 0;
        
        while(!q.empty()){
            int next = q.front();
            q.pop();
            for(int x : adj[next]){
                if(dist[i][next]+1<dist[i][x]){
                    dist[i][x] = dist[i][next]+1;
                    q.push(x);
                }
            }
        }
    }
    //iterate in order of largest to smallest dist
    vector<pair<int,int>> order;
    vector<pair<int,int>> store[3001];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(j!=i) store[dist[i][j]].push_back({i,j});
    for(int i=3000;i>=0;i--)
        for(auto &it : store[i])
            order.push_back(it);
    for(auto &it : order){
        int x = it.first;
        int y = it.second;
        //iterate over all adjacent points that do not lie on path, take maximum, add as transition state
        if(depth[x]-depth[y]==dist[x][y]){
            for(int next : adj[y])
                if(dist[y][next]+dist[next][x]==dist[y][x]){
                    dp[x][y] = subtreesz[x]*1LL*(n-subtreesz[next]);
                }
        }
        else if(depth[y]-depth[x]==dist[x][y]){
            for(int next : adj[x])
                if(dist[y][next]+dist[next][x]==dist[y][x]){
                    dp[x][y] = subtreesz[y]*1LL*(n-subtreesz[next]);
                }
        }
        else{
            dp[x][y] = subtreesz[x]*1LL*subtreesz[y];
        }
        ll add = 0;
        for(int next : adj[x])
            if(dist[x][next]+dist[next][y]!=dist[x][y])
                add = max(add,dp[next][y]);
        for(int next : adj[y])
            if(dist[x][next]+dist[next][y]!=dist[x][y])
                add = max(add,dp[next][x]);
        dp[x][y]+=add;
    }
    ll ret = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ret = max(ret,dp[i][j]);
    cout << ret << endl;
    
    
}