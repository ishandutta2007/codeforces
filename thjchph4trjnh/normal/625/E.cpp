#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) ((n) & (1LL << (i)))
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

const int maxn = 100010;
int n, m;
ll p[maxn];
ll q[maxn];
ll a[maxn];
ll d[maxn];
ll t[maxn];
ll z[maxn];
int del[maxn];
set<pi> st1, st2;

void update(int idx, ll tms) {
	q[idx] += (tms - t[idx]) * a[idx];
	t[idx] = tms;
}

ll calc(int idx, ll tms) {
	return q[idx] + (tms - t[idx]) * a[idx];
}

void process(pi e) {
	ll tms = e.fi;
	int u = e.se;
	if (del[u]) return;
	set<pi>::iterator it = st1.find(mp(p[u], u));
	vii his;
	while (1) {
		if (++it == st1.end()) {
			it = st1.begin();
		}
		int nxt = it->se;
		if (nxt == u) break;
		ll r = p[u] < p[nxt] ? 0 : m;
		r += u < nxt ? 0 : a[nxt];
		if (tms <= max(t[u], t[nxt])) break;
		if (calc(u, tms - 1) + a[u] < calc(nxt, tms - 1) + r) break;
		d[u]++; del[nxt] = 1;
		his.pb(*it);
	}
	FORall(it, his) {
		st1.erase(*it);
	}
}

void update(pi e) {
	ll tms = e.fi;
	int u = e.se;
	if (del[u]) return;
	set<pi>::iterator it = st1.find(mp(p[u], u));
	if (++it == st1.end()) {
		it = st1.begin();
	}
	int nxt = it->se;
	if (a[u] && nxt != u) {
		st2.erase(mp(z[u], u));
		ll x = t[u], y = t[nxt];
		ll d = max(x, y);
		update(u, d); update(nxt, d);
		ll r = p[u] < p[nxt] ? 0 : m;
		r += u < nxt ? 0 : a[nxt];
		if (q[u] + a[u] >= q[nxt] + r) {
			z[u] = d + 1;
			st2.insert(mp(z[u], u));
		}
		else if (a[u] > a[nxt]) {
			z[u] = d + (q[nxt] + r - q[u] - a[nxt] - 1) / (a[u] - a[nxt]) + 1;
			st2.insert(mp(z[u], u));
		}
		update(u, x); update(nxt, y);
	}
	it = st1.find(mp(p[u], u));
	if (it == st1.begin()) {
		it = st1.end();
	}
	it--;
	int prv = it->se;
	if (prv != u) {
		st2.erase(mp(z[prv], prv));
		ll x = t[prv], y = t[u];
		ll d = max(x, y);
		update(prv, d); update(u, d);
		ll r = p[prv] < p[u] ? 0 : m;
		r += prv < u ? 0 : a[u];
		if (q[prv] + a[prv] >= q[u] + r) {
			z[prv] = d + 1;
			st2.insert(mp(z[prv], prv));
		}
		else if (a[prv] > a[u]) {
			z[prv] = d + (q[u] + r - q[prv] - a[u] - 1) / (a[prv] - a[u]) + 1;
			st2.insert(mp(z[prv], prv));
		}
		update(prv, x); update(u, y);
	}
}

void solve() {
	cin>>n>>m;
	FOR(i, 0, n) {
		cin>>p[i]>>a[i];
		q[i] = p[i];
		st1.insert(mp(p[i], i));
	}
	FOR(i, 0, n) {
		set<pi>::iterator it = st1.find(mp(p[i], i));
		if (++it == st1.end()) {
			it = st1.begin();
		}
		int nxt = it->se;
		int r = p[i] < p[nxt] ? 0 : m;
		r += i < nxt ? 0 : a[nxt];
		if (p[i] + a[i] >= p[nxt] + r) {
			z[i] = 1;
			st2.insert(mp(z[i], i));
		}
		else if (a[i] > a[nxt]) {
			z[i] = (p[nxt] + r - p[i] - a[nxt] - 1) / (a[i] - a[nxt]) + 1;
			st2.insert(mp(z[i], i));
		}
	}
	while (sz(st2)) {
		vii v;
		FORall(it, st2) {
			if (it->fi > st2.begin()->fi) break;
			v.pb(*it);
		}
		FORall(it, v) {
			process(*it);
			st2.erase(*it);
		}
		FORall(it, v) {
			int u = it->se;
			update(u, it->fi);
			a[u] = max(0LL, a[u] - d[u]);
			d[u] = 0;
		}
		FORall(it, v) {
			update(*it);
		}
	}
	cout<<sz(st1)<<"\n";
	FORall(it, st1) cout<<it->se + 1<<" ";
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}