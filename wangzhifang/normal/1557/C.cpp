#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define mod 1000000007
il ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
#define max_n 200000
int fac[max_n+1],ifac[max_n+1];
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(!k){
		puts("1");
		return;
	}
	int sum=ifac[n];
	for(int i=2; i<n; i+=2)
		sum=(sum+ll(ifac[i])*ifac[n-i])%mod;
	sum=ll(sum)*fac[n]%mod;
	if((n&1)){
		ll t=quickpow(++sum,k);
		printf("%lld\n",t);
		return;
	}
	sum=quickpow(2,mod-1-n,sum);
//	printf("%d\n",sum);
	printf("%lld\n",(quickpow(2,n*ll(k-1)%(mod-1),sum!=1?quickpow(sum+mod-1,mod-2,quickpow(sum,k)+mod-1):k)+quickpow(quickpow(2,n,sum),k))%mod);
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