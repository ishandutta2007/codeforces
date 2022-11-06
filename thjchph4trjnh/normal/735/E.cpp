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

const int maxn = 100 + 10;
const int maxk = 40 + 10;
int n, k;
vi adj[maxn];
int dep[maxn];
int f[maxn][maxk][maxk];

void dfs(int u, int p = -1) {
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != p) {
			dfs(v, u);
			chkmax(dep[u], dep[v] + 1);
		}
	}
}

int calc(int u, int pv, int mn, int p = -1) {
	if (pv > k && mn > k) return 0;
	int& res = f[u][pv][mn];
	if (~res) return res;
	res = 0;
	if (!mn) {
		res = 1;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i];
			if (v != p) {
				int tmp = 0;
				FOR(j, 0, 2 * k + 5) {
					addmod(tmp, calc(v, 1, j, u));
				}
				if (dep[v] + 1 <= k) {
					addmod(tmp, 1);
				}
				res = mult(res, tmp);
			}
		}
	}
	else {
		res = 0;
		int p1 = 1, p2 = 1, tot = 0;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i];
			if (v != p) {
				tot++;
				int tmp1 = 0, tmp2 = 0;
				FOR(j, mn - 1, 2 * k + 5) {
					if (j == mn - 1) {
						addmod(tmp1, calc(v, min(pv + 1, k + 1), j, u));
					}
					else {
						addmod(tmp1, calc(v, min(min(pv + 1, mn + 1), k + 1), j, u));
						addmod(tmp2, calc(v, min(min(pv + 1, mn + 1), k + 1), j, u));
					}
				}
				if (dep[v] + 1 + min(pv, mn) <= k) {
					addmod(tmp1, 1);
					addmod(tmp2, 1);
				}
				p1 = mult(p1, tmp1);
				p2 = mult(p2, tmp2);
			}
		}
		if (tot) {
			submod(p1, p2);
			res = p1;
		}
	}
	return res;
}

void solve() {
	cin >> n >> k;
	FOR(i, 0, n - 1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}
	dfs(0);
	ms(f, -1);
	int ans = 0;
	FOR(i, 0, 2 * k + 5) {
		addmod(ans, calc(0, k + 1, i));
	}
	cout << ans << "\n";
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