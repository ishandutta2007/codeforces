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

const int N = 1123456;
int f[N], co[N];
vector<ll> p;

ll phi(ll n) {
	if(n < N) return f[n];
	ll ans = n;
	for(ll x : p) {
		if(!(n % x)) {
			ans = (ans / x) * (x - 1);
			do n /= x; while(!(n % x));
		}
		if(x > n) break;
	}
	if(n > 1) ans = (ans / n) * (n - 1);
	return ans;
}

inline ll g(ll n) {
	return n;
}

ll solve(ll n, ll k) {
	for(; k > 0; k -= 2) {
		if(n == 1) return 1;
		n = phi(n);
	}
	return n;
}

int main() {
	int i, j;
	f[1] = 1;
	for(i = 2; i < N; i++)
		f[i] = i;
	for(i = 2; i < N; i++)
		if(!co[i]) {
			p.pb(i);
			for(j = i; j < N; j += i)
				co[j]++, f[j] = (f[j] / i) * (i - 1);
		}
	ll n, k;
	scanf("%lld %lld", &n, &k);
	printf("%lld\n", mod(solve(n, k)));
}