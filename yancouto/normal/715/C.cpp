#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define minus asldhasd
ll minus(ll x) { return (modn - (x % modn)) % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

int phi_(int x) {
	int p = x;
	for(int i = 2; i * i <= x; i++) {
		if(x % i) continue;
		p = (p / i) * (i - 1);
		while(!(x % i)) x /= i;
	}
	if(x > 1) p = (p / x) * (x - 1);
	return p;
}
ll phi;

inline ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}
inline ll inv(ll x) { return fexp(x, phi - 1); }
const int N = 112345;
ll inv10[N], p10[N];
ll ans;

struct st {
	int size;
	ll ya, yb; // real y = ya * y + yb
	map<ll, ll> y;
	ll xa, xb; // real x = xa * x + xb
	map<ll, ll> xg;
	void add_digit(ll d) {
		// y' = 10y + d
		ya = mod(10ll * ya);
		yb = mod(10ll * yb + d);
		
		//10^(-g-1) * x' = d * 10^-1 + (10^-g * x) * 10^-1
		xa = mod(inv10[1] * xa);
		xb = mod(inv10[1] * mod(xb + d));
	}
	void swap(st &o) {
		std::swap(size, o.size);
		std::swap(ya, o.ya);
		std::swap(yb, o.yb);
		y.swap(o.y);
		std::swap(xa, o.xa);
		std::swap(xb, o.xb);
		xg.swap(o.xg);
	}
	void check(st &o) {
		// o.y checking on xg
		for(pll p : o.y) {
			ll r = minus(p.fst * o.ya + o.yb);
			ll search = mod(mod(r - xb + modn) * inv(xa));
			if(xg.count(search))
				ans += xg[search] * p.snd;
		}
		// o.xg checking on y
		for(pll p : o.xg) {
			ll r = minus(p.fst * o.xa + o.xb);
			ll search = mod(mod(r - yb + modn) * inv(ya));
			if(y.count(search))
				ans += y[search] * p.snd;
		}
	}
	void join(st &o) {
		size += o.size;
		// adding o.y
		for(pll p : o.y) {
			ll r = mod(p.fst * o.ya + o.yb);
			ll add = mod(mod(r - yb + modn) * inv(ya));
			y[add] += p.snd;
		}
		// adding o.xg
		for(pll p : o.xg) {
			ll r = mod(p.fst * o.xa + o.xb);
			ll add = mod(mod(r - xb + modn) * inv(xa));
			xg[add] += p.snd;
		}
	}
	void start() {
		ya = xa = 1; yb = xb = 0;
		y[0] = 1;
		xg[0] = 1;
		size = 1;
	}
} s[N];

vector<pii> adj[N];

void dfs(int u, int p) {
	debug("dfs(%d, %d)\n", u, p);
	bool any = false;
	s[u].start();
	for(pii e : adj[u]) {
		int v = e.fst;
		if(v == p) continue;
		any = true;
		dfs(v, u);
		s[v].add_digit(e.snd);
		debug("join on %d\n", u);
		if(s[u].size < s[v].size) s[u].swap(s[v]);
		s[u].check(s[v]);
		s[u].join(s[v]);
	}
}


int main() {
	int i, j, a, b, d;
	scanf("%d %lld", &n, &modn);
	phi = phi_(modn);
	p10[0] = mod(1);
	inv10[0] = mod(1);
	inv10[1] = inv(10);
	for(i = 1; i < N; i++) p10[i] = mod(p10[i - 1] * 10ll);
	for(i = 2; i < N; i++) inv10[i] = mod(inv10[i - 1] * inv10[1]);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &d);
		adj[a].pb(pii(b, d));
		adj[b].pb(pii(a, d));
	}
	if(modn == 1) printf("%lld\n", ll(n) * ll(n - 1));
	else {
		dfs(0, 0);
		printf("%lld\n", ans);
	}
}