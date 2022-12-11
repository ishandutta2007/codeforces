#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
struct node{
    long long mxmx,mimi,mxmi,mimx,mxi,mii,val;
    node (long long a1=-1e18,long long a2=1e18,long long a3=1e18,long long a4=-1e18,long long a5=1e18, long long a6=-1e18,long long a7=1e18){
        mxmx=a1,mimi=a2,mxmi=a3,mimx=a4,mxi=a5,mii=a6,val=a7;
    }
    node operator+(const node b)const{
        return node(max(mxmx,b.mxmx),min(mimi,b.mimi),min(mxmi,b.mxmi),max(mimx,b.mimx),min(mxi,b.mxi),max(mii,b.mii),min(val,b.val));
    }
};
long long n,k,dd;
struct seg{
    node t[N<<2];
    long long tag1[N<<2],tag2[N<<2];
    seg(){memset(tag1,63,sizeof tag1),memset(tag2,-63,sizeof tag2);}
    void pushup(long long rt){t[rt]=t[rt<<1]+t[rt<<1|1];}
    void add_tag1(long long rt,long long tg,long long l,long long r){
        t[rt].mxmx=t[rt].mxmi=tg;
        t[rt].mxi=tg-r*dd;
        t[rt].val=tg-t[rt].mii;
        tag1[rt]=tg;
    }
    void add_tag2(long long rt,long long tg,long long l,long long r){
        t[rt].mimi=t[rt].mimx=tg;
        t[rt].mii=tg+r*dd;
        t[rt].val=t[rt].mxi-tg;
        tag2[rt]=tg;
    }
    void pushdown(long long rt,long long l,long long r){
        long long mid=(l+r)>>1;
        if(tag1[rt]<=1e18+1){
            add_tag1(rt<<1,tag1[rt],l,mid);
            add_tag1(rt<<1|1,tag1[rt],mid+1,r);
            tag1[rt]=2e18+1;
        }
        if(tag2[rt]>=-1e18-1){
            add_tag2(rt<<1,tag2[rt],l,mid);
            add_tag2(rt<<1|1,tag2[rt],mid+1,r);
            tag2[rt]=-2e18-1;
        }
    }
    void modify(long long rt,long long l,long long r,long long X,node d){
        if(l==r)return t[rt]=d,void();
        long long mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(X<=mid)modify(rt<<1,l,mid,X,d);
        else modify(rt<<1|1,mid+1,r,X,d);
        pushup(rt);
    }
    void upd1(long long rt,long long l,long long r,long long L,long long R,long long d){
        if(L>R)return;
        if(L<=l&&r<=R)return add_tag1(rt,d,l,r);
        long long mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(L<=mid)upd1(rt<<1,l,mid,L,R,d);
        if(R>mid)upd1(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    void upd2(long long rt,long long l,long long r,long long L,long long R,long long d){
        if(L>R)return;
        if(L<=l&&r<=R)return add_tag2(rt,d,l,r);
        long long mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(L<=mid)upd2(rt<<1,l,mid,L,R,d);
        if(R>mid)upd2(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    long long findpos1(long long rt,long long l,long long r,long long d){
        if(l==r)return l;
        pushdown(rt,l,r);
        long long mid=(l+r)>>1;
        if(t[rt<<1|1].mxmi<d)return findpos1(rt<<1|1,mid+1,r,d);
        return t[rt<<1].mxmi<d?findpos1(rt<<1,l,mid,d):0;
    }
    long long findpos2(long long rt,long long l,long long r,long long d){
        if(l==r)return l;
        pushdown(rt,l,r);
        long long mid=(l+r)>>1;
        if(t[rt<<1|1].mimx>d)return findpos2(rt<<1|1,mid+1,r,d);
        return t[rt<<1].mimx>d?findpos2(rt<<1,l,mid,d):0;
    }
    long long findans(long long rt,long long l,long long r,long long d){
        if(l==r)return l;
        pushdown(rt,l,r);
        long long mid=(l+r)>>1;
        if(t[rt<<1|1].val<=d)return findans(rt<<1|1,mid+1,r,d);
        return findans(rt<<1,l,mid,d);
    }
    long long query(long long rt,long long l,long long r,long long X){
        if(l==r)return t[rt].val;
        long long mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(X<=mid)return query(rt<<1,l,mid,X);
        else return query(rt<<1|1,mid+1,r,X);
    }
}tr;
long long ans[N],to[N],a[N];
map<long long,long long>mp;
int main(){
    scanf("%lld%lld%lld",&n,&k,&dd);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    if(dd==0){
        ans[n]=1;
        long long res=0;
        for(long long i=n-1;i>=1;i--){
            ans[i]=a[i]==a[i+1]?ans[i+1]+1:1;
            res=max(res,ans[i]);
        }
        for(long long i=1;i<=n;i++)if(ans[i]==res){printf("%lld %lld\n",i,i+res-1);break;}
    }
    else{
        to[n]=n;
        long long res=0;
        for(long long i=n;i>=1;i--){
            if(!to[i])to[i]=min(mp.count(a[i])?mp[a[i]]-1:(long long)1e18,abs(a[i]-a[i+1])%dd==0?to[i+1]:i);
            mp[a[i]]=i;
            tr.upd1(1,1,n,to[i]+1,n,1e18+1);
            tr.upd2(1,1,n,to[i]+1,n,-1e18-1);
            int p1=tr.findpos1(1,1,n,a[i]),p2=tr.findpos2(1,1,n,a[i]);
            if(p1>=i)tr.upd1(1,1,n,i,p1,a[i]);
            if(p2>=i)tr.upd2(1,1,n,i,p2,a[i]);
            tr.modify(1,1,n,i,node(a[i],a[i],a[i],a[i],a[i]-i*dd,a[i]+i*dd,-i*dd));
            ans[i]=tr.findans(1,1,n,k*dd-i*dd);
            res=max(res,ans[i]-i+1);
        }
        for(long long i=1;i<=n;i++){
            if(ans[i]-i+1==res){printf("%lld %lld\n",i,ans[i]);break;}
        }
    }
    return  0;
}