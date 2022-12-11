#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
struct node{
    int a,p1,p0,s1,s0;
    node(int x=-1,int y=-1,int z=-1,int k1=0,int k2=0){a=x,p1=y,p0=z,s1=k1,s0=k2;}
    int v1(int x){return x==a?p1:p0;}
    int v2(int x){return x==a?s1:s0;}
    node operator+(node b){
        return node(a,b.v1(p1),b.v1(p0),b.v2(p1)+s1,b.v2(p0)+s0);
    }
};
struct seg{
    node t[N<<2];
    void modify(int rt,int l,int r,int x,node d){
        if(l==r)return t[rt]=d,void();
        int mid=(l+r)>>1;
        if(x<=mid)modify(rt<<1,l,mid,x,d);
        else modify(rt<<1|1,mid+1,r,x,d);
        t[rt]=t[rt<<1|1]+t[rt<<1];
    }
    node query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1;
        if(R<=mid)return query(rt<<1,l,mid,L,R);
        if(L>mid)return query(rt<<1|1,mid+1,r,L,R);
        return query(rt<<1|1,mid+1,r,L,R)+query(rt<<1,l,mid,L,R);
    }
}tr;
struct edge{
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int dfn[N],hs[N],siz[N],tp[N],en[N],ct,cn[N][21],f[N],sum[N];
void dfs1(int x,int fa){
    siz[x]=1;
    f[x]=fa;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs1(v,x);
        if(siz[v]>siz[hs[x]])hs[x]=v;
        siz[x]+=siz[v];
    }
}
void dfs(int x,int fa,int top){
    dfn[x]=++ct;
    tp[x]=top;
    en[top]=x;
    if(hs[x])dfs(hs[x],x,top);
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa||v==hs[x])continue;
        dfs(v,x,v);
    }
}
int ask1(int x){
    x=tp[x];
    return tr.query(1,1,n,dfn[x],dfn[en[x]]).v1(-1);
}
int ask2(int x){
    x=tp[x];
    return tr.query(1,1,n,dfn[x],dfn[en[x]]).v2(-1);
}
void modify(int x,node d){
    if(!x)return;
    int nxt=f[tp[x]];
    if(nxt)cn[nxt][ask1(x)]--,sum[nxt]-=ask2(x);
    tr.modify(1,1,n,dfn[x],d);
    if(nxt)cn[nxt][ask1(x)]++,sum[nxt]+=ask2(x);
    vector<int>vec;
    int i=0;
    while((int)vec.size()<2)cn[nxt][i]?i++:(vec.push_back(i),i++);
    modify(nxt,node(vec[0],vec[1],vec[0],sum[nxt]+vec[1],sum[nxt]+vec[0]));
}
int main(){
    scanf("%d",&n);
    n++;
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        add(x,i);
        add(i,x);
    }
    dfs1(1,0);
    dfs(1,0,1);
    modify(1,node(0,1,0,1,0));
    for(int i=2;i<=n;i++){
        modify(i,node(0,1,0,1,0));
        printf("%d\n",ask2(1));
    }
    return 0;
}