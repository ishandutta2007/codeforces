#include <cstdio>
using namespace std;
typedef long long ll;
constexpr int mod=1000000007;
constexpr int max_n=250;
int comb[max_n+1],s[max_n+1],p[max_n+1];
ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	comb[0]=s[0]=p[0]=1;
	for(int i=1; i<=n; ++i)
		comb[i]=quickpow(i,mod-2,comb[i-1]*ll(n-i+1)%mod),
		s[i]=s[i-1]*ll(k)%mod,
		p[i]=p[i-1]*ll(k-1)%mod;
	int ans=0;
	for(int i=0; i<=n; ++i)
#define val quickpow((ll(p[i])*s[n-i]-p[n]+mod)%mod,n,comb[i])
		ans=((i&1)?ans-val+mod:(ans+val))%mod;
#undef val
	printf("%d",ans);
	return 0;
}