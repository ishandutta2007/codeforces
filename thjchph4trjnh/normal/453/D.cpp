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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = (int) 1e9 + 7) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

long long mod64_mul(long long a, long long b, long long p) {
	a %= p; b %= p;
	long long r = 0;
	int block = 10;
	long long base = 1LL << block;
	for (; b; b >>= block) {
		r = (r + a * (b & (base - 1))) % p;
		a = a * base % p;
	}
	return r;
}
long long mod64_pow(long long n, long long k, long long p) {
	if (!n) return 0;
	long long r = 1;
	for (; k; k >>= 1) {
		if (k & 1) r = mod64_mul(r, n, p);
		n = mod64_mul(n, n, p);
	}
	return r;
}

void XORFFT(ll a[], int n, ll p, int invert) {
	for (int i = 1; i < n; i <<= 1) {
		for (int j = 0; j < n; j += i << 1) {
			for (int k = 0; k < i; k++) {
				ll u = a[j + k], v = a[i + j + k];
				a[j + k] = (u + v) % p;
				a[i + j + k] = (u - v + p) % p;
			}
		}
	}
	if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}

const int maxm = 23;
const int maxn = 1 << maxm;
int n, m;
ll t, p;
ll a[maxn];
ll b[maxm];
ll e[maxn];
ll f[maxn];

void solve() {
	ms(f, -1);
	scanf("%d%I64d%I64d", &m, &t, &p); n = 1 << m;
	p *= n;
	FOR(i, 0, n) {scanf("%I64d", e + i); e[i] %= p;}
	FOR(i, 0, m + 1) {scanf("%I64d", b + i); b[i] %= p;}
	FOR(i, 0, n) a[i] = b[bitcount(i)];
	XORFFT(e, n, p, 0);
	XORFFT(a, n, p, 0);
	FOR(i, 0, n) {
		if (!~f[bitcount(i)]) a[i] = f[bitcount(i)] = mod64_pow(a[i], t, p);
		else a[i] = f[bitcount(i)];
	}
	FOR(i, 0, n) a[i] = mod64_mul(a[i], e[i], p);
	XORFFT(a, n, p, 1);
	FOR(i, 0, n) printf("%I64d\n", a[i]);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}