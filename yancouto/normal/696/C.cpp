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

struct mat {
	ll a, b;
	ll base;
	mat operator * (mat o) const {
		mat k;
		k.a = mod(a * o.a);
		k.base = mod(base * o.base);
		k.b = mod(a * o.b + b * o.base);
		return k;
	}
};

mat fexp(mat n, ll p) {
	mat r = {1, 0, 1};
	for(; p; p >>= 1, n = (n * n))
		if(p & 1)
			r = (r * n);
	return r;
}

int main() {
	int i, j, n; ll x;
	scanf("%d", &n);
	mat M = {modn - 1, 1, 2};
	mat ans = M;
	for(i = 0; i < n; i++) {
		scanf("%lld", &x);
		ans = fexp(ans, x);
	}
	const ll i2 = 500000004;
	//debug("%d/%d and %d/%d\n", (int) ans.a, (int)ans.base, (int)ans.b, (int)ans.base);
	printf("%d/%d\n", (int) mod((ans.a + ans.b)*i2), (int) mod(ans.base*i2));
}