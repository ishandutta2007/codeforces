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

map<ll, ll> mp;

int lg(ll x) {
	if(x == 1) return 0;
	return 1 + lg(x >> 1);
}

int main() {
	int i, j, n, op;
	scanf("%d", &n); ll x, a, b;
	while(n--) {
		scanf("%d %lld %lld", &op, &a, &b);
		if(op == 1) {
			int ca = lg(a), cb = lg(b);
			scanf("%lld", &x);
			while(ca != cb) {
				if(ca > cb) mp[a] += x, a >>= 1, ca--;
				else mp[b] += x, b >>= 1, cb--;
			}
			while(a != b) {
				mp[a] += x; mp[b] += x;
				a >>= 1, b >>= 1;
			}
		} else {
			ll cs = 0;
			int ca = lg(a), cb = lg(b);
			while(ca != cb) {
				if(ca > cb) cs += mp[a], a >>= 1, ca--;
				else cs += mp[b], b >>= 1, cb--;
			}
			while(a != b) {
				cs += mp[a] + mp[b];
				a >>= 1, b >>= 1;
			}
			printf("%lld\n", cs);
		}

	}
}