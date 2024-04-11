#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define SUMITH_IS_HOT_AF main
int c[100001];
map<int,int> col[100001];
vector<int> adj[100001];
ll ans[100001];
int mx[100001];
void dfs(int curr,int par){
    col[curr][c[curr]]++;
    ans[curr] = c[curr];
    mx[curr] = 1;
    for(int next : adj[curr]){
        if(next!=par){
            dfs(next,curr);
            if(col[next].size()>col[curr].size()) swap(col[curr],col[next]), ans[curr] = ans[next], mx[curr]=mx[next];
            for(auto &it : col[next]){ 
                col[curr][it.first]+=col[next][it.first];
                if(col[curr][it.first]>mx[curr]){
                    mx[curr] = col[curr][it.first], ans[curr] = 0;
                }
                if(col[curr][it.first]==mx[curr]){
                    ans[curr]+=it.first;
                }
            }
            col[next].clear();
        }
    }
}
int SUMITH_IS_HOT_AF(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<n-1;i++){
        int x,y; cin >> x >> y;
        --x, --y;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++) cout << ans[i] << "\n";
    
}