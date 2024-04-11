#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

ll euclid(ll x, ll y, ll &k, ll &l) {
	if (y == 0) {
		k = 1;
		l = 0;
		return x;
	}
	ll g = euclid(y, x % y, l, k);
	l -= k * (x / y);
	return g;
}

int main()
{
	ll n;
	scanf("%lld", &n);
	ll m = -1;
	for (ll x = 2; x * x <= n; x++) {
		if (n % x) continue;
		m = 1;
		while(n % x == 0) {
			m *= x;
			n /= x;
		}
		break;
	}
	if (m == -1 || n == 1) {
		printf("NO\n");
		return 0;
	}
	ll k, l;
	if (euclid(n, m, k, l) != 1) throw;
	k *= -1;
	l *= -1;
	if (k < 0) {
		k += m;
	} else {
		l += n;
	}
	if (k <= 0 || l <= 0 || k * n + l * m != n * m - 1) throw;
	printf("YES\n2\n");
	printf("%lld %lld\n", k, m);
	printf("%lld %lld\n", l, n);
	
    return 0;
}