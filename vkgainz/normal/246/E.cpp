#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define SUMITH_IS_HOT_AF main
vector<int> adj[100001];
string s[100001];
int ans[100001], depth[100001], par[100001];
map<int,set<string>> col[100001];
vector<pair<int,int>> queries[100001];
void dfs(int curr, int par){
    col[curr][depth[curr]].insert(s[curr]);
    for(int next : adj[curr]) if(next!=par){
        depth[next] = depth[curr]+1;
        dfs(next,curr);
        if(col[next].size()>col[curr].size()) swap(col[curr],col[next]);
        for(auto &it : col[next]){
            col[curr][it.f].insert(it.s.begin(),it.s.end());
        }
    }
    for(auto &q : queries[curr]){
        ans[q.s] = col[curr][q.f+depth[curr]].size();
    }
}
int SUMITH_IS_HOT_AF(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string x;
        int r;
        cin >> x >> r;
        par[i] = --r;
        if(r>=0){
            adj[i].push_back(r);
            adj[r].push_back(i);
        }
        s[i] = x;
    }
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int v,k; cin >> v >> k;
        --v;
        queries[v].push_back({k,i});
    }
    for(int i=0;i<n;i++) if(par[i]==-1) dfs(i,-1);
    for(int i=0;i<m;i++) cout << ans[i] << endl;

}