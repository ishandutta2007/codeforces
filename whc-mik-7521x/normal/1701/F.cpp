#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e5+10;
struct node{
    long long sum,add,cnt;
    node operator+(const node b)const{
        return node{sum+b.sum,add+b.add,cnt+b.cnt};
    }
};
struct seg{
    node t[N<<2];
    int tag[N<<2];
    void pushup(int rt){t[rt]=t[rt<<1]+t[rt<<1|1];}
    void add_tag(int rt,int d){
        long long res2=t[rt].add+d*t[rt].cnt,res1=t[rt].sum+(t[rt].add+res2-t[rt].cnt)*d/2;
        t[rt]=node{res1,res2,t[rt].cnt};
        tag[rt]+=d;
    }
    void pushdown(int rt){
        add_tag(rt<<1,tag[rt]);
        add_tag(rt<<1|1,tag[rt]);
        tag[rt]=0;
    }
    void modify(int rt,int l,int r,int X,int d,int val){
        if(l==r)return val?(t[rt]=node{0,0,1},add_tag(rt,d)):(t[rt]=node{0,0,0},void()),void();
        pushdown(rt);
        int mid=(l+r)>>1;
        if(X<=mid)modify(rt<<1,l,mid,X,d,val);
        else modify(rt<<1|1,mid+1,r,X,d,val);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L>R)return;
        if(L<=l&&r<=R)return add_tag(rt,d);
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        return pushup(rt);
    }
    node query(int rt,int l,int r,int L,int R){
        if(L>R)return node{0,0,0};
        if(L<=l&&r<=R)return t[rt];
        pushdown(rt);
        int mid=(l+r)>>1;
        if(R<=mid)return query(rt<<1,l,mid,L,R);
        if(L>mid)return query(rt<<1|1,mid+1,r,L,R);
        return query(rt<<1,l,mid,L,R)+query(rt<<1|1,mid+1,r,L,R);
    }
}tr;
int q,d,a[N];
int main(){
    scanf("%d%d",&q,&d);
    while(q--){
        int x;
        scanf("%d",&x);
        tr.upd(1,1,M,x+1,min(M,x+d),a[x]?-1:1);
        a[x]?tr.modify(1,1,M,x,0,0):tr.modify(1,1,M,x,tr.query(1,1,M,max(1,x-d),x-1).cnt,1);
        a[x]=!a[x];
        printf("%lld\n",tr.query(1,1,M,1,M).sum);
    }
    return  0;
}