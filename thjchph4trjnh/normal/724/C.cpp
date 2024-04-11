#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100000 + 10;
int n, m, k;
int x[maxn];
int y[maxn];
long long mn[maxn];

pi euclid(int a, int b) {
	if (b == 0) return mp(1, 0);
	pi r = euclid(b, a % b);
	return mp(r.second, r.first - a / b * r.second);
}

long long calc(int x, int y, int sig1, int sig2) {
	int d = m + sig2 * (m - y) - n - sig1 * (n - x);
	int g = __gcd(2 * n, 2 * m);
	if (d % g) return LINF;
	pi r = euclid(2 * n / g, 2 * m / g);
	r.fi *= +d / g;
	r.se *= -d / g;
	int u = m / __gcd(n, m);
	int v = n / __gcd(n, m);
	while (r.fi < 0 || r.se < 0) {
		int add = 0;
		if (r.fi < 0) {
			chkmax(add, (-r.fi + u - 1) / u);
		}
		if (r.se < 0) {
			chkmax(add, (-r.se + v - 1) / v);
		}
		r.fi += add * u;
		r.se += add * v;
	}
	while (r.fi >= u && r.se >= v) {
		r.fi -= u;
		r.se -= v;
	}
	long long xx = (long long) r.fi * 2 * n + n + sig1 * (n - x);
	if (!xx) {
		r.fi += m / __gcd(n, m);
		xx = (long long) r.fi * 2 * n + n + sig1 * (n - x);
	}
	return xx;
}

void solve() {
	cin >> n >> m >> k;
	long long tmp = LINF;
	FOR(sig1, -1, 2) FOR(sig2, -1, 2) if (sig1 && sig2) {
		chkmin(tmp, calc(0, 0, sig1, sig2));
		chkmin(tmp, calc(n, 0, sig1, sig2));
		chkmin(tmp, calc(0, m, sig1, sig2));
		chkmin(tmp, calc(n, m, sig1, sig2));
	}
	FOR(i, 0, k) {
		cin >> x[i] >> y[i];
		mn[i] = LINF;
		FOR(sig1, -1, 2) FOR(sig2, -1, 2) if (sig1 && sig2) {
			chkmin(mn[i], calc(x[i], y[i], sig1, sig2));
		}
		if (mn[i] >= tmp) {
			cout << -1 << "\n";
		}
		else {
			cout << mn[i] << "\n";
		}
	}
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