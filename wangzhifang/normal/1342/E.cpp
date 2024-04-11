#include <cstdio>
using namespace std;
typedef long long ll;
#define mod 998244353
#define max_n 262144
int frc[max_n],ifr[max_n];
ll quickpow(ll x,int k){
	ll ret=1;
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int main(){
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	if(k>=n){
		puts("0");
		return 0;
	}
	k=n-k;
	ll now=frc[1]=frc[0]=1;
	for(int i=2; i<=n; ++i)
		now=frc[i]=now*i%mod;
	now=ifr[n]=quickpow(frc[n],mod-2);
	for(int i=n; i; --i)
		now=ifr[i-1]=now*i%mod;
	int sum=0;
	for(int i=0; i<=k; ++i)
		sum=(sum+((k-i)&1?mod-quickpow(i,n):quickpow(i,n))*ifr[k-i]%mod*ifr[i])%mod;
	printf("%lld\n",sum*(k!=n?2ll:1ll)*frc[n]%mod*ifr[n-k]%mod);
	return 0;
}