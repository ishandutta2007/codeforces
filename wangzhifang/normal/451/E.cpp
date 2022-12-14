#include <cstdio>
using namespace std;
#define mod 1000000007
typedef long long ll;
#define max_n 20
ll quickpow(ll x,int k){
	ll ret=1;
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
ll comb(ll n,const int&m){
	ll prd=1;
	n%=mod;
	for(ll i=n-m; ++i<=n; prd=prd*i%mod);
	prd<0&&(prd+=mod);
	return prd;
}
ll f[max_n];
int main(){
	int n;
	ll s;
	scanf("%d%lld",&n,&s);
	for(int i=0; i<n; ++i)
		scanf("%lld",f+i);
	ll ans=0,iv=1;
	for(int i=1; i<n; ++i)
		iv=iv*i%mod;
	iv=quickpow(iv,mod-2);
	for(int j=1<<n; --j>=0; ){
		ll sum=0;
		for(int k=0; k<n; ++k)
			if(j&(1<<k))
				sum+=f[k]+1;
//		printf("%d:%lld\n",j,sum);
//		if(s-sum>=0)
//		printf("%lld\n",comb(n+s-sum-1,n-1)*iv%mod);
		if(s-sum>=0)
			ans=(ans+(__builtin_parity(j)?mod-1:1)*comb(n+s-sum-1,n-1)%mod*iv)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}