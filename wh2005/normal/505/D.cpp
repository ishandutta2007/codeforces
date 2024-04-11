#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
const ll mod=1e9+7;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t,ll res=1){for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}

int n,m;
const int MAXN=1e5+7;
vector<int> g[MAXN];
int dfn[MAXN],low[MAXN],sta[MAXN],top,cnt,mark[MAXN],id[MAXN],siz[MAXN],fa[MAXN];
void tarjan(int u){
    mark[u]=1,sta[++top]=u;
    dfn[u]=low[u]=++cnt;
    for(auto v:g[u]){
        if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
        else if(mark[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        do{
            int v=sta[top];
            mark[v]=0;
            id[v]=u;
            siz[u]++;
        }while(sta[top--]!=u);
    }
}
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
void merge(int u,int v){
    u=find(u),v=find(v);
    fa[v]=u;
}
int main(){
    scanf("%d%d",&n,&m);
    for(ri i=1;i<=n;++i) fa[i]=i;
    for(ri i=1;i<=m;++i){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v);
        merge(u,v);
    }
    int ans=n;
    for(ri u=1;u<=n;++u) if(!dfn[u]) tarjan(u);
    for(ri u=1;u<=n;++u) if(find(u)==u) --ans;
    for(ri u=1;u<=n;++u) if(id[u]==u&&siz[u]>1&&!mark[find(u)]) mark[find(u)]=1,++ans;
    printf("%d\n",ans);
}