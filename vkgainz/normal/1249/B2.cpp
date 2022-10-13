#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[200001];
int ans[200001];
bool visited[200001];
vector<int> in;
void dfs(int i){
    in.push_back(i);
    visited[i] = true;
    for(int next : adj[i]){
        if(!visited[next])
            dfs(next);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    int p[n];
    for(int i=0;i<n;i++)
        adj[i].clear();
    for(int i=0;i<n;i++) visited[i] = false;
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        --p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            in.clear();
            dfs(i);
            for(auto &x : in) ans[x] =in.size();
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}
int main(){
    int q; scanf("%d",&q);
    while(q--){
        solve();
    }
}