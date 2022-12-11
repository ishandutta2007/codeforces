#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10,inf=1e18;
long long n,a[N],pos[N],nn[N];
long long rr[N],ll[N];
struct tr{
    long long sum[N<<2],mx[N<<2],sx[N<<2],cnt[N<<2],lazy1[N<<2],lazy2[N<<2];
    void pushup(long long rt){
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
        if(mx[rt<<1]==mx[rt<<1|1])cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1],mx[rt]=mx[rt<<1],sx[rt]=max(sx[rt<<1],sx[rt<<1|1]);
        if(mx[rt<<1]>mx[rt<<1|1])cnt[rt]=cnt[rt<<1],mx[rt]=mx[rt<<1],sx[rt]=max(sx[rt<<1],mx[rt<<1|1]);
        if(mx[rt<<1]<mx[rt<<1|1])cnt[rt]=cnt[rt<<1|1],mx[rt]=mx[rt<<1|1],sx[rt]=max(sx[rt<<1|1],mx[rt<<1]);
    }
    void ope(long long rt,long long val){
        if(mx[rt]<val)return ;
        sum[rt]-=(mx[rt]-val)*cnt[rt];
        mx[rt]=val,lazy1[rt]=val;
    }
    void add(long long rt,long long val,long long l,long long r){
        sum[rt]+=(r-l+1)*val;mx[rt]+=val,sx[rt]+=val;lazy1[rt]+=val,lazy2[rt]+=val;
    }
    void pushdown(long long rt,long long l,long long r){
        long long mid=(l+r)>>1;
        if(lazy2[rt])add(rt<<1,lazy2[rt],l,mid),add(rt<<1|1,lazy2[rt],mid+1,r);
        lazy2[rt]=0;
        ope(rt<<1,lazy1[rt]);
        ope(rt<<1|1,lazy1[rt]);
        lazy1[rt]=inf;
    }
    void build(long long rt,long long l,long long r){
        lazy1[rt]=inf;lazy2[rt]=0;
        if(l==r)return sum[rt]=0,lazy1[rt]=inf,mx[rt]=0,sx[rt]=-inf,cnt[rt]=1,(void)0;
        long long mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd1(long long rt,long long l,long long r,long long L,long long R,long long d){//+
        if(L>R||l>r)return;
        if(mx[rt]<=d)return;
        if(L<=l&&r<=R&&sx[rt]<=d)return ope(rt,d);
        pushdown(rt,l,r);
        long long mid=(l+r)>>1;
        if(L<=mid)upd1(rt<<1,l,mid,L,R,d);
        if(R>mid)upd1(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    void upd2(long long rt,long long l,long long r,long long L,long long R,long long d){//min
        if(L>R||l>r)return;
        if(L<=l&&r<=R){
            return add(rt,d,l,r);
        }
        pushdown(rt,l,r);
        long long mid=(l+r)>>1;
        if(L<=mid)upd2(rt<<1,l,mid,L,R,d);
        if(R>mid)upd2(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    void upd3(long long rt,long long l,long long r,long long L,long long d){//dd
        if(l>r)return;
        if(l==r)return mx[rt]=d,sx[rt]=-inf,cnt[rt]=1,lazy1[rt]=inf,lazy2[rt]=0,sum[rt]=d,(void)0;
        pushdown(rt,l,r);
        long long mid=(l+r)>>1;
        if(mid>=L)upd3(rt<<1,l,mid,L,d);
        else upd3(rt<<1|1,mid+1,r,L,d);
        pushup(rt);
    }
    long long query(){
        return sum[1];
    }
}t;
struct BIT{
    int ts[N];
    int ask(int x){
        int res=0;
        for(;x;x-=x&-x)res+=ts[x];
        return res;
    }
    void add(int x,int d){
        for(;x<=n;x+=x&-x)ts[x]+=d;
    }
    void del(int x){for(int i=0;i<=x;i++)ts[i]=0;}
}tt;
int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pos[a[i]]=i;
        nn[a[i]]=tt.ask(a[i]-1);
        tt.add(a[i],1);
    }
    t.build(1,1,n);
    for(long long i=1;i<=n;i++){
        t.upd3(1,1,n,pos[i],i);
        t.upd2(1,1,n,pos[i]+1,n,1);
        t.upd1(1,1,n,1,pos[i]-1,nn[i]);
        rr[i]=t.query();
    }
    reverse(a+1,a+n+1);
    t.build(1,1,n);
    tt.del(n);
    for(long long i=1;i<=n;i++){
        pos[a[i]]=i;
        nn[a[i]]=tt.ask(a[i]-1);
        tt.add(a[i],1);
    }
    for(long long i=1;i<=n;i++){
        t.upd3(1,1,n,pos[i],i);
        t.upd2(1,1,n,pos[i]+1,n,1);
        t.upd1(1,1,n,1,pos[i]-1,nn[i]);
        ll[i]=t.query();
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",rr[i]+ll[i]-i*n);
    }
    return  0;
}