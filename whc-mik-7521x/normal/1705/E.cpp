#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,M=3e5;
int n,a[N],q;
struct seg{
    int t0[N<<2],t1[N<<2],tag[N<<2];
    seg(){memset(tag,-1,sizeof tag);}
    void pushup(int rt){
        t0[rt]=max(t0[rt<<1],t0[rt<<1|1]);
        t1[rt]=max(t1[rt<<1],t1[rt<<1|1]);
    }
    void add_tag(int rt,int l,int r,int d){
        d?(t0[rt]=0,t1[rt]=r):(t1[rt]=0,t0[rt]=r);
        tag[rt]=d;
    }
    void pushdown(int rt,int l,int r){
        if(tag[rt]==-1)return;
        int mid=(l+r)>>1;
        add_tag(rt<<1,l,mid,tag[rt]);
        add_tag(rt<<1|1,mid+1,r,tag[rt]);
        tag[rt]=-1;
    }
    void modify(int rt,int l,int r,int L,int R,int d){
        if(L>R)return;
        if(L<=l&&r<=R)return add_tag(rt,l,r,d);
        int mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(L<=mid)modify(rt<<1,l,mid,L,R,d);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    int query0(int rt,int l,int r,int X){
        if(l==r)return l;
        pushdown(rt,l,r);
        int mid=(l+r)>>1;
        if(t0[rt<<1]>=X)return query0(rt<<1,l,mid,X);
        return query0(rt<<1|1,mid+1,r,X);
    }
    int query1(int rt,int l,int r,int X){
        if(l==r)return l;
        pushdown(rt,l,r);
        int mid=(l+r)>>1;
        if(t1[rt<<1]>=X)return query1(rt<<1,l,mid,X);
        return query1(rt<<1|1,mid+1,r,X);
    }
}tr;
void inc(int x){
    int now=tr.query0(1,1,M,x);
    tr.modify(1,1,M,x,now-1,0);
    tr.modify(1,1,M,now,now,1);
}
void dec(int x){
    int now=tr.query1(1,1,M,x);
    tr.modify(1,1,M,x,now-1,1);
    tr.modify(1,1,M,now,now,0);
}
int main(){
    scanf("%d%d",&n,&q);
    tr.modify(1,1,M,1,M,0);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),inc(a[i]);
    for(int i=1;i<=q;i++){
        int k,l;
        scanf("%d%d",&k,&l);
        dec(a[k]);
        a[k]=l;
        inc(a[k]);
        printf("%d\n",tr.t1[1]);
    }
    return 0;
}