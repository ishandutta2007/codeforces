#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define SUMITH_IS_HOT_AF main
vector<int> adj[100001];
vector<pair<int,int>> qin[100001], qout[100001];
int r[100001];
map<int,int> col[100001];
int ans[100001];
int depth[100001];
vector<int> in;
void dfs(int curr,int par){
    ++col[curr][depth[curr]];
    in.push_back(curr);
    for(int next : adj[curr]) if(next!=par) {
        depth[next] = depth[curr]+1;
        dfs(next,curr);
        if(col[next].size()>col[curr].size()) swap(col[curr],col[next]);
        for(auto &it : col[next]){
            col[curr][it.f]+=it.s;
        }
    }
    for(auto q : qin[curr]){
        if(q.f<=in.size()-1){
            qout[in[in.size()-1-q.f]].push_back({q.f,q.s});
        }
    }
    for(auto q : qout[curr]){
        ans[q.s]+=col[curr][depth[curr]+q.f]-1;
    }
    in.pop_back();

}
int SUMITH_IS_HOT_AF(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> r[i];
        --r[i];
        if(r[i]>=0){
            adj[i].push_back(r[i]);
            adj[r[i]].push_back(i);
        }
    }
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int v,p;
        cin >> v >> p;
        --v;
        qin[v].push_back({p,i});
    }
    for(int i=0;i<n;i++) if(r[i]<0) dfs(i,-1);
    for(int i=0;i<m;i++) cout << ans[i] << endl;

}