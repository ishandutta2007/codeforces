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

const int maxn = 300010;
int n, m, k;
vector<pair<int, pi> > adj[maxn];
vi rou;
int dmin[maxn];
ll d[maxn];
int f[maxn];

void solve() {
	ms(dmin, 0x3f);
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, m) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w); u--; v--;
		adj[u].pb(mp(v, mp(w, 0))); adj[v].pb(mp(u, mp(w, 0)));
	}
	FOR(i, 0, k) {
		int u, w; scanf("%d%d", &u, &w); u--;
		rou.pb(u); dmin[u] = min(dmin[u], w);
	}
	sort(all(rou)); uni(rou);
	FOR(i, 0, sz(rou)) {
		int u = rou[i];
		int w = dmin[u];
		adj[0].pb(mp(u, mp(w, 1)));
	}
	FOR(i, 0, n) d[i] = LINF; d[0] = 0;
	priority_queue<pair<ll, int> > pq; pq.push(mp(-d[0], 0));
	while (sz(pq)) {
		int u = pq.top().se;
		ll w = -pq.top().fi;
		pq.pop();
		if (d[u] != w) continue;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i].fi;
			int w = adj[u][i].se.fi;
			int idx = adj[u][i].se.se;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				f[v] = idx;
				pq.push(mp(-d[v], v));
			}
			else {
				if (d[v] == d[u] + w && !idx) f[v] = 0;
				if (d[v] < d[u] + w) if (idx) f[v] = 0;
			}
		}
	}
	int ans = 0;
	FOR(i, 0, sz(rou)) ans += f[rou[i]];
	printf("%d", k - ans);
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