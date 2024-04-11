#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
const ll mod=1e9+7;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t,ll res=1){for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}

const int MAXN=2e6+7;
int flag[MAXN],prim[MAXN],mu[MAXN],sumu[MAXN];

void sieve(){
    int n=2e6;
    mu[1]=1;
    for(ri i=2;i<=n;++i){
        if(!flag[i]) prim[++prim[0]]=i,mu[i]=mod-1;
        for(ri j=1;j<=prim[0]&&i*prim[j]<=n;++j){
            int v=i*prim[j];
            flag[v]=1;
            if(i%prim[j]==0) break;
            mu[v]=mod-mu[i];
        }
    }
}
int n,k,ans;
int b[MAXN],base[MAXN];
int main(){
    sieve();
    scanf("%d%d",&n,&k);
    // for(ri i=1;i<=k;++i) printf("%d ",mu[i]);puts("");
    for(ri i=1;i<=k;++i) base[i]=ksm(i,n);
    for(ri i=1;i<=k;++i){
        for(ri j=1;i*j<=k;++j){
            int l=i*j,r=min(l+i-1,k);
            b[l]=add(b[l],1ll*mu[i]*base[j]%mod);
            b[r+1]=dec(b[r+1],1ll*mu[i]*base[j]%mod);
        }
    }
    for(ri i=1;i<=k;++i){
        b[i]=add(b[i],b[i-1]);
        ans=add(ans,b[i]^i);
    }
    printf("%d\n",ans);
    // for(ri i=1;i<=k;++i) printf("%d ",b[i]);puts("");
}