#include<cstdio>
typedef long long ll;
int main() {
	ll n, p, w, d;
	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	for(ll y=0;y<w;y++) {
		if( (p - y*d) % w == 0 ) {
			ll x = (p - y*d) / w;
			if( x + y <= n && x >= 0 ) {
				printf("%lld %lld %lld\n", x, y, n - x - y);
				return 0;
			}
		}
	}
	puts("-1");
}