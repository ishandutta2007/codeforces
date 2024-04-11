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
ll best = -1;
ll n, k;

void go(ll x, bool print=false) {
	ll n = ::n / x;
	if((k * (k + 1ll)) / 2ll > n) return;
	if(print) {
		for(int i = 0; i < k - 1; i++)
			printf("%lld ", ll(i + 1) * x);
		printf("%lld\n", (n - (k * (k - 1)) / 2) * x);
	}
	best = max<ll>(best, x);
}

int main() {
	scanf("%lld %lld", &n, &k);
	if(k > 1e6) { puts("-1"); return 0; }
	for(ll i = 1; i * i <= n; i++)
		if((n % i) == 0)
			go(i), go(n / i);
	if(best == -1) puts("-1");
	else go(best, true);
}