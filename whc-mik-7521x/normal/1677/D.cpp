#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,mod=998244353;
long long fac[N],inv[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    inv[N-1]=fp(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
long long C(long long x,long long y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
long long A(long long x,long long y){
    return fac[x]*inv[x-y]%mod;
}
int t,n,k;
int a[N];
int main(){
    scanf("%d",&t);
    init();
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        long long ans=fac[k];
        for(int i=1;i<=n-k;i++){
            if(a[i]==0){
                ans*=(k+1)*1ll;
                ans%=mod;
            }
            else if(a[i]==-1){
                ans*=(i+k)*1ll;
                ans%=mod;
            }
        }
        for(int i=n-k+1;i<=n;i++)if(a[i]>0)ans=0;
        printf("%lld\n",ans);
    }
    return  0;
}