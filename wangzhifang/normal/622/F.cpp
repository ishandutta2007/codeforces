#include <cstdio>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define max_k 1000000
int fac[max_k+1],inv[max_k+1];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	++k;
	inv[0]=inv[1]=1,fac[0]=n-k;
	for(int i=2; i<=k; ++i)
		inv[i]=ll(-mod/i)*inv[mod%i]%mod;
	ll now=1;
	for(int i=1; i<=k; ++i)
		fac[i]=fac[i-1]*ll(n-k+i)%mod,inv[i]=now=inv[i]*now%mod;
	now=1;
	ll ans=0,sum=0;
	for(int i=0; i<=k; ++i){
		ll y=bool(i);
		for(ll x=i,t=k-1; t; t>>=1,x=x*x%mod)
			(t&1)&&(y=y*x%mod);
		(sum+=y)>=mod&&(sum-=mod);
		ans+=sum*now%mod*(i==k?1:fac[k-i-1])%mod*inv[i]%mod*inv[k-i]%mod*((k-i)&1?-1:1);
		now=now*(n-i)%mod;
	}
	(ans%=mod)<0&&(ans+=mod);
	printf("%lld\n",ans);
	return 0;
}