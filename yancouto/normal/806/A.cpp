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

int n;

int main() {
	scanf("%d", &n);
	while(n--) {
		ll x, y, p, q;
		scanf("%lld %lld %lld %lld", &x, &y, &p, &q);
		if(x == y && p == q) { puts("0"); continue; }
		if(p == q) { puts("-1"); continue; }
		if(x == 0 && p == 0) { puts("0"); continue; }
		if(p == 0) { puts("-1"); continue; }
		ll k1 = (y + q - 1) / q;
		ll k2 = (y - x + q - p - 1) / (q - p);
		ll k3 = (x + p - 1) / p;
		ll k = max(max(k1, k2), k3);
		printf("%lld\n", k * q - y);
	}
}