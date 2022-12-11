#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
int n,q;
int fa[N],w[N],tot,st[N][21],dep[N],dfn[N],ct;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;}
struct edge{
    int to,nex;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
struct node{
    int x,y,w;
    bool operator<(const node b)const{
        return w<b.w;
    }
}a[N];
struct SegmentTree{
    int mi[N<<2],mx[N<<2],tmi[N<<2],tmx[N<<2],lazy[N<<2];
    void pushup(int rt){tmi[rt]=min(tmi[rt<<1],tmi[rt<<1|1]);tmx[rt]=max(tmx[rt<<1],tmx[rt<<1|1]);}
    void pushdown(int rt){
        if(!lazy[rt])return;
        if(lazy[rt]==1){
            tmi[rt<<1]=mi[rt<<1];
            tmx[rt<<1]=mx[rt<<1];
            tmi[rt<<1|1]=mi[rt<<1|1];
            tmx[rt<<1|1]=mx[rt<<1|1];
        }
        else{
            tmi[rt<<1]=1e9;
            tmx[rt<<1]=0;
            tmi[rt<<1|1]=1e9;
            tmx[rt<<1|1]=0;
        }
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        lazy[rt]=0;
    }
    void build(int rt,int l,int r){
        lazy[rt]=0;
        if(l==r){mi[rt]=mx[rt]=dfn[l];tmi[rt]=1e9,tmx[rt]=0;return;}
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
        mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L<=l&&r<=R){lazy[rt]=d,tmi[rt]=(d==1?mi[rt]:1e9),tmx[rt]=(d==1?mx[rt]:0);return;}
        pushdown(rt);
        int mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    int querymin(int rt,int l,int r){
        if(l==r)return l;
        if(tmi[rt]==1e9)return 0;
        pushdown(rt);
        int mid=(l+r)>>1;
        if(tmi[rt<<1]<tmi[rt<<1|1])return querymin(rt<<1,l,mid);
        else return querymin(rt<<1|1,mid+1,r);
    }
    int querymax(int rt,int l,int r){
        if(l==r)return l;
        if(tmx[rt]==0)return 0;
        pushdown(rt);
        int mid=(l+r)>>1;
        if(tmx[rt<<1]>tmx[rt<<1|1])return querymax(rt<<1,l,mid);
        else return querymax(rt<<1|1,mid+1,r);
    }
}tr;
void dfs(int x,int f){
    dep[x]=dep[f]+1;
    st[x][0]=f;
    if(x<=n)dfn[x]=++ct;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==f)continue;
        dfs(v,x);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    int now=dep[x]-dep[y];
    for(int i=20;i>=0;i--){
        if(now>=1<<i)x=st[x][i],now-=1<<i;
    }
    if(x==y)return x;
    for(int i=20;i>=0;i--){
        if(st[x][i]!=st[y][i])x=st[x][i],y=st[y][i];
    }
    return st[x][0];
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n<<1;i++)fa[i]=i;
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    }
    stable_sort(a+1,a+n);
    tot=n;
    for(int i=1;i<n;i++){
        int fx=find(a[i].x),fy=find(a[i].y);
        tot++;
        add(fx,tot),add(tot,fx);
        add(fy,tot),add(tot,fy);
        fa[fx]=fa[fy]=tot;
        w[tot]=a[i].w;
    }
    dfs(tot,0);
    for(int i=1;i<=20;i++){
        for(int o=1;o<=tot;o++){
            st[o][i]=st[st[o][i-1]][i-1];
        }
    }
    tr.build(1,1,n);
    while(q--){
        int tp;
        scanf("%d",&tp);
        if(tp==1){
            int l,r;
            scanf("%d%d",&l,&r);
            tr.upd(1,1,n,l,r,1);
        }
        if(tp==2){
            int l,r;
            scanf("%d%d",&l,&r);
            tr.upd(1,1,n,l,r,2);
        }
        if(tp==3){
            int ans=-1,x;
            scanf("%d",&x);
            int ml=tr.querymin(1,1,n),mr=tr.querymax(1,1,n);
            if(ml&&ml!=x)ans=max(ans,w[lca(ml,x)]);
            if(mr&&mr!=x)ans=max(ans,w[lca(mr,x)]);
            printf("%d\n",ans);
        }
    }
    return  0;
}