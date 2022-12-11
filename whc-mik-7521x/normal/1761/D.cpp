#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,mod=1e9+7;
int n,k;
namespace Math{
    long long fac[N],inv[N];
    long long fp(long long x,long long y){
        if(y<0)return 0;
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
        if(x<0||y<0||x<y)return 0;
        return fac[x]*inv[y]%mod*inv[x-y]%mod;
    }
};
using namespace Math;
int main(){
    init();
	scanf("%d%d",&n,&k);
	if(k==0)return printf("%lld",fp(3,n)),0;
	int ans=0;
	for(int i=1;i<=k;i++){
		ans=(ans+1ll*C(k-1,i-1)*C(n-k,i)%mod*fp(3,n-2*i))%mod;
		ans=(ans+1ll*C(k-1,i-1)*C(n-k,i-1)%mod*fp(3,n-2*i+1))%mod;
	}
    printf("%d",ans);
	return 0;
}