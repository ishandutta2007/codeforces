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

ll mdc(ll a, ll b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

int main() {
	ll n, a, b, p, q;
	scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &p, &q);
	ll tot = 0;
	tot += ((n / a) - (n / (a * b / mdc(a, b)))) * p;
	tot += ((n / b) - (n / (a * b / mdc(a, b)))) * q;
	tot += (n / (a * b / mdc(a, b))) * max(p, q);
	printf("%lld\n", tot);

}