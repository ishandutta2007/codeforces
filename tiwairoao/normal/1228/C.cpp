#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD = int(1E9) + 7;
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
int x; ll n;
int cal(ll p) {
	ll ret = pow_mod(1, n % (MOD - 1))%MOD;
	for(ll i=p;;i*=p) {
		ret = 1LL*ret*pow_mod((i/p)%MOD, (MOD - 1) - (n/i) % (MOD - 1))%MOD;
		ret = 1LL*ret*pow_mod(i%MOD, (n/i) % (MOD - 1))%MOD;
		if( i > n/p ) return ret;
	}
	return ret;
}
int main() {
	scanf("%d%lld", &x, &n);
	int ans = 1;
	for(int i=2;i<=x/i;i++) {
		if( x % i == 0 ) {
			ans = 1LL*ans*cal(i)%MOD;
			while( x % i == 0 )
				x /= i;
		}
	}
	if( x != 1 ) ans = 1LL*ans*cal(x)%MOD;
	printf("%d\n", ans);
}