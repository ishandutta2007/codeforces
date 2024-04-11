#include <cstdio>
#include <cmath>
#define mod 1000000007
using namespace std;
long long query(long long k){
	if(!k)
		return 0;
	int cyc=64-__builtin_clzll(k);
	long long nume,numo;
	(cyc&1)?(numo=k-(nume=((1ll<<(cyc-1))-1)/3*2)):(nume=k-(numo=((1ll<<cyc)-1)/3));
	nume%=mod,numo%=mod;
//	printf("%lld:%lld(%lld %lld)\n",k,(nume*(nume+1)+numo*numo)%mod,numo,nume);
	return (nume*(nume+1)+numo*numo)%mod;
}
int main(){
	long long l,r,ans;
	scanf("%lld%lld",&l,&r);
	(ans=query(r)-query(l-1))<0&&(ans+=mod);
	printf("%lld\n",ans);
	return 0;
}