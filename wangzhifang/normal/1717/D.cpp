#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int mod=1000000007;
ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
constexpr int max_n=100000;
int ifac[max_n+1];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	ll now=1;
	for(int i=2; i<=n; ++i)
		now=now*i%mod;
	const ll facn=now;
	ifac[n]=now=quickpow(now,mod-2);
	for(int i=n; i; ifac[--i]=now)
		now=now*i%mod;
	if(k>n)
		k=n;
	int sum=ifac[n];
	for(int i=1; i<=k; ++i)
		sum=(ll(ifac[i])*ifac[n-i]+sum)%mod;
	printf("%lld\n",sum*facn%mod);
	return 0;
}