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
typedef pair<int, int> pi;
typedef vector<int> vi;
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
void submod(int& a, int val, int p = MOD) {if ((a = (a + val)) < 0) a += p;}

const int maxn = 100010;
int n;
vector<pair<ll, ll> > vl;
vector<pair<ll, ll> > vx, vy, vz, vt;

ll sqr(ll x) {return x * x;}

int check(ll val) {
	FOR(i, 0, n) if (vl[i].fi >= 0) {
		if (sqr(vl[i].fi) > val) break;
		ll t = 0, dmax = -LINF, dmin = LINF;
		int k = upper_bound(all(vx), mp(vl[i].fi, LINF)) - vx.begin();
		if (k < sz(vx)) {
			t = max(t, sqr(vl[i].fi) + sqr(vx[k].se));
			t = max(t, sqr(vl[i].fi) + sqr(vy[k].se));
			dmax = max(dmax, vx[k].se);
			dmin = min(dmin, vy[k].se);
		}
		ll l = 0, r = INF;
		while (l < r) {
			ll m = (l + r + 1) >> 1;
			if (sqr(vl[i].fi + m) <= val) l = m; else r = m - 1;
		}
		k = upper_bound(all(vz), mp(l, LINF)) - vz.begin();
		if (k < sz(vz)) {
			t = max(t, sqr(vl[i].fi) + sqr(vz[k].se));
			t = max(t, sqr(vl[i].fi) + sqr(vt[k].se));
			dmax = max(dmax, vz[k].se);
			dmin = min(dmin, vt[k].se);
		}
		if (dmax >= dmin) t = max(t, sqr(dmax - dmin));
		if (t <= val) return 1;
	}
	return 0;
}

void preprocess() {
	vx.clear(); vy.clear(); vz.clear(); vt.clear();
	FOR(i, 0, n) {
		vx.pb(mp(abs(vl[i].fi), vl[i].se));
		vy.pb(mp(abs(vl[i].fi), vl[i].se));
		if (vl[i].fi < 0) {
			vz.pb(mp(-vl[i].fi, vl[i].se));
			vt.pb(mp(-vl[i].fi, vl[i].se));
		}
	}
	sort(all(vx)); sort(all(vy)); sort(all(vz)); sort(all(vt));
	FORd(i, n - 1, 0) {
		vx[i].se = max(vx[i].se, vx[i + 1].se);
		vy[i].se = min(vy[i].se, vy[i + 1].se);
	}
	FORd(i, sz(vz) - 1, 0) {
		vz[i].se = max(vz[i].se, vz[i + 1].se);
	}
	FORd(i, sz(vt) - 1, 0) {
		vt[i].se = min(vt[i].se, vt[i + 1].se);
	}
}

void solve() {
	cin>>n;
	ll xmin = LINF, xmax = -LINF, ymin = LINF, ymax = -LINF;
	FOR(i, 0, n) {
		ll x, y; cin>>x>>y;
		xmin = min(xmin, x);
		xmax = max(xmax, x);
		ymin = min(ymin, y);
		ymax = max(ymax, y);
		vl.pb(mp(x, y));
	}
	ll ans = LINF;
	ans = min(ans, sqr(xmax - xmin));
	ans = min(ans, sqr(ymax - ymin));
	sort(all(vl));
	preprocess();
	ll l = 0, r = LINF;
	while (l < r) {
		ll m = (l + r) >> 1;
		if (!check(m)) l = m + 1; else r = m;
	}
	ans = min(ans, l);
	FOR(i, 0, n) vl[i].fi *= -1;
	reverse(all(vl));
	preprocess();
	l = 0; r = LINF;
	while (l < r) {
		ll m = (l + r) >> 1;
		if (!check(m)) l = m + 1; else r = m;
	}
	ans = min(ans, l);
	cout<<ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}