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
#define bit(n, i) (((n) >> (i)) & 1)
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
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 100010;
int n, m;
int a[maxn];
int b[maxn];
int l[maxn];
int r[maxn];
int f[maxn];
int g[maxn];

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n + 1) {
		scanf("%d", a + i);
		l[i] = r[i] = i;
	}
	FOR(i, 0, m) scanf("%d", b + i);
	sort(a + 1, a + n + 1); sort(b, b + m);
	FOR(i, 2, n + 1) {
		if (a[i] == a[i - 1] + 1) {
			l[i] = l[i - 1];
		}
	}
	FOR(i, 1, n + 1) {
		int k = upper_bound(b, b + m, a[i]) - b;
		FOR(j, 0, k) if (i - a[i] + b[j] >= 0 && l[i - a[i] + b[j]]) {
			setmax(g[i], f[l[i - a[i] + b[j]] - 1] + k - j);
		}
		setmax(f[i], f[i - 1]);
		setmax(f[i], g[i]);
		setmax(g[i], g[i - 1]);
		if (l[i] == i) setmax(g[i], f[i - 1]);
		FOR(j, k, m) {
			if (i + b[j] - a[i] <= n) {
				setmax(f[i + b[j] - a[i]], g[i] + j - k + 1);
			}
		}
	}
	printf("%d", f[n]);
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