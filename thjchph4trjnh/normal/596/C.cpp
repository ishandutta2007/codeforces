#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 100010;
int n;
int x[maxn];
int y[maxn];
int w[maxn];
vi t[2 * maxn];
map<pi, int> tb;
pi ans[maxn];

void solve() {
	scanf("%d", &n);
	vector<pair<pi, int> > v;
	FOR(i, 0, n) {
		scanf("%d%d", x + i, y + i);
		v.pb(mp(mp(x[i], y[i]), y[i] - x[i]));
	}
	FOR(i, 0, n) {
		scanf("%d", w + i);
		t[w[i] + maxn].pb(i);
	}
	FOR(i, 0, 2 * maxn) sort(all(t[i]));
	sort(all(v));
	FORd(i, sz(v), 0) {
		int k = v[i].se + maxn;
		if (!sz(t[k])) {printf("NO"); return;}
		tb[v[i].fi] = t[k].back(); t[k].pop_back();
	}
	FORd(i, sz(v), 0) {
		int k = tb[v[i].fi];
		int p = v[i].fi.fi;
		int q = v[i].fi.se;
		if (p && k <= tb[mp(p - 1, q)]) {printf("NO"); return;}
		if (q && k <= tb[mp(p, q - 1)]) {printf("NO"); return;}
		if (p && q && k <= tb[mp(p - 1, q - 1)]) {printf("NO"); return;}
	}
	printf("YES\n");
	FORall(it, tb) ans[it->se] = it->fi;
	FOR(i, 0, n) printf("%d %d\n", ans[i].fi, ans[i].se);
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