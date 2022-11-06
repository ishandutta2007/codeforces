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

const int maxn = 100010;
int n, q;
int a[maxn];
vi adj[maxn];
int lev[maxn];
int p[maxn];
int ans[maxn];

const int MAXN = 2000010;
bool flag[MAXN];
int sp[MAXN];
vi divisor[MAXN];
int tb[MAXN];
void Sieve() {
	for (int i = 2; i < MAXN; i += 2) sp[i] = 2;
	for (int i = 3; i < MAXN; i += 2) if (!flag[i]) {
		sp[i] = i;
		for (int j = i; 1LL * i * j < MAXN; j += 2) if (!flag[i * j]) {
			flag[i * j] = 1;
			sp[i * j] = i;
		}
	}
}

void dfs(int u, int dad = -1) {
	vii his;
	FOR(i, 0, sz(divisor[a[u]])) {
		int k = divisor[a[u]][i];
		if (~tb[k]) {
			if (!~ans[u] || lev[ans[u]] < lev[tb[k]]) {
				ans[u] = tb[k];
			}
		}
		his.pb(mp(k, tb[k]));
		tb[k] = u;
	}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (v != dad) {
			lev[v] = lev[u] + 1;
			p[v] = u; dfs(v, u);
		}
	}
	FOR(i, 0, sz(his)) {
		tb[his[i].fi] = his[i].se;
	}
}

void solve() {
	Sieve();
	FOR(i, 2, MAXN) {
		int k = i;
		while (k > 1) {
			if (!sz(divisor[i]) || divisor[i].back() != sp[k]) {
				divisor[i].pb(sp[k]);
			}
			k /= sp[k];
		}
	}
	scanf("%d%d", &n, &q);
	FOR(i, 0, n) scanf("%d", a + i);
	FOR(i, 0, n - 1) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	ms(ans, -1); ms(tb, -1); dfs(0);
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int u; scanf("%d", &u); u--;
			if (~ans[u]) printf("%d\n", ans[u] + 1); else printf("-1\n");
		}
		else {
			int u, w; scanf("%d%d", &u, &w); u--;
			a[u] = w; ms(ans, -1); dfs(0);
		}
	}
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}