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

const int maxn = 1000010;
int n, c;
int lmin[maxn];
int lmax[maxn];
int rmin[maxn];
int rmax[maxn];
vi ans;

int st[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {st[node] = max(lmax[L], rmax[L]); return;}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = max(st[node << 1], st[(node << 1) + 1]);
}
int query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return -1;
	if (l <= L && r >= R) return st[node];
	return max(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

int go(int from, int to) {
	if (from > to) return 1;
	if (from == to) {
		ans.pb(from);
		return 1;
	}
	if (lmax[from] < 0) {
		ans.pb(from);
		if (go(from + 1, to)) return 1; else return 0;
	}
	FOR(i, max(from + 1, lmax[from]), min(to + 1, rmin[from])) {
		if (query(1, from + 1, i, 0, n - 1) <= i) {
			if (!go(from + 1, i)) return 0;
			ans.pb(from);
			if (!go(i + 1, to)) return 0;
			return 1;
		}
	}
	return 0;
}

void solve() {
	ms(lmin, 0x3f); ms(lmax, -1); ms(rmin, 0x3f); ms(rmax, -1);
	scanf("%d%d", &n, &c);
	FOR(i, 0, c) {
		int u, v; char dir[10]; scanf("%d%d%s", &u, &v, dir); u--; v--;
		if (u >= v) {printf("IMPOSSIBLE"); return;}
		if (dir[0] == 'L') {
			lmin[u] = min(lmin[u], v);
			lmax[u] = max(lmax[u], v);
		}
		else {
			rmin[u] = min(rmin[u], v);
			rmax[u] = max(rmax[u], v);
		}
	}
	build(1, 0, n - 1);
	if (!go(0, n - 1)) printf("IMPOSSIBLE");
	else {
		FOR(i, 0, sz(ans)) printf("%d ", ans[i] + 1);
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