#include<bits/stdc++.h>
using namespace std;
const int N = 200009;
#define ll long long
int n,m,st,pre[N],pot;ll a[N];
struct pp{int nxt,to;}p[N<<1],g[N<<1];
void Add(int u,int v){
    p[++pot].nxt=pre[u],p[pot].to=v,pre[u]=pot;
}
void init(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);Add(u,v);Add(v,u);
    }
    scanf("%d",&st);
    return ;
}
int idx,dfn[N],low[N];
int s[N],top,cnt,bl[N],ins[N];

void Tarjan(int u,int fa){
    dfn[u]=low[u]=++idx;
    s[++top]=u,ins[u]=1;
    for(int i=pre[u];i!=-1;i=p[i].nxt){
        int v=p[i].to;if(v==fa) continue;
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        ++cnt;
        do{
            bl[s[top]]=cnt;
            ins[s[top]]=0;
        }while(s[top--]!=u);
    }
}
int siz[N],head[N],tot;ll w[N];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
void rebuild(){
    memset(head,-1,sizeof(head));tot=0;
    for(int u=1;u<=n;u++)
        for(int i=pre[u];i!=-1;i=p[i].nxt){
            int v=p[i].to;
            if(bl[u]!=bl[v]) add(bl[u],bl[v]);
        }
    return ;
}
int flag[N];ll ans;
int dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        if(dfs(v,u)==1) flag[u]=1;
    }
    if(siz[u]>1) flag[u]=1;
    if(flag[u]==1) ans+=w[u],w[u]=0;
    return flag[u];
}
ll dfs2(int u,int fa){
    ll mx=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        mx=max(mx,dfs2(v,u));
    }
    return mx+w[u];
}
int main(){
    memset(pre,-1,sizeof(pre));pot=0;
    init();
    idx=cnt=top=0;
    memset(ins,0,sizeof(ins));
    memset(siz,0,sizeof(siz));
    memset(w,0,sizeof(w));
    Tarjan(st,0);
    for(int i=1;i<=n;i++) siz[bl[i]]++,w[bl[i]]+=a[i];
    rebuild();
    memset(flag,0,sizeof(flag));ans=0;
    flag[bl[st]]=dfs(bl[st],0);
    ans+=dfs2(bl[st],0);
    printf("%lld\n",ans);
    return 0;
}