#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, i, j, x, on[MN], vis[MN], ans;
pair<int,int> a[MN], b[MN];
vector<int> adj[MN], nd[MN];
int dfs1(int n,int p){
    a[n]=b[n]={0,0}; vis[n]=1;
    for(auto v : adj[n]){
        if(v==p||!on[v]) continue;
        pair<int,int> t={dfs1(v,n)+1,v};
        if(t.first>a[n].first)b[n]=a[n],a[n]=t;
        else if(t.first>b[n].first)b[n]=t;
    }
    return a[n].first;
}
void dfs2(int n,int p,int d){
    ans = max(ans, 1+d+a[n].first);
    for(auto v : adj[n]){
        if(v==p||!on[v]) continue;
        if(v==a[n].second) dfs2(v,n,max(d,b[n].first)+1);
        else dfs2(v,n,max(d,a[n].first)+1);
    }
}
int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x); int r=x;
        for(j=2;j*j<=x;j++){
            if(r%j==0){
                nd[j].push_back(i);
                while(r%j==0) r/=j;
            }
        }
        if(r!=1) nd[r].push_back(i);
    }
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(i=2;i<MN;i++){
        for(auto v : nd[i])
            on[v] = 1;
        for(auto v : nd[i]){
            if(vis[v]) continue;
            dfs1(v, 0);
            dfs2(v, 0, 0);
        }
        for(auto v : nd[i])
            on[v] = 0, vis[v] = 0;
    }
    printf("%d\n",ans);
    return 0;
}