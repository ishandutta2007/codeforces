#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

int n;
ll phi;
inline ll inv(ll x) { return fexp(x, phi - 1); }

ll mdc(ll a, ll b) {
	if(!b) return a;
	return mdc(b, a % b);
}

const int N = 212345;
ll a[N], p[N], ans[N];

ll T;
int seen[N];
int ans2[N];

void brut_check() {
	int pos = -a[0];
	for(int t = 0; t < 100000; t++) {
		int i = t % n;
		pos = (pos + a[i]) % T;
		if(seen[pos]) continue;
		seen[pos]  =1;
		ans2[i]++;
	}
	for(int i = 0; i < n; i++) printf("%d ", ans2[i]); putchar('\n');
	for(int i = 0; i < n; i++) assert(ans[i] == ans2[i]);
}

int main() {
	int i, j;
	rd(T); rd(n);
	modn = T;
	ll x = T; phi = T;
	for(ll i = 2; i * i <= x; i++) {
		if(x % i) continue;
		while(!(x % i)) x /= i;
		phi = (phi / i) * (i - 1ll);
	}
	if(x > 1) phi = (phi / x) * (x - 1ll);
	for(i = 0; i < n; i++) {
		rd(a[i]);
	}
	ll K = accumulate(a, a + n, 0ll) % ll(T);
	ll g = mdc(ll(T), ll(K));
	debug("T %lld K %lld g %lld\n", T, K, g);
	map<int, vector<pii>> mp;
	ll invKg = inv(K / g);
	debug("inv(%lld) = %lld\n", K / g, inv(K / g));
	ll sz = T / g;
	for(i = 0; i < n; i++) {
		if(i) p[i] = (p[i - 1] + a[i]) % T;
		debug("%d starts at %lld\n", i, p[i]);
		int cl = p[i] % g;
		debug("class %d\n", cl);
		ll z = (p[i] - cl) / g;
		z = (z * invKg) % sz;
		debug("first i is %lld\n", z);
		mp[cl].pb(pii(int(z), i));
	}
	for(auto &e : mp) {
		int cl = e.fst;
		vector<pii> &V = e.snd;
		sort(V.begin(), V.end(), [](pii a, pii b) { if(a.fst != b.fst) return a.fst < b.fst; return a.snd > b.snd; });
		if(V.size() == 1) { ans[V[0].snd] = sz; continue; }
		for(int i = 0; i < int(V.size()) - 1; i++) {
			ans[V[i].snd] = V[i + 1].fst - V[i].fst;
			//assert(ans[V[i].snd] > 0);
		}
		ans[V.back().snd] = (sz - V.back().fst) + V.front().fst;
		//printf("%d - %d + %d\n", sz, V.back().fst, V.front().snd);
		//assert(ans[V.back().snd] > 0);
	}
	for(i = 0; i < n; i++) printf("%lld ", ans[i]); putchar('\n');
	//brut_check();
}