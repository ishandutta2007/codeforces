#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif


inline ll L(ll i, ll sz) {
	return i - ((sz - 1ll) / 2ll + 1ll) / 2ll;
}
inline ll R(ll i, ll sz) {
	return i + ((sz - 1ll) / 2ll + 1ll) / 2ll;
}

vector<int> d;

ll get_sz(ll i, ll sz, ll u) {
	if(i == u) return sz;
	if(u < i) { d.pb(0); return get_sz(L(i, sz), (sz - 1ll) / 2, u); }
	else { d.pb(1); return get_sz(R(i, sz), (sz - 1ll) / 2, u); }
}

char s[112345];

int main() {
	ll n, u;
	int i, q;
	scanf("%lld %d", &n, &q);
	while(q--) {
		scanf("%lld %s", &u, s);
		ll sz = get_sz((n + 1ll) / 2ll, n, u);
		for(i = 0; s[i]; i++) {
			ll p = u, ps = sz;
			if(s[i] == 'L') {
				if(sz == 1) continue;
				u = L(u, sz);
				sz = (sz - 1ll) / 2ll;
				d.pb(0);
			} else if(s[i] == 'R') {
				if(sz == 1) continue;
				u = R(u, sz);
				sz = (sz - 1ll) / 2ll;
				d.pb(1);
			} else {
				if(sz == n) continue;
				ll lp = (sz - 1ll) / 2ll + 1ll;
				if(d.back() == 0) u += lp;
				else u -= lp;
				sz = 2ll * sz + 1ll;
				d.pop_back();
			}
		}
		printf("%lld\n", u);
	}
}