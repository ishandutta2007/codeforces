#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=998244353;
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
int n;
long long fac[N],inv[N],pw3[35000],pwpw3[35000];
long long C(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
long long calc(int t){
    return pwpw3[t>>15]*pw3[t&32767]%mod;
}
void init(){
    fac[0]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;i++)inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=inv[i]*inv[i-1]%mod;
    }
    pw3[0]=pwpw3[0]=1;
    for(int i=1;i<=32767;i++)pw3[i]=pw3[i-1]*3%mod;
    long long buf=pw3[32767]*3%mod;
    for(int i=1;i<=31000;i++)pwpw3[i]=pwpw3[i-1]*buf%mod;
}
int main(){
    scanf("%d",&n);
    init();
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long res=C(n,i)*calc(1ll*((mod-1)-i)*n%(mod-1))%mod*(fp(1-calc(i-n+(mod-1)),n)-1)%mod;
        if(i&1)ans=(ans-res)%mod;
        else ans=(ans+res)%mod;
    }
    ans=ans*calc((1ll*n*n+1)%(mod-1))%mod;
    ans=(ans+2*calc(1ll*n*n%(mod-1))%mod*(fp(1-calc((mod-1)+1-n),n)-1))%mod;
    printf("%lld",(mod-ans)%mod);
    return 0;
}