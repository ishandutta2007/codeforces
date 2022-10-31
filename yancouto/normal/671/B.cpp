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
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
bool pos;
int ans;

void end(ll ql, ll l, ll el, ll qr, ll r, ll er, ll k) {
	debug("end %lld %lld %lld | %lld %lld %lld\n", ql, l, el, qr, r, er);
	er += k;
	el += k;
	ql -= el / l;
	el %= l;
	qr += er / r;
	er %= r;
	if(ql <= qr) printf("%d\n", !pos), ans = !pos;
	else printf("%d\n", int(ql - qr)), ans = int(ql - qr);
}

ll a[512345];
int simul(int n, ll k) {
	multiset<int> ms;
	for(int i = 0; i < n; i++)
		ms.insert(a[i]);
	while(k--) {
		int x = *ms.rbegin();
		ms.erase(ms.find(x));
		ms.insert(--x);
		x = *ms.begin();
		ms.erase(ms.find(x));
		ms.insert(++x);
	}
	return *ms.rbegin() - *ms.begin();
}

int main() {
	int i, j, n; ll k;
	scanf("%d" LLD, &n, &k);
	for(i = 0; i < n; i++)
		scanf(LLD, &a[i]);
	sort(a, a + n, greater<ll>());
	pos = (accumulate(a, a + n, 0ll) % n) == 0;
	deque<ll> d;
	for(i = 0; i < n; i++) d.pb(a[i]);
	ll l = 1, r = 1;
	ll el = 0, er = 0;
	//int A = simul(n, k);
	while(d.size() > 2) {
		debug("el %lld er %lld k %lld\n", el, er, k);
		n = d.size();
		ll nl = l * (d[0] - d[1]);
		ll nr = r * (d[n - 2] - d[n - 1]);
		debug("%lld->%lld .... %lld<-%lld\n", d[0], d[1], d[n - 2], d[n - 1]);
		debug("l %lld r %lld\n", l, r);
		if(nl - el >= k && nr - er >= k)
			break;
		if(nl - el == nr - er) {
			k -= nl - el;
			el = er = 0;
			d.pop_front();
			d.pop_back();
			l++; r++;
		} else if(nl - el < nr - er) {
			er += nl - el;
			k -= nl - el;
			el = 0; l++;
			d.pop_front();
		} else {
			el += nr - er;
			k -= nr - er;
			er = 0; r++;
			d.pop_back();
		}
	}
	if(d.size() == 1) { puts("0"); return 0; }
	end(d.front(), l, el, d.back(), r, er, k);
	//debug("%d vs %d\n", ans, A);
	//assert(ans == A);
}