#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=300050;

int low[N],disc[N],tid,x[N],y[N];
vector<pair<int,int>> E[N];
bool was[N],bridge[N];

void DFS(int u,int p){
    low[u]=disc[u]=++tid;
    was[u]=true;
    for(auto e:E[u]){
        int v=e.first;
        if(!was[v]){
            DFS(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])bridge[e.second]=true;
        }else{
            if(v!=p)low[u]=min(low[u],disc[v]);
        }
    }
}

int comp[N],nxt;
void DFS1(int u,int p){
    for(auto e:E[u]){
        if(!bridge[e.second]&&!comp[e.first]){
            comp[e.first]=comp[u];
            DFS1(e.first,u);
        }
    }
}

vector<int> G[N];
int dist[N],mx=1;
void DFS2(int u,int p,int dep){
    dist[u]=dep;
    if(dist[u]>=dist[mx])mx=u;
    for(int v:G[u])if(v!=p)DFS2(v,u,dep+1);
}

int main(){
    int n,m;scanf("%i %i",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%i %i",&x[i],&y[i]);
        E[x[i]].pb({y[i],i});
        E[y[i]].pb({x[i],i});
    }
    DFS(1,0);
    for(int i=1;i<=n;i++){
        if(!comp[i]){
            comp[i]=++nxt;
            DFS1(i,i);
        }
    }
    for(int i=1;i<=m;i++){
        if(bridge[i]){
            int u=x[i],v=y[i];
            G[comp[u]].pb(comp[v]);
            G[comp[v]].pb(comp[u]);
        }
    }
    DFS2(1,0,0);
    DFS2(mx,0,0);
    printf("%i",dist[mx]);
    return 0;
}