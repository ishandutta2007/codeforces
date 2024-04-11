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

ll d, k, a, b, t;
ll full;
ll cost(ll x) {
	if(x * k >= d) return full * x - t - (x * k - d) * a;
	return full * x - t + (d - k * x) * b;
}

int main() {
	scanf("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t);
	full = k * a + t;
	ll l = 1, r = (d + k - 1) / k;
	while(l < r) {
		ll m = (l + r) / 2;
		if(cost(m) < cost(m + 1)) r = m;
		else l = m + 1;
	}
	printf("%lld\n", cost(l));
}