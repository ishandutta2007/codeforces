#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=998244353;
int t,n,dp1[N],dp2[N],pw2[N];
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
    dp1[0]=pw2[0]=1;
	for(int i=1;i<N;i++)pw2[i]=2*pw2[i-1]%mod;
	for(int i=1;i<N;i++)dp1[i]=(dp1[i-1]+1ll*dp1[i-2]*(i-1))%mod;
	dp2[0]=0,dp2[1]=1,dp2[2]=2;
	for(int i=3;i<N;i++)dp2[i]=1ll*dp2[i-2]*i%mod;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
        int ans=dp1[n];
		for(int i=1;4*i<=n;i++)ans=(ans+1ll*dp1[n-4*i]*C(n-2*i,2*i)%mod*pw2[i]%mod*dp2[2*i-1])%mod;
		printf("%d\n",ans);
	}
	return 0;
}