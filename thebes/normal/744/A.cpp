#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
int n, m, k, i, j, x, y, vis[MN], vis2[MN], tot, u[100*MN], rem;
vector<int> g, rt;
vector<pair<int,int>> adj[MN];
int dfs(int n){
    vis[n] = 1; int ret = 1;
    for(auto v : adj[n])
        if(!vis[v.first]) ret += dfs(v.first);
    return ret;
}
int dfs2(int n){
    int e = 0; vis2[n]=1;
    for(auto v : adj[n]){
        if(!vis2[v.first]) e+=dfs2(v.first);
        if(!u[v.second]) e++, u[v.second]=1;
    }
    return e;
}
int main(){
    for(scanf("%d%d%d",&n,&m,&k),i=1;i<=k;i++)
        scanf("%d",&x), g.push_back(x);
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }
    for(auto v : g){
        rt.push_back(dfs(v));
        rem += dfs2(v);
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            tot += dfs(i);
            rem += dfs2(i);
        }
    }
    sort(rt.begin(),rt.end(),[](int i,int j){return i>j;});
    int sz = rt[0]+tot;
    int ans = sz*(sz-1)/2;
    for(i=1;i<rt.size();i++)
        ans += rt[i]*(rt[i]-1)/2;
    printf("%d\n",ans-rem);
    return 0;
}