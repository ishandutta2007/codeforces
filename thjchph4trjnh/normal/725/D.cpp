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

struct Node {
	Node();
	Node *l, *r, *p;
	int size;
	pair<long long, long long> key;
};
Node* nil = new Node();
Node::Node() {
	l = r = p = nil;
	size = 1;
}
void init() {
	nil->l = nil->r = nil->p = nil;
	nil->size = 0;
}
int isrt(Node* x) {
	return x->p == nil || (x->p->l != x && x->p->r != x);
}
void setchild(Node* p, Node* c, int l) {
	c->p = p; l ? p->l = c : p->r = c;
}
void pushup(Node* x) {
	x->size = x->l->size + x->r->size + 1;
}
void rotate(Node* x) {
	Node* y = x->p;
	int l = x->p->l == x;
	if (!isrt(y)) {
		setchild(y->p, x, y->p->l == y);
	}
	else {
		x->p = y->p;
	}
	setchild(y, l ? x->r : x->l, l);
	setchild(x, y, !l);
	pushup(y);
}
void splay(Node* x) {
	while (!isrt(x)) {
		if (!isrt(x->p)) rotate((x->p->l == x) == (x->p->p->l == x->p) ? x->p : x);
		rotate(x);
	}
	pushup(x);
}

const int MAXN = 1000000 + 10;
struct SplayTree {
	Node mem[MAXN], *root;
	int cur;
	SplayTree() {
		root = nil; cur = 0;
		init();
	}
	Node* alloc(pair<long long, long long> key) {
		mem[cur].key = key;
		return mem + (cur++);
	}
	Node* insert(Node* x, pair<long long, long long> key) {
		Node* p = nil;
		while (x != nil) {
			p = x;
			if (x->key < key) x = x->r;
			else x = x->l;
		}
		x = alloc(key);
		x->p = p;
		if (p == nil) {
			root = x;
		}
		else if (p->key < x->key) p->r = x;
		else p->l = x;
		splay(x);
		return root = x;
	}
	Node* insert(pair<long long, long long> key) {
		return insert(root, key);
	}
	Node* findkey(Node* x, pair<long long, long long> key) {
		while (x != nil) {
			if (x->key < key) x = x->r;
			else if (key < x->key) x = x->l;
			else {
				splay(x);
				return root = x;
			}
		}
		return nil;
	}
	Node* findkey(pair<long long, long long> key) {
		return findkey(root, key);
	}
	Node* join(Node* x, Node* y) {
		x->p = y->p = nil;
		if (x == nil) return root = y;
		if (y == nil) return root = x;
		while (1) {
			if (x->r == nil) break;
			x = x->r;
		}
		splay(x);
		setchild(x, y, 0);
		pushup(x);
		return root = x;
	}
	void erase(pair<long long, long long> key) {
		Node* x = findkey(key);
		x->l->p = x->r->p = nil;
		join(x->l, x->r);
	}
	int query(long long val) {
		Node* x = insert(mp(val, LINF));
		int res = x->r->size;
		x->l->p = x->r->p = nil;
		join(x->l, x->r);
		return res;
	}
} slt;

const int maxn = 300000 + 10;
int n;
long long t[maxn];
long long w[maxn];

int compare(int i, int j) {
	if (t[i] != t[j]) return t[i] > t[j];
	return i < j;
}

void solve() {
	cin >> n;
	set<pair<long long, int> > s;
	vi v;
	FOR(i, 0, n) {
		cin >> t[i] >> w[i];
		slt.insert(mp(t[i], 0));
		if (i) {
			if (t[i] > t[0]) {
				s.insert(mp(w[i] - t[i], i));
			}
			else {
				v.pb(i);
			}
		}
	}
	sort(all(v), compare);
	int ans = slt.query(t[0]);
	int ptr = 0;
	while (sz(s)) {
		int ix = s.begin()->se;
		s.erase(s.begin());
		if (t[0] >= w[ix] - t[ix] + 1) {
			slt.erase(mp(t[0], 0));
			t[0] -= w[ix] - t[ix] + 1;
			slt.insert(mp(t[0], 0));
			slt.erase(mp(t[ix], 0));
			chkmin(ans, slt.query(t[0]));
		}
		else {
			break;
		}
		while (ptr < sz(v)) {
			int ix = v[ptr];
			if (t[ix] > t[0]) {
				s.insert(mp(w[ix] - t[ix], ix));
				ptr++;
			}
			else {
				break;
			}
		}
	}
	cout << ans + 1 << "\n";
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