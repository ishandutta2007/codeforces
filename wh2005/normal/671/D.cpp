#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
const ll inf = 1e14;
const int N = 3e5+9;
int n,m,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}

int dfn[N],nm;
void dfs(int u,int fa){
    dfn[u]=++nm;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs(v,u);
    }
    return ;
}
int rt[N],cnt;
struct seg{ll mn,tag;int ch[2];}t[N*32];
void pushup(int c){
    t[c].mn=inf;
    if(ls(c)) t[c].mn=min(t[c].mn,t[ls(c)].mn);
    if(rs(c)) t[c].mn=min(t[c].mn,t[rs(c)].mn);
    return ;
}
void modify(int &c,int l,int r,int x,ll d){
    if(!c){c=++cnt;t[c].mn=inf,t[c].tag=0;}
    if(l==r){
        t[c].mn=min(d,t[c].mn);
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) modify(ls(c),l,mid,x,d);
    if(x>mid) modify(rs(c),mid+1,r,x,d);
    pushup(c);
    return ;
}
void upd(int c,ll d){
    if(!c) return ;
    t[c].mn+=d,t[c].tag+=d;
    t[c].mn=min(inf,t[c].mn);
    return ;
}
void pushdown(int c){
    if(t[c].tag){
        upd(ls(c),t[c].tag);
        upd(rs(c),t[c].tag);
        t[c].tag=0;
    }
    return ;
}
int merge(int l,int r,int x,int y){
    if(!x||!y) return x+y;
    if(l==r){
        t[x].mn=min(t[x].mn,t[y].mn);
        return x;
    }
    int mid=(l+r)>>1;
    pushdown(x);pushdown(y);
    ls(x)=merge(l,mid,ls(x),ls(y));
    rs(x)=merge(mid+1,r,rs(x),rs(y));
    pushup(x);
    return x;
}
void modi(int c,int l,int r,int x){
    if(!c) return ;
    if(l==r){
        t[c].mn=inf;
        return ;
    }
    pushdown(c);
    int mid=(l+r)>>1;
    if(x<=mid) modi(ls(c),l,mid,x);
    if(x>mid) modi(rs(c),mid+1,r,x);
    pushup(c);
    return ;
}
ll dp[N];
void dfs2(int u,int fa){
    ll sum=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs2(v,u);sum+=dp[v];
    }
    upd(rt[u],sum);
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;upd(rt[v],sum-dp[v]);
        rt[u]=merge(1,n,rt[u],rt[v]);
    }
    modi(rt[u],1,n,dfn[u]);
    dp[u]=t[rt[u]].mn;
    if(u!=1&&dp[u]>=inf){
        printf("-1\n");
        exit(0);
    }
    return ;
}

int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    dfs(1,0);cnt=0;
    for(int i=1;i<=m;i++){
        int x,y,c;scanf("%d%d%d",&x,&y,&c);
        modify(rt[x],1,n,dfn[y],c);
    }
    t[0].mn=inf;
    dfs2(1,0);
    ll ans=0;
    for(int i=head[1];i!=-1;i=g[i].nxt){int v=g[i].to;ans+=dp[v];}
    printf("%lld\n",(ans>=inf)?(-1):ans);
    return 0;
}