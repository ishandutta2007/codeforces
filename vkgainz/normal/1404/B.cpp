#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
vector<int> adj[100001];
int dist[100001];
void solve(){
    int n,a,b,da,db; cin >> n >> a >> b >> da >> db;
    --a; --b;
    for(int i=0;i<=n;i++) adj[i].clear();
    
    for(int i=0;i<n-1;i++){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    for(int i=0;i<=n;i++) dist[i] = -1;
    dist[0] = 0;
    int bestIdx = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(dist[x]>dist[bestIdx])
            bestIdx= x;
        for(int next : adj[x]){
            if(dist[next]==-1){
                dist[next] = dist[x]+1;
                q.push(next);
            }
        }
    }
    for(int i=0;i<=n;i++) dist[i] = -1;
    dist[bestIdx] = 0;
    q.push(bestIdx);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(dist[x]>dist[bestIdx])
            bestIdx = x;
        for(int next : adj[x]){
            if(dist[next]==-1){
                dist[next] = dist[x]+1;
                q.push(next);
            }
        }
    }
    int diam = dist[bestIdx];
    for(int i=0;i<=n;i++) dist[i] = -1;
    dist[a] = 0;
    q.push(a);
    while(!q.empty()){
        int x=  q.front();
        q.pop();
        for(int next : adj[x]){
            if(dist[next]==-1){
                dist[next] = dist[x]+1;
                q.push(next);
            }
        }
    }
    if(da>=(diam+1)/2){
        cout << "Alice" << endl;
    }
    else if(dist[b]<=da){
        cout << "Alice" << endl;
    }
    else if(da>=(db+1)/2){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
    }
 
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}