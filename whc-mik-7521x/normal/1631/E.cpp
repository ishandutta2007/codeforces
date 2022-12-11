#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct SegmentTree{
    int sum[N<<2];
    void pushup(int rt){sum[rt]=min(sum[rt<<1],sum[rt<<1|1]);}
    void build(int rt,int l,int r){
        if(l==r){sum[rt]=1e9;return;}
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L<=l&&r<=R){sum[rt]=d;return;}
        int mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    int querysum(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[rt];
        int res=1e9,mid=(l+r)>>1;
        if(L<=mid)res=min(res,querysum(rt<<1,l,mid,L,R));
        if(R>mid)res=min(res,querysum(rt<<1|1,mid+1,r,L,R));
        return res;
    }
}segt;
int dp[N],a[N],n,fir[N];
int main(){
    scanf("%d",&n);
    memset(fir,127,sizeof fir);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),fir[a[i]]=min(fir[a[i]],i);
    segt.build(1,0,n);
    dp[0]=0;
    segt.upd(1,0,n,0,0,0);
    for(int i=1;i<=n;i++){
        dp[i]=min(dp[i-1],segt.querysum(1,0,n,fir[a[i]],i))+1;
        segt.upd(1,0,n,i,i,dp[i]);
    }
    printf("%d",n-dp[n]);
    return  0;
}