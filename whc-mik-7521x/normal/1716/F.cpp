#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,mod=998244353,M=2e3+10;
namespace Math{
    long long fac[N],inv[N],dp[M][M],iv[N];
    long long fp(long long x,long long y){
        long long res=1;
        while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
        return res;
    }
    void init(){
        fac[0]=inv[0]=1;
        for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod,iv[i]=fp(i,mod-2);
        inv[N-1]=fp(fac[N-1],mod-2);
        for(int i=N-2;i>=1;i--){
            inv[i]=inv[i+1]*(i+1)%mod;
        }
        dp[1][1]=1;
        for(int i=1;i<M-1;i++){
            for(int o=1;o<M-1;o++){
                (dp[i+1][o]+=dp[i][o]*o)%=mod;
                (dp[i+1][o+1]+=dp[i][o])%=mod;
            }
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
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        long long ans=0,Cni=1;
        for(int i=1;i<=k;i++){
            if(i>n)break;
            Cni=Cni*(n-i+1)%mod*iv[i]%mod;
            ans+=Cni*dp[k][i]%mod*fac[i]%mod*fp((m+1)/2,i)%mod*fp(m,n-i)%mod;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}