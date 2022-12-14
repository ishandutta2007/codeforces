#include <cstdio>
using namespace std;
typedef long long ll;
__inline__ __attribute__((always_inline)) ll quickpow(ll x,ll k,const ll& mod){
	ll ret=1;
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==4){
		puts("YES\n1\n3\n2\n4");
		return 0;
	}
	for(int i=2; i*i<=n; ++i)
		if(!(n%i)){
			puts("NO");
			return 0;
		}
	puts("YES\n1");
	if(n==1)
		return 0;
	for(int i=2; i<n; ++i)
		printf("%lld\n",i*quickpow(i-1,n-2,n)%n);
	printf("%d\n",n);
	return 0;
}