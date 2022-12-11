#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long a[N],b[N],c[N],dd[N],n,m,q;
long long s1[N],s2[N];
struct SegmentTree{
    long long mx[N<<2],lazy[N<<2],sum[N<<2];
    void pushup(long long rt){mx[rt]=mx[rt<<1|1],sum[rt]=sum[rt<<1]+sum[rt<<1|1];}
    void pushdown(long long rt,long long l,long long r){
        if(!lazy[rt])return;
        long long mid=(l+r)>>1;
        sum[rt<<1]+=(mid-l+1)*lazy[rt];
        sum[rt<<1|1]+=(r-mid)*lazy[rt];
        mx[rt<<1]+=lazy[rt];
        mx[rt<<1|1]+=lazy[rt];
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        lazy[rt]=0;
    }
    void build(long long rt,long long l,long long r){
        if(l==r){mx[rt]=sum[rt]=dd[l];return;}
        long long mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(long long rt,long long l,long long r,long long L,long long R,long long d){
        if(L<=l&&r<=R){mx[rt]+=d,sum[rt]+=d*(r-l+1),lazy[rt]+=d;return;}
        pushdown(rt,l,r);
        long long mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    long long querysum(long long rt,long long l,long long r,long long L,long long R){
        if(L<=l&&r<=R)return sum[rt];
        pushdown(rt,l,r);
        long long res=0,mid=(l+r)>>1;
        if(L<=mid)res+=querysum(rt<<1,l,mid,L,R);
        if(R>mid)res+=querysum(rt<<1|1,mid+1,r,L,R);
        return res;
    }
    long long querypos(long long rt,long long l,long long r,long long d){
        if(l==r)return l;
        long long mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(mx[rt<<1]>=d)return querypos(rt<<1,l,mid,d);
        else return querypos(rt<<1|1,mid+1,r,d);
    }
}t;
long long su;
int main(){
    scanf("%lld%lld%lld",&n,&m,&q);
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]),c[i]=a[i]-a[i-1];
    for(long long i=1;i<=m;i++)scanf("%lld",&b[i]),dd[i]=b[i]-b[i-1],su+=(i==1?0:dd[i]*(m-i+1));
    t.build(1,2,m);
    while(q--){
        long long tp,k,d;
        scanf("%lld%lld%lld",&tp,&k,&d);
        if(tp==1){if(k==n)a[1]+=d,k--;for(long long i=n-k+1;i<=n;i++)c[i]+=d;}
        else {if(k==m)b[1]+=d,k--;t.upd(1,2,m,m-k+1,m,d);su+=d*(k)*(k+1)/2;}
        long long ans=su+(n+m-1)*(a[1]+b[1]);
		long long sm=t.querysum(1,2,m,2,m);
		for(long long i=2;i<=n;i++){
			if(t.querysum(1,2,m,m,m)<c[i]){ans+=sm;continue;}
			long long pos=t.querypos(1,2,m,c[i]);
			if(pos!=2)ans+=t.querysum(1,2,m,2,pos-1);
			ans+=c[i]*(m-pos+1);	
		}
		for(long long i=2;i<=n;i++)ans+=c[i]*(n-i+1);
		printf("%lld\n",ans);
    }
    return  0;
}