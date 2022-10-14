#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=1000050;
const int L=20;

int par[N][L],lid[N],rid[N],tid,dep[N],nxt=5,u=2,v=3,ans=2;
vector<int> E[N];

void DFS(int u,int p){
    par[u][0]=p;
    for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
    lid[u]=++tid;
    for(int v:E[u])if(v!=p){
        dep[v]=dep[u]+1;
        DFS(v,u);
    }
    rid[u]=tid;
}

bool anc(int u,int v){
    return lid[u]<=lid[v] && rid[v]<=rid[u];
}

int LCA(int u,int v){
    if(anc(u,v)) return u;
    if(anc(v,u)) return v;
    for(int i=L-1;i>=0;i--) if(par[u][i]>0 && !anc(par[u][i],v)) u=par[u][i];
    return par[u][0];
}

int dist(int u,int v){
    return dep[u]+dep[v]-2*dep[LCA(u,v)];
}

void Update(int i) {
    int x=dist(i,u);
    int y=dist(i,v);
    if(x>ans)ans=x,v=i;
    if(y>ans)ans=y,u=i;
}

int main(){
    int q;scanf("%i",&q);
    for(int i=2;i<=4;i++)E[1].pb(i);
    while(q--){
        int p;scanf("%i",&p);
        E[p].pb(nxt++);
        E[p].pb(nxt++);
    }
    DFS(1,0);
    for(int i=5;i<nxt;i+=2){
        Update(i);
        Update(i+1);
        printf("%i\n",ans);
    }
    return 0;
}