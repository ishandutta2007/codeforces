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

void insert(int x, vi& v) {
//	for a in v
//		if a & -a & x
//			x ^= a
//	if !x
//		return
//	for a in v
//		if x & -x & a
//			a ^= x
//	v.push(x)
	
	FOR(i, 0, sz(v)) if (v[i] & -v[i] & x) x ^= v[i];
	if (!x) return;
	FOR(i, 0, sz(v)) if (x & - x & v[i]) v[i] ^= x;
	v.pb(x);
}

int count(int n) {
	if (!n) return 0;
	int l = 0, r = 30;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		if ((1 << m) <= n) l = m; else r = m - 1;
	}
	return l + 1;
}

void gauss(vi& f) {
	vi v[32];
	FOR(i, 0, sz(f)) {
		v[count(f[i])].pb(f[i]);
	}
	f.clear();
	FORd(i, 32, 1) {
		if (sz(v[i])) {
			f.pb(v[i][0]);
			while (sz(v[i]) > 1) {
				int k = v[i].back() ^ v[i][0];
				if (k) v[count(k)].pb(k);
				v[i].pop_back();
			}
		}
	}
}

struct Node {
	int l, r;
	vi f;
	Node() {l = r = -1;}
} null;

Node merge(Node n1, Node n2) {
	if (!~n1.l) return n2;
	if (!~n2.l) return n1;
	Node res = n1;
	res.l = min(res.l, n2.l);
	res.r = max(res.r, n2.r);
//	FOR(i, 0, sz(n2.f)) {
//		res.f.pb(n2.f[i]);
//	}
	int k = n1.r ^ n2.l;
	if (k) insert(k, res.f);
//	gauss(res.f);
	FOR(i, 0, sz(n2.f)) insert(n2.f[i], res.f);
	return res;
}

const int maxn = 200010;
int n, q;
int a[maxn];

Node st[4 * maxn];
int lz[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {
		st[node].l = st[node].r = a[L];
		return;
	}
	build(node << 1, L, (L + R) >> 1);
	build((node << 1) + 1, ((L + R) >> 1) + 1, R);
	st[node] = merge(st[node << 1], st[(node << 1) + 1]);
}
void updatelz(int node, int L, int R) {
	if (~lz[node]) {
		st[node].l ^= lz[node];
		st[node].r ^= lz[node];
		if (L < R) {
			if (~lz[node << 1]) lz[node << 1] ^= lz[node]; else lz[node << 1] = lz[node];
			if (~lz[(node << 1) + 1]) lz[(node << 1) + 1] ^= lz[node]; else lz[(node << 1) + 1] = lz[node];
		}
		lz[node] = -1;
	}
}
void update(int node, int l, int r, int L, int R, int val) {
	updatelz(node, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[node] = val;
		updatelz(node, L, R);
		return;
	}
	update(node << 1, l, r, L, (L + R) >> 1, val);
	update((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R, val);
	st[node] = merge(st[node << 1], st[(node << 1) + 1]);
}
Node query(int node, int l, int r, int L, int R) {
	updatelz(node, L, R);
	if (l > R || r < L) return null;
	if (l <= L && r >= R) return st[node];
	return merge(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

void solve() {
	ms(lz, -1);
	scanf("%d%d", &n, &q);
	FOR(i, 0, n) scanf("%d", a + i);
	build(1, 0, n - 1);
	while (q--) {
		int op, l, r; scanf("%d%d%d", &op, &l, &r); l--; r--;
		if (op == 1) {
			int k; scanf("%d", &k);
			update(1, l, r, 0, n - 1, k);
		}
		else {
			Node res = query(1, l, r, 0, n - 1);
			if (res.l) insert(res.l, res.f);
//			if (res.l) res.f.pb(res.l);
//			gauss(res.f);
			printf("%I64d\n", 1LL << sz(res.f));
//			cout<<q<<"\n";
		}
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