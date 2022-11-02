#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 1e5+9;
ll qpow(ll x,ll y){ll t=1;while(y){if(y&1) (t*=x)%=mod;(x*=x)%=mod;y>>=1;}return t;}
int n;ll k,kk[N];
int f[N],pri[N],tot;
ll phi[N],sph[N];
void init(){
    f[1]=1,tot=0,phi[1]=1;
    for(int i=2;i<=N-9;i++){
        if(!f[i]) pri[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&pri[j]*i<=N-9;j++){
            f[pri[j]*i]=1,phi[pri[j]*i]=phi[i]*(pri[j]-1);
            if(i%pri[j]==0){
                phi[pri[j]*i]=phi[i]*pri[j];break;
            }
        }
    }
    for(int i=2;i<=N-9;i++) sph[i]=(sph[i-1]+phi[i])%mod;
    return ;
}


int main(){
    init();
    scanf("%d%lld",&n,&k);
    kk[0]=1;
    for(int i=1;i<=n;i++) kk[i]=kk[i-1]*k%mod;
    ll ans=0;
    for(int i=1;i<(n-1);i++){
        (ans+=kk[i]*(n-i-1)%mod)%=mod;
    }
    for(int p=1;p<=n-1;p++){
        (ans+=sph[(n-1)/p+1]*kk[p]%mod)%=mod;
    }
    for(int p=1;p<=n-1;p++){
        if(n%p==0) continue;
        (ans+=(mod-phi[(n-1)/p+1]*kk[((n-1)/p+1)*p-n]%mod))%=mod;
    }
    printf("%lld\n",ans*qpow(kk[n],mod-2)%mod);
    return 0;
}