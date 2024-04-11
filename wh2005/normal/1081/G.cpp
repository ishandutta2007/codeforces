#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5+9;
int n,k;ll mod;
ll fac[N],inv[N];
ll C(ll x,ll y){if(x<0||y<x) return 0;return fac[y]*inv[x]%mod*inv[y-x]%mod;}
int a[N];

void build(int l,int r,int h){
    h--;
    if(!h){a[r-l+1]++;return ;}
    if(l==r) return ;
    int mid=(l+r)>>1;build(l,mid,h);build(mid+1,r,h);
    return ;
}

ll iv[N];

int main(){
    scanf("%d%d%lld",&n,&k,&mod);
    fac[0]=inv[0]=inv[1]=1;
    for(int i=1;i<=N-9;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=2;i<=N-9;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=1;i<=N-9;i++) iv[i]=inv[i];
    for(int i=1;i<=N-9;i++) (inv[i]*=inv[i-1])%=mod;
    build(1,n,k);
    ll ans=0;
    int x=0,y=0,nx=0,ny=0;
    for(int i=1;i<=n;i++)
        if(a[i]){
            if(x==0) x=i,nx=a[i];
            else y=i,ny=a[i];
            (ans+=1ll*a[i]*C(2,i)%mod*C(2,n)%mod*fac[n-2]%mod)%=mod;
        }
    ll t=0;
    for(int s=2;s<=2*x;s++){
        ll len=min(s-1,x)-max(1,s-x)+1;
        (t+=iv[s]*(mod-2)%mod*len%mod)%=mod;
    }
    t=(1ll*x*x%mod+t)%mod*fac[n]%mod;
    (ans+=t*inv[2]%mod*nx%mod*(nx-1)%mod*inv[2]%mod)%=mod;
    for(int i=1;i<=x;i++) (t+=fac[n]*iv[i+y]%mod*(i+y-2)%mod)%=mod;
    
    (ans+=t*inv[2]%mod*nx%mod*ny%mod)%=mod;
    for(int i=1;i<=y;i++) (t+=fac[n]*iv[i+y]%mod*(i+y-2)%mod)%=mod;
    
    (ans+=t*inv[2]%mod*ny%mod*(ny-1)%mod*inv[2]%mod)%=mod;
    (ans*=inv[n])%=mod;
    printf("%lld\n",ans);
    return 0;
}