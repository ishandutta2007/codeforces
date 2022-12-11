#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=1e9;
int n,q;
struct SegmentTree{
    int sum[N<<2],lazy[N<<2];
    void pushup(int rt){sum[rt]=sum[rt<<1]+sum[rt<<1|1];}
    void pushdown(int rt,int l,int r){
        int mid=(l+r)>>1;
        sum[rt<<1]+=lazy[rt]*(mid-l+1);
        sum[rt<<1|1]+=lazy[rt]*(r-mid);
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        lazy[rt]=0;
    }
    void build(int rt,int l,int r){
        if(l==r){sum[rt]=1;return;}
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L>R)return;
        if(L<=l&&r<=R){sum[rt]+=d*(r-l+1),lazy[rt]+=d;return;}
        pushdown(rt,l,r);
        int mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    int querysum(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[rt];
        pushdown(rt,l,r);
        int res=0,mid=(l+r)>>1;
        if(L<=mid)res+=querysum(rt<<1,l,mid,L,R);
        if(R>mid)res+=querysum(rt<<1|1,mid+1,r,L,R);
        return res;
    }
}segt;
struct tr{
    int mx[N<<2],sx[N<<2],cnt[N<<2],lazy[N<<2];
    void pushup(int rt){
        if(mx[rt<<1]==mx[rt<<1|1])cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1],mx[rt]=mx[rt<<1],sx[rt]=max(sx[rt<<1],sx[rt<<1|1]);
        if(mx[rt<<1]>mx[rt<<1|1])cnt[rt]=cnt[rt<<1],mx[rt]=mx[rt<<1],sx[rt]=max(sx[rt<<1],mx[rt<<1|1]);
        if(mx[rt<<1]<mx[rt<<1|1])cnt[rt]=cnt[rt<<1|1],mx[rt]=mx[rt<<1|1],sx[rt]=max(sx[rt<<1|1],mx[rt<<1]);
    }
    void ope(int rt,int val){
        mx[rt]=val,lazy[rt]=val;
    }
    void pushdown(int rt){
        if(lazy[rt]<mx[rt<<1])ope(rt<<1,lazy[rt]);
        if(lazy[rt]<mx[rt<<1|1])ope(rt<<1|1,lazy[rt]);
        lazy[rt]=inf;
    }
    void build(int rt,int l,int r){
        lazy[rt]=inf;
        if(l==r)return lazy[rt]=inf,mx[rt]=l,sx[rt]=-1,cnt[rt]=1,(void)0;
        int mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L>R)return;
        if(L<=l&&r<=R){
            if(mx[rt]<=d)return;
            if(sx[rt]<=d)return segt.upd(1,1,n,d+1,min(mx[rt],n),-cnt[rt]),ope(rt,d);
            int mid=(l+r)>>1;
            pushdown(rt);
            upd(rt<<1,l,mid,L,R,d);
            upd(rt<<1|1,mid+1,r,L,R,d);
            pushup(rt);
            return;
        }
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    void cha(int rt,int l,int r,int L,int d){
        if(l==r)return segt.upd(1,1,n,l,min(mx[rt],n),-1),mx[rt]=d,sx[rt]=-1,cnt[rt]=1,lazy[rt]=inf,segt.upd(1,1,n,l,min(d,n),1);
        pushdown(rt);
        int mid=(l+r)>>1;
        if(mid>=L)cha(rt<<1,l,mid,L,d);
        else cha(rt<<1|1,mid+1,r,L,d);
        pushup(rt);
    }
}t;
int main(){
    scanf("%d%d",&n,&q);
    t.build(1,1,n);
    segt.build(1,1,n);
    while(q--){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            t.upd(1,1,n,1,l-1,l-1);
            t.cha(1,1,n,l,r);
        }
        else printf("%d\n",segt.querysum(1,1,n,l,r));
    }
    return  0;
}