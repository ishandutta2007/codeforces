#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
struct node{
    long long l,k;
};
vector<node>segment[N];
long long dp[N],s[N],f[N],pre[5][N],nx[N],lst[N];
struct SegmentTree{
    struct node{
        long long v1,v2,sum;
        node operator+(const node b)const{
            node c;
            c.v1=max(v1,b.v1);
            c.v2=max(v2,b.v2);
            c.sum=max(sum,max(b.sum,v1+b.v2));
            return c;
        }
    }kk[N<<2];
    void pushup(long long rt){kk[rt]=kk[rt<<1]+kk[rt<<1|1];}
    void build(long long rt,long long l,long long r){
        if(l==r){kk[rt]={s[l],f[l],s[l]+f[l]};return;}
        long long mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    node querysum(long long rt,long long l,long long r,long long L,long long R){
        if(L<=l&&r<=R)return kk[rt];
        long long mid=(l+r)>>1;
        if(L>mid)return querysum(rt<<1|1,mid+1,r,L,R);
        else if(R<=mid)return querysum(rt<<1,l,mid,L,R);
        else return querysum(rt<<1,l,mid,L,R)+querysum(rt<<1|1,mid+1,r,L,R);
    }
}segt;
struct ST{
    long long sum[N<<2];
    void pushup(long long rt){sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);}
    void build(long long rt,long long l,long long r){
        if(l==r){sum[rt]=s[l];return;}
        long long mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(long long rt,long long l,long long r,long long L,long long R,long long d){
        if(L<=l&&r<=R){sum[rt]=d;return;}
        long long mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    long long querysum(long long rt,long long l,long long r,long long L,long long R){
        if(L<=l&&r<=R)return sum[rt];
        long long res=-1e18,mid=(l+r)>>1;
        if(L<=mid)res=max(res,querysum(rt<<1,l,mid,L,R));
        if(R>mid)res=max(res,querysum(rt<<1|1,mid+1,r,L,R));
        return res;
    }
}st;
long long n,m,a[5][N];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=3;i++){
        for(long long o=1;o<=n;o++){
            scanf("%lld",&a[i][o]);
            pre[i][o]=pre[i][o-1]+a[i][o];
        }
    }
    for(long long i=1;i<=n;i++){
        s[i]=pre[1][i]-pre[2][i-1];
        f[i]=pre[2][i]-pre[3][i-1]+pre[3][n];
    }
    for(long long i=1;i<=m;i++){
        long long l,r,w;
        scanf("%lld%lld%lld",&l,&r,&w);
        segment[r].push_back({l,w});
    }
    memset(dp,-63,sizeof dp);
    st.build(1,1,n);
    for(long long i=1;i<=n;i++){
        for(auto it:segment[i]){
            s[i+1]=max(s[i+1],st.querysum(1,1,n,it.l,i)-it.k);
            if(i!=n)st.upd(1,1,n,i+1,i+1,s[i+1]);
        }
    }
    segt.build(1,1,n);
    long long ans=-1e18;
    for(long long i=1;i<=n;i++){
        for(auto it:segment[i]){
            ans=max(ans,segt.querysum(1,1,n,it.l,i).sum-it.k);
        }
    }
    printf("%lld",ans);
    return  0;
}