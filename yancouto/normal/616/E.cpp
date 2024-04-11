#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
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

int main() {
	ll i; ll n, m;
	scanf("%lld %lld", &n, &m);
	ll tot = mod(mod(n) * mod(m));
	for(i = 1; i <= m && i * i <= n; i++)
		tot = mod(tot - mod((n / i) * i) + modn);
	ll j = i;
	if(i > m) { printf("%lld\n", tot); return 0; }
	ll inv2 = 500000004;
	assert(mod(inv2 * 2ll) == 1);
	for(i = 1; i * i < n; i++) {
		ll l = (n / (i + 1)) + 1;
		ll r = (n / i);
		l = max(l, j);
		r = min(r, m);
		if(l > m || l > r) continue;
		ll val = mod(mod(mod(l + r) * mod(r - l + 1)) * inv2);
		tot = mod(tot - mod(val * i) + modn);
	}
	printf("%lld\n", tot);
}