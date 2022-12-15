#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int d[MN], n, cnt, i, x, vis[MN], vis2[MN], t, tree;
vector<int> adj[MN], rt;
void dfs(int n){
    vis[n] = 1;
    for(auto v : adj[n])
        if(!vis[v]) dfs(v);
}
int fnd(int n){
    vis2[n] = 1;
    if(vis2[d[n]]){
        if(d[n]==n) t=1;
        return n;
    }
    else return fnd(d[n]);
}
int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&d[i]); x=d[i];
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            t=0; dfs(i); int r=fnd(i);
            if(t&&!tree) tree = r;
            else rt.push_back(r);
        }
    }
    for(auto v : rt){
        if(!tree){
            tree = v; d[v] = v;
            cnt++;
        }
        else{
            d[v] = tree;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    for(i=1;i<=n;i++) printf("%d ",d[i]);
    return 0;
}