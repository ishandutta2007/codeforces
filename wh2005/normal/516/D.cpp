#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
const int N = 1e5+9;
int n,m,head[N],tot;
struct pp{int nxt,to;ll val;}g[N<<1];
void add(int u,int v,ll w){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;
}
int rt;ll dep[N],f[N];

void dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dep[v]=dep[u]+g[i].val;dfs(v,u);
    }
    if(dep[u]>dep[rt]) rt=u;
    f[u]=max(f[u],dep[u]);
}

int ans;
int Fa[N],cnt;
int find(int x){return Fa[x]==x?x:(Fa[x]=find(Fa[x]));}
struct node{int ch[2],dst,siz;ll val;}t[N];
void pushup(int x){
    t[x].siz=t[ls(x)].siz+t[rs(x)].siz+1;
}
int New(int x){
    ++cnt;t[cnt].val=f[x],ls(cnt)=rs(cnt)=0,t[cnt].dst=1,t[cnt].siz=1;
    return cnt;
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(t[x].val<t[y].val) swap(x,y);
    rs(x)=merge(rs(x),y);
    pushup(x);
    if(t[ls(x)].dst<t[rs(x)].dst) swap(ls(x),rs(x));
    t[x].dst=t[rs(x)].dst+1;
    return x;
}
void del(int x){
    Fa[x]=Fa[ls(x)]=Fa[rs(x)]=merge(ls(x),rs(x));
    ls(x)=rs(x)=t[x].dst=0,t[x].siz=0;return ;
}

void dfs2(int u,int fa,ll lim){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs2(v,u,lim);
        int fu=find(Fa[u]),fv=find(Fa[v]);
        Fa[u]=merge(fu,fv);
    }
    while(t[find(u)].val-f[u]>lim){
        del(find(u));
    }
    ans=max(ans,t[find(u)].siz);
}


int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dep[1]=0;dfs(1,0);
    dep[rt]=0;dfs(rt,0);
    dep[rt]=0;dfs(rt,0);
    rt=1;
    for(int i=1;i<=n;i++){
        if(f[rt]>f[i]) rt=i;
    }
    scanf("%d",&m);
    while(m--){
        ll lim;
        ans=0,cnt=0;
        for(int i=1;i<=n;i++) Fa[i]=New(i);
        scanf("%lld",&lim);
        dfs2(rt,0,lim);
        printf("%d\n",ans);
    }
    return 0;
}