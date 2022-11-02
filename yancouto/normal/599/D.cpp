#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int main() {
	ll x;
	scanf("%I64d", &x);
	ll mi = 0, li = 0;
	vector<pii> v;
	for(ll i = 0; ; i++) {
		mi += i + 1;
		li += ((i * (i + 1)) >> 1);
		ll m = x + li;
		if(i > 10000 && ((m + mi - 1) / mi) < i + 1) break;
		if((m % mi) == 0) {
			m /= mi;
			if(i + 1 > m) continue;
			v.pb(pii(i + 1ll, m));
		}
	}
	printf("%d\n", 2 * v.size() - (v.back().fst == v.back().snd));
	for(pii p : v)
		printf("%I64d %I64d\n", p.fst, p.snd);
	if(v.back().fst == v.back().snd) v.pop_back();
	for(int i = v.size() - 1; i >= 0; i--)
		printf("%I64d %I64d\n", v[i].snd, v[i].fst);
}