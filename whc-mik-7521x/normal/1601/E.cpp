#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
struct RMQ{
    int st[N][21];
    RMQ(int a[],int len){
        for(int i=1;i<=len;i++)st[i][0]=a[i];
        for(int o=1;o<=20;o++){
            for(int i=1;i+(1<<o)-1<=len;i++){
                st[i][o]=min(st[i][o-1],st[i+(1<<(o-1))][o-1]);
            }
        }
    }
    int query(int l,int r){
        if(l>r)return 0;
        int len=r-l+1,k=30;
        while((1<<k)>len)k--;
        return min(st[l][k],st[r-(1<<k)+1][k]);
    }
};
int n,q,k,a[N];
vector<pair<int,int>>que[N];
struct seg{
    long long t[N<<2],tag[N<<2];
    void pushup(int rt){
        t[rt]=t[rt<<1]+t[rt<<1|1];
    }
    void add_tag(int rt,int l,int r,int d){
        t[rt]+=1ll*d*(r-l+1);
        tag[rt]+=d;
    }
    void build(int rt,int l,int r){
        t[rt]=tag[rt]=0;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
    }
    void pushdown(int rt,int l,int r){
        int mid=(l+r)>>1;
        add_tag(rt<<1,l,mid,tag[rt]);
        add_tag(rt<<1|1,mid+1,r,tag[rt]);
        tag[rt]=0;
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L<=l&&r<=R)return add_tag(rt,l,r,d);
        int mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    void modify(int rt,int l,int r,int X,int d){
        if(l==r)return t[rt]=d,void();
        int mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(X<=mid)modify(rt<<1,l,mid,X,d);
        else modify(rt<<1|1,mid+1,r,X,d);
        pushup(rt);
    }
    long long query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1;
        pushdown(rt,l,r);
        long long res=0;
        if(L<=mid)res+=query(rt<<1,l,mid,L,R);
        if(R>mid)res+=query(rt<<1|1,mid+1,r,L,R);
        return res;
    }
}tr;
long long ans[N];
int main(){
    scanf("%d%d%d",&n,&q,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    RMQ ty(a,n);
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        que[l].push_back({r,i});
    }
    for(int i=0;i<k;i++){
        int r=(n-i-1)/k;
        tr.build(1,0,r);
        int stk[N],tp=0,cl[N];
        stk[0]=r+1;
        for(int o=n-i;o>=1;o-=k){
            int num=(o-1)/k;
            if(num!=r){
                int val=ty.query(o,o+k);
                while(tp&&cl[stk[tp]]>=val)tr.upd(1,0,r,stk[tp],stk[tp-1]-1,-cl[stk[tp]]+val),tp--;
                stk[++tp]=num+1;
                cl[num+1]=val;
                tr.modify(1,0,r,num+1,val);
            }
            tr.modify(1,0,r,num,a[o]);
            while(que[o].size()){
                auto now=que[o].back();
                que[o].pop_back();
                ans[now.second]=tr.query(1,0,r,num,(now.first-o)/k+num);
            }
        }
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return  0;
}