#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
const ll modn2 = 1000000006;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % modn2; }

ll fexp(ll x, ll e) {
	ll r = 1;
	for(; e; e >>= 1) {
		if(e & 1) r = mod(r * x);
		x = mod(x * x);
	}
	return r;
}

ll r[200009], l[200009];
int main() {
	int i, n, p;
	map<int, int> mp;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &p);
		mp[p]++;
	}
	ll tot = 1;
	l[0] = 1;
	i = 1;
	for(auto &it : mp) {
		tot = mod2(tot * ll(it.snd + 1));
		l[i++] = tot;
	}
	r[i--] = 1;
	tot = 1;
	for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
		tot = mod2(tot * ll(it->snd + 1));
		r[i--] = tot;
	}
	ll ans = 1;
	i = 1;
	for(auto &it : mp) {
		ll p = fexp(it.fst, (ll(it.snd) * ll(it.snd + 1)) / 2ll);
		p = fexp(p, l[i - 1] * r[i + 1]);
		ans = mod(ans * p);
		i++;
	}
	printf("%d\n", int(ans));
}