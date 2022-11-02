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

int d[112];

int n;
map<tuple<int, int, int, int, int>, ll> mp;
ll solve(int i, int o1, int o2, int d1, int d2) {
	if(i == n) return !o1 && !o2 && !d1 && !d2;
	tuple<int, int, int, int, int> t = make_tuple(i, o1, o2, d1, d2);
	if(mp.count(t)) return mp[t];
	ll &r = mp[t];
	r = 0;
	if(!o1 && !o2 && d1) r += ll(d1) * solve(i + 1, d1 - 1, d2, d[i] == 2, d[i] == 3);
	if(!o1 && !o2 && d2) r += ll(d2) * solve(i + 1, d1 + 1, d2 - 1, d[i] == 2, d[i] == 3);
	if(o1) {
		r += ll(o1) * solve(i + 1, o1 - 1, o2, d1 + (d[i] == 2), d2 + (d[i] == 3));
		if(d1) r += ll(o1) * ll(d1) * solve(i + 1, o1 - 1, o2, d1 - 1 + (d[i] == 3), d2);
		if(d2) r += ll(o1) * ll(d2) * solve(i + 1, o1 - 1, o2, d1 + 1 + (d[i] == 3), d2 - 1);
		if(d[i] == 3) {
			if(d1 >= 2) r += ll(o1) * ll((ll(d1) * ll(d1 - 1)) / 2ll) * solve(i + 1, o1 - 1, o2, d1 - 2, d2);
			if(d2 >= 2) r += ll(o1) * ll((ll(d2) * ll(d2 - 1)) / 2ll) * solve(i + 1, o1 - 1, o2, d1 + 2, d2 - 2);
			if(d1 && d2) r += ll(o1) * ll(d1) * ll(d2) * solve(i + 1, o1 - 1, o2, d1, d2 - 1);
		}
	}
	if(o2) {
		r += ll(o2) * solve(i + 1, o1 + 1, o2 - 1, d1 + (d[i] == 2), d2 + (d[i] == 3));
		if(d1) r += ll(o2) * ll(d1) * solve(i + 1, o1 + 1, o2 - 1, d1 - 1 + (d[i] == 3), d2);
		if(d2) r += ll(o2) * ll(d2) * solve(i + 1, o1 + 1, o2 - 1, d1 + 1 + (d[i] == 3), d2 - 1);
		if(d[i] == 3) {
			if(d1 >= 2) r += ll(o2) * ll((ll(d1) * ll(d1 - 1)) / 2ll) * solve(i + 1, o1 + 1, o2 - 1, d1 - 2, d2);
			if(d2 >= 2) r += ll(o2) * ll((ll(d2) * ll(d2 - 1)) / 2ll) * solve(i + 1, o1 + 1, o2 - 1, d1 + 2, d2 - 2);
			if(d1 && d2) r += ll(o2) * ll(d1) * ll(d2) * solve(i + 1, o1 + 1, o2 - 1, d1, d2 - 1);
		}
	}
	return r = mod(r);
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &d[i]);
	ll ans = solve(2, d[0] == 2, d[0] == 3, d[1] == 2, d[1] == 3);
	printf("%lld\n", ans);
}