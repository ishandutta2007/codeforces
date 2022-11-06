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
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
int n, t, q;
int p[maxn];
int l[maxn];
int f[maxn];
ld g[maxn];
ld h[maxn];
set<pair<ld, int> > st1, st2;
ld ans;

void update() {
	while (t && sz(st1)) {
		int u = st1.rbegin()->se;
		ld x = (ld) p[u] * f[u] / (f[u] + l[u]);
		ans -= x;
		f[u]++;
		ld y = (ld) p[u] * f[u] / (f[u] + l[u]);
		ans += y;
		if (st2.find(mp(h[u], u)) != st2.end()) {
			st2.erase(mp(h[u], u));
		}
		h[u] = y - x;
		st2.insert(mp(h[u], u));
		st1.erase(mp(g[u], u));
		if (f[u] + 1 <= l[u]) {
			g[u] = (ld) p[u] * (f[u] + 1) / (f[u] + l[u] + 1) - (ld) p[u] * f[u] / (f[u] + l[u]);
			st1.insert(mp(g[u], u));
		}
		t--;
	}
}

void solve() {
	scanf("%d%d%d", &n, &t, &q);
	FOR(i, 0, n) scanf("%d", p + i);
	FOR(i, 0, n) {
		scanf("%d", l + i);
		g[i] = (ld) p[i] / (l[i] + 1);
		st1.insert(mp(g[i], i));
	}
	update();
	while (q--) {
		int op, u; scanf("%d%d", &op, &u); u--;
		if (f[u]) {
			ans -= (ld) p[u] * f[u] / (f[u] + l[u]);
			f[u]--; t++;
		}
		if (st1.find(mp(g[u], u)) != st1.end()) {
			st1.erase(mp(g[u], u));
		}
		if (st2.find(mp(h[u], u)) != st2.end()) {
			st2.erase(mp(h[u], u));
		}
		int v = -1;
		if (sz(st2) && st2.begin()->se != u) {
			v = st2.begin()->se;
			ans -= (ld) p[v] * f[v] / (f[v] + l[v]);
			f[v]--; t++;
			if (st1.find(mp(g[v], v)) != st1.end()) {
				st1.erase(mp(g[v], v));
			}
			st2.erase(mp(h[v], v));
		}
		if (op == 1) l[u]++; else l[u]--;
		ans += (ld) p[u] * f[u] / (f[u] + l[u]);
		if (f[u] + 1 <= l[u]) {
			g[u] = (ld) p[u] * (f[u] + 1) / (f[u] + l[u] + 1) - (ld) p[u] * f[u] / (f[u] + l[u]);
			st1.insert(mp(g[u], u));
		}
		if (f[u]) {
			h[u] = (ld) p[u] * ((ld) f[u] / (f[u] + l[u]) - (ld) (f[u] - 1) / (f[u] + l[u] - 1));
			st2.insert(mp(h[u], u));
		}
		if (~v) {
			ans += (ld) p[v] * f[v] / (f[v] + l[v]);
			if (f[v] + 1 <= l[v]) {
				g[v] = (ld) p[v] * (f[v] + 1) / (f[v] + l[v] + 1) - (ld) p[v] * f[v] / (f[v] + l[v]);
				st1.insert(mp(g[v], v));
			}
			if (f[v]) {
				h[v] = (ld) p[v] * ((ld) f[v] / (f[v] + l[v]) - (ld) (f[v] - 1) / (f[v] + l[v] - 1));
				st2.insert(mp(h[v], v));
			}
		}
		update();
		cout<<prec(9)<<ans<<"\n";
	}
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