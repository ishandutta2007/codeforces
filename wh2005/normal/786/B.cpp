#include<bits/stdc++.h>
#define ll long long
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pii pair<ll ,int >
#define mcp(x,y) make_pair(x,y)
using namespace std;
const int NUM = 1000000;
const int N = 3200009;
int n,m,s;
int head[N],tot,p[N];
struct segmeny{int num;}t[N];
struct pp{int nxt,to;ll val;}g[N];
void add(int u,int v,ll w){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;
}
void build(int c,int l,int r){
    t[c].num=c;
    if(l==r){
        p[l]=c;
        add(c,c+NUM,0);
        add(c+NUM,c,0);
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(c),l,mid);build(rs(c),mid+1,r);
    add(ls(c),c,0);add(c+NUM,(ls(c))+NUM,0);
    add(rs(c),c,0);add(c+NUM,(rs(c))+NUM,0);
    return ;
}
void modify(int c,int l,int r,int x,int y,int u,ll w,int opt){
    if(x<=l&&r<=y){
        if(opt==0){add(u,c+NUM,w);add(u+NUM,c,w);}
        if(opt==1){add(c,u+NUM,w);add(c+NUM,u,w);}
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) modify(ls(c),l,mid,x,y,u,w,opt);
    if(y>mid) modify(rs(c),mid+1,r,x,y,u,w,opt);
    return ;
}
ll dis[N];int vis[N];
priority_queue<pii> q;
void dijkstra(int u){
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    dis[u]=0;q.push(mcp(0,u));
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i!=-1;i=g[i].nxt){
            int v=g[i].to;
            if(dis[v]==-1||dis[v]>dis[x]+g[i].val){
                dis[v]=dis[x]+g[i].val;
                q.push(mcp(-dis[v],v));
            }
        }
    }
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d%d",&n,&m,&s);
    build(1,1,n);
    while(m--){
        int opt,u,x,y;ll w;scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d%lld",&x,&y,&w);
            add(p[x],p[y]+NUM,w);
            add(p[x]+NUM,p[y],w);
        }
        else{
            scanf("%d%d%d%lld",&u,&x,&y,&w);
            if(opt==2)
                modify(1,1,n,x,y,p[u],w,0);
            if(opt==3)
                modify(1,1,n,x,y,p[u],w,1);
        }
    }
    dijkstra(p[s]);
    for(int i=1;i<=n;i++){
        ll ans=-1;
        if(dis[p[i]]!=-1){
            if(ans==-1||dis[p[i]]<ans) ans=dis[p[i]];
        }
        if(dis[p[i]+NUM]!=-1){
            if(ans==-1||dis[p[i]+NUM]<ans) ans=dis[p[i]+NUM];
        }
        printf("%lld ",ans);
    }
    return 0;
}