#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
vector<int> E[N];
int in[N],out[N],t,dist[N],par[N];

void DFS(int u,int p=-1){
    in[u]=++t;
    for(int e:E[u])if(e!=p)dist[e]=dist[u]+1,par[e]=u,DFS(e,u);
    out[u]=++t;
}

int main(){
    int n,q;scanf("%i%i",&n,&q);
    for(int i=1;i<n;i++){
        int u,v;scanf("%i%i",&u,&v);
        E[u].pb(v);
        E[v].pb(u);
    }
    dist[1]=0,par[1]=1,DFS(1);
    while(q--){
        int m;scanf("%i",&m);
        vector<int> b;
        for(int i=0,x;i<m;i++)scanf("%i",&x),b.pb(x);
        int mx=0,u=1;
        for(int v:b)if(dist[v]>mx)mx=dist[v],u=v;
        bool ok=true;
        for(int&v:b)if(v!=u){
            v=par[v];
            if(out[v]<in[u]||in[v]>out[u])ok=false;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}