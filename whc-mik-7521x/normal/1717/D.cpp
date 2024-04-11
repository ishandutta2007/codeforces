#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e9+7;
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
};
using namespace Math;
int main(){
    init();
    int n,k;
    scanf("%d%d",&n,&k); 
    long long res=0;
    for(int i=0;i<=min(n,k);i++)(res+=C(n,i))%=mod; 
    printf("%lld",res);
    return 0;
}