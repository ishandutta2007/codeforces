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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

int main() {
	ll n, m; int k;
	scanf("%lld %lld %d", &n, &m, &k);
	if(k == -1 && (n & 1) != (m & 1) && (m > 1 || n > 1)) puts("0");
	else printf("%lld\n", fexp(fexp(2, n - 1), m - 1));

}