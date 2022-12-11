#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
#define mod 1000000007
int fac[max_n+1],ifac[max_n+1];
il void test(){
	int n,k,ans=1;
	scanf("%d%d",&n,&k);
	for(int i=1,r=n; i<n&&r>=i; ++i,r-=k-1)
		ans=(ans+ll(fac[r])*ifac[r-i]%mod*ifac[n]%mod*fac[n-i])%mod;
	printf("%d\n",ans);
}
ll quickpow(ll x,int k){
	ll ret=1;
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int main(){
	ll now=fac[0]=1;
	for(int i=1; i<=max_n; ++i)
		fac[i]=now=now*i%mod;
	ifac[max_n]=now=quickpow(now,mod-2);
	for(int i=max_n; i; --i)
		ifac[i-1]=now=now*i%mod;
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}