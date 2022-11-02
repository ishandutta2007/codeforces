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
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

int main() {
	ll a, b, n, x;
	scanf("%lld %lld %lld %lld", &a, &b, &n, &x);
	if(a == 1) { printf("%lld\n", mod(mod(n) * b + x)); return 0; }
	ll ans = mod(fexp(a, n) * x);
	ll aux = mod(mod(fexp(a, n) - 1ll + modn) * fexp(a - 1ll, modn - 2));
	ans = mod(ans + aux * b);
	printf("%lld\n", ans);
}