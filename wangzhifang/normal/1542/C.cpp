#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define mod 1000000007
il void test(){
	ll n;
	scanf("%lld",&n);
	ll ans=0;
	for(ll i=2,now=1; now<=n; ++i){
		if(!(now%i))
			continue;
		ll x=i/__gcd(now,i);
		ans+=((n/now)-(n/now)/x)%mod*i%mod;
		now=now*x;
	}
	printf("%lld\n",ans%mod);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}