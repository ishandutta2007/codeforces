#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct Persistence_Segment_Tree{
    struct node{
        int l,r,val;
        node(){l=r=val=0;}
    };
    node t[N<<5];
    int root[N],tot=0;
    void pushup(int rt){
        t[rt].val=min(t[t[rt].l].val,t[t[rt].r].val);
    }
    void build(int &rt,int l,int r){
        rt=++tot;
        if(l==r)return t[rt].val=1e9+7,void();
        int mid=(l+r)>>1;
        build(t[rt].l,l,mid);
        build(t[rt].r,mid+1,r);
        pushup(rt);
    }
    void upd(int &rt,int ort,int l,int r,int d,int kk){
        rt=++tot;
        t[rt]=t[ort];
        if(l==r)return t[rt].val=kk,void();
        int mid=(l+r)>>1;
        if(d<=mid)upd(t[rt].l,t[ort].l,l,mid,d,kk);
        else upd(t[rt].r,t[ort].r,mid+1,r,d,kk);
        pushup(rt);
    }
    int query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return t[rt].val;
        int mid=(l+r)>>1,res=1e9+7;
        if(L<=mid)res=min(res,query(t[rt].l,l,mid,L,R));
        if(R>mid)res=min(res,query(t[rt].r,mid+1,r,L,R));
        return res;
    }
}tr;
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
vector<int>dep[N];
int n,a[N],m,id[N],ct,dfn[N],en[N],depth[N];
void dfs(int x,int fa,int de){
    depth[x]=de;
    dep[de].push_back(x);
    id[x]=++ct;
    dfn[ct]=x;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x,de+1);
    }
    en[x]=ct;
}
int ro;
int main(){
    scanf("%d%d",&n,&ro);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(ro,0,1);
    tr.build(tr.root[0],1,n);
    for(int i=1;i<=n*2;i++){
        tr.root[i]=tr.root[i-1];
        for(int o:dep[i]){
            tr.upd(tr.root[i],tr.root[i],1,n,id[o],a[o]);
        }
    }
    scanf("%d",&m);
    int last=0;
    while(m--){
        int p,q;
        scanf("%d%d",&p,&q);
        int x=(p+last)%n+1,k=(q+last)%n;
        printf("%d\n",last=tr.query(tr.root[depth[x]+k],1,n,id[x],en[x]));
    }
    return  0;
}