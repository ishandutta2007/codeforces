#include <iostream>
#include <cstdio>

typedef long double ld;
typedef long long ll;

const ll INF = 2e18;
const int ms = 100;

ll mul(ll a, ll b) {
	if((ld) a * b >= INF) {
		return INF;
	} else {
		return a * b;
	}
}

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = mul(ans, x);
		}
		x = mul(x, x);
	}
	return ans;
}

int mob[ms];
bool np[ms];

int main() {
	for(int i = 0; i < ms; i++) {
		mob[i] = -1;
	}
	for(int i = 2; i < ms; i++) {
		if(np[i]) continue;
		for(int j = i; j < ms; j += i) {
			mob[j] = -mob[j];
			np[j] = true;
			if(j / i % i == 0) {
				mob[j] = 0;
			}
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		ll l, r;
		scanf("%lld %lld", &l, &r);
		ll ans = 0;
		if(l == 1) {
			ans++;
			l = 2;
		}
		ll nxt = 2e9;
		for(int i = 2; i < 65; i++) {
			if(l > r) break;
			if(mob[i] == 0) {
				continue;
			}
			ll lll = 2, rr = nxt;
			while(lll != rr) {
				ll m;
				m = (lll + rr) / 2;
				if(fexp(m, i) > r) {
					rr = m;
				} else {
					lll = m + 1;
				}
			}
			nxt = rr;
			//std::cout << "r is " << rr << "\n";
			//std::cout << fexp(rr, i) << "\n";
			ll got = rr;
			//ans += mob[i] * rr;
			lll = 2;
			while(lll != rr) {
				ll m;
				m = (lll + rr) / 2;
				if(fexp(m, i) >= l) {
					rr = m;
				} else {
					lll = m + 1;
				}
			}
			//ans -= mob[i] * lll;
			got -= lll;
			ans += mob[i] * got;
			//std::cout << "for i == " << i << ", got " << got * mob[i] << "\n";
			//std::cout << "l is " << lll << "\n";
		}
		if(l == 1) {
			ans++;
		}
		printf("%lld\n", ans);
	}
}