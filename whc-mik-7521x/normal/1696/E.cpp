#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
int n,a[N];
long long ans;
namespace Math{
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
    long long exgcd(long long a,long long b,long long &x,long long &y){
        if(!b)return x=1,y=0,a;
        long long d=exgcd(b,a%b,x,y);
        long long z=x;x=y;y=z-y*(a/b);
        return d;
    }
}
using namespace Math;
int main(){
    scanf("%d",&n);
    n++;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    init();
    for(int i=1;i<=n;i++){if(a[i])(ans+=C(a[i]+i-1,i))%=mod;}
    printf("%lld",ans%mod);
    return  0;
}