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
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}

const int MAXN = 1 << 16;
typedef complex<double> cplex;
void fft(cplex a[], int n, int oper) {
	for (int i = 1, j = 0; i < n; i++) {
		for (int s = n; j ^= s >>= 1, ~j & s; );
		if (i < j) swap(a[i], a[j]);
	}
	for (int m = 1; m < n; m *= 2) {
		double p = PI / m * oper;
		cplex w = cplex(cos(p), sin(p));
		for (int i = 0; i < n; i += m * 2) {
			cplex unit = 1;
			for (int j = 0; j < m; j++) {
				cplex &x = a[i + j + m], &y = a[i + j], t = unit * x;
				x = y - t;
				y = y + t;
				unit *= w;
			}
		}
	}
	if (oper == -1) for (int i = 0; i < n; i++) a[i] /= n;
}
const int K = 3;
static cplex ap[K][MAXN << 1], bp[K][MAXN << 1], cc[MAXN << 1];
void multiply(int a[], int b[], int c[], int na, int nb, int mod = (int) 1e9 + 7) {
	int n = 1; while (n < na + nb) n *= 2;
	int base = (int) cbrt(mod) + 1;
	FOR(i, 0, n) FOR(j, 0, K) {
		ap[j][i] = a[i] % base;
		a[i] /= base;
		bp[j][i] = b[i] % base;
		b[i] /= base;
	}
	FOR(i, 0, K) {
		fft(ap[i], n, 1);
		fft(bp[i], n, 1);
	}
	FOR(i, 0, n) c[i] = 0;
	FOR(i, 0, K) FOR(j, 0, K) {
		FOR(k, 0, n) cc[k] = ap[i][k] * bp[j][k];
		fft(cc, n, -1);
		FOR(k, 0, n) {
			long long z = (long long) (cc[k].real() + 0.5);
			z = (z % mod + mod) % mod;
			FOR(l, 0, i + j) z = z * base % mod;
			c[k] += z; if (c[k] >= mod) c[k] -= mod;
		}
	}
}

const int maxn = 1 << 16;
ll n;
int k;
int a[maxn];
int b[maxn];
int c[maxn << 1];
int d[maxn];
int fac[maxn];
int rfac[maxn];

int binomial(int a, int b) {
	if (!a || a == b) return 1;
	if (a > b) return 0;
	return (ll) fac[b] * rfac[a] % MOD * rfac[b - a] % MOD;
}

void go(ll n) {
	if (n == 1) {
		FOR(i, 1, k + 1) a[i] = 1;
		return;
	}
	if (!(n & 1)) {
		go(n >> 1);
		int d = 0;
		FOR(i, 1, k + 1) {
			b[i] = (ll) a[i] * rfac[i] % MOD * fpow(2, (ll) i * (n >> 1)) % MOD;
		}
		FOR(i, 1, k + 1) {
			a[i] = (ll) a[i] * rfac[i] % MOD;
		}
		multiply(a, b, c, k + 1, k + 1);
		FOR(i, 1, k + 1) a[i] = (ll) c[i] * fac[i] % MOD;
	}
	else {
		go(n - 1);
		FOR(i, 1, k + 1) {
			b[i] = (ll) rfac[i] * fpow(2, (ll) i * (n - 1)) % MOD;
		}
		FOR(i, 1, k + 1) {
			a[i] = (ll) a[i] * rfac[i] % MOD;
		}
		multiply(a, b, c, k + 1, k + 1);
		FOR(i, 1, k + 1) a[i] = (ll) c[i] * fac[i] % MOD;
	}
}

void solve() {
	fac[0] = rfac[0] = 1;
	FOR(i, 1, maxn) {
		fac[i] = (ll) fac[i - 1] * i % MOD;
		rfac[i] = fpow(fac[i], MOD - 2);
	}
	cin>>n>>k;
	if (n > k) {
		cout<<0;
		return;
	}
	go(n);
	int ans = 0;
	FOR(i, 1, k + 1) {
		addmod(ans, (ll) a[i] * binomial(i, k) % MOD);
	}
	cout<<ans;
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