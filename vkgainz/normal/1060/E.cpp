#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> adj[200001];
vector<pair<ll, ll>> num[200001];
vector<pair<ll, ll>> dist[200001];
void solveDist(int curr,int par){
    ll even = 0;
    ll odd = 0;
    for(int x : adj[curr]){
        if(x!=par){
            solveDist(x,curr);
            even+=dist[x][0].first;
            odd+=dist[x][0].second+num[x][0].second;
        }
    }
    dist[curr].push_back({odd,even});
}
void solveNum(int curr,int par){
    ll even =1;
    ll odd =0;
    for(int x : adj[curr]){
        if(x!=par){
            solveNum(x,curr);
            even+=num[x][0].first;
            odd+=num[x][0].second;
        }
    }
    num[curr].push_back({odd,even});

}

void dfs(int curr,int par){
    if(par==-1){
        for(int x : adj[curr]){
            dfs(x,curr);
        }
        return;
    }
    ll even = 0;
    ll odd = 0;
            even=dist[par][0].first-num[curr][0].second;
        odd = dist[par][0].second+num[par][0].second-num[curr][0].first;      

    num[curr][0].first = num[par][0].second;
    num[curr][0].second = num[par][0].first;
    dist[curr][0].first= odd;
    dist[curr][0].second = even;
     for(int x : adj[curr]){
         if(x!=par){
             dfs(x,curr);
         }
     }
}

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solveNum(0,-1);
    solveDist(0,-1);
    dfs(0,-1);
    ll ans =0;
    for(int i=0;i<n;i++){
        ans+=dist[i][0].first+dist[i][0].second;
   }
    ans/=2;
    cout << ans << endl;
}