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

const int maxn = 300000 + 10;
int n;
int a[maxn];

struct Node {
	long long l, r;
	int len;
	int lmx, rmx;
	int llmx, rrmx;
	int mx;
	Node() : l(-LINF), r(-LINF), len(INF), lmx(INF), rmx(INF), llmx(INF), rrmx(INF), mx(INF) {}
	Node(long long l, long long r, int lmx, int rmx) : l(l), r(r), len(len), lmx(lmx), rmx(rmx), llmx(llmx), rrmx(rrmx), mx(mx) {}
	Node(const Node& rhs) : l(rhs.l), r(rhs.r), len(rhs.len), lmx(rhs.lmx), rmx(rhs.rmx), llmx(rhs.llmx), rrmx(rhs.rrmx), mx(rhs.mx) {}
} nil;

Node merge(Node a, Node b) {
	if (a.l == nil.l) return b;
	if (b.l == nil.l) return a;
	Node res;
	res.l = a.l;
	res.r = b.r;
	res.len = a.len + b.len;
	res.lmx = a.lmx;
	if (res.lmx == a.len && a.r > b.l) {
		res.lmx += b.llmx;
	}
	if (a.rrmx == a.len) {
		if (a.r > b.l) {
			chkmax(res.lmx, a.rrmx + b.llmx);
		}
		if (a.r < b.l) {
			chkmax(res.lmx, a.rrmx + b.lmx);
		}
	}
	res.rmx = b.rmx;
	if (res.rmx == b.len && b.l > a.r) {
		res.rmx += a.rrmx;
	}
	if (b.llmx == b.len) {
		if (b.l > a.r) {
			chkmax(res.rmx, b.llmx + a.rrmx);
		}
		if (b.l < a.r) {
			chkmax(res.rmx, b.llmx + a.rmx);
		}
	}
	res.llmx = a.llmx;
	if (res.llmx == a.len && a.r > b.l) {
		res.llmx += b.llmx;
	}
	res.rrmx = b.rrmx;
	if (res.rrmx == b.len && b.l > a.r) {
		res.rrmx += a.rrmx;
	}
	res.mx = max(a.mx, b.mx);
	chkmax(res.mx, res.lmx);
	chkmax(res.mx, res.rmx);
	if (a.r > b.l) {
		chkmax(res.mx, a.rmx + b.llmx);
	}
	if (a.r < b.l) {
		chkmax(res.mx, b.lmx + a.rrmx);
	}
	return res;
}

Node st[maxn << 2];
long long lz[maxn << 2];

void build(int p, int L, int R) {
	if (L == R) {
		st[p].l = st[p].r = a[L];
		st[p].len = 1;
		st[p].lmx = st[p].rmx = 1;
		st[p].llmx = st[p].rrmx = 1;
		st[p].mx = 1;
		return;
	}
	build(p << 1, L, L + R >> 1);
	build(p << 1 | 1, (L + R >> 1) + 1, R);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}

void pushdown(int p, int L, int R) {
	if (lz[p]) {
		st[p].l += lz[p];
		st[p].r += lz[p];
		if (L < R) {
			lz[p << 1] += lz[p];
			lz[p << 1 | 1] += lz[p];
		}
		lz[p] = 0;
	}
}
void upd(int p, int l, int r, int L, int R, int val) {
	pushdown(p, L, R);
	if (l > R || r < L) return;
	if (l <= L && r >= R) {
		lz[p] += val;
		pushdown(p, L, R);
		return;
	}
	upd(p << 1, l, r, L, L + R >> 1, val);
	upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
	st[p] = merge(st[p << 1], st[p << 1 | 1]);
}
Node query(int p, int l, int r, int L, int R) {
	pushdown(p, L, R);
	if (l > R || r < L) return nil;
	if (l <= L && r >= R) return st[p];
	return merge(query(p << 1, l, r, L, L + R >> 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R));
}

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	build(1, 0, n - 1);
	int q; cin >> q;
	while (q--) {
		int l, r, val; cin >> l >> r >> val; l--, r--;
		upd(1, l, r, 0, n - 1, val);
		cout << query(1, 0, n - 1, 0, n - 1).mx << "\n";
	}
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