#include <bits/stdc++.h>

typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while( T-- ) {
		ll p; int q; scanf("%lld%d", &p, &q);
		if( p % q ) printf("%lld\n", p);
		else {
			ll ans = 0; int lim = sqrt(q);
			for(int i=2;i<=lim;i++) {
				if( q % i == 0 ) {
					ll tmp = p;
					while( tmp % i == 0 ) tmp /= i;
					while( q % i == 0 ) q /= i, tmp *= i;
					tmp /= i, ans = std::max(ans, tmp);
				}
			}
			if( q != 1 ) {
				ll tmp = p;
				while( tmp % q == 0 ) tmp /= q;
				ans = std::max(ans, tmp);
			}
			printf("%lld\n", ans);
		}
	}
}