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

int main() {
	ll m, b;
	scanf("%lld %lld", &m, &b);
	ll mx = 0;
	for(ll y = 0; y <= b; y++) {
		ll x = (b - y) * m;
		mx = max(mx, ((y * (y + 1ll)) / 2ll) * (x + 1ll) + ((x * (x + 1ll)) / 2ll) * (y + 1ll));
	}
	printf("%lld\n", mx);
}