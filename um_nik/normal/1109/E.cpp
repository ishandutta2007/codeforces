#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll MOD = 1;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll euclid(ll x, ll y, ll &k, ll &l) {
	if (y == 0) {
		k = 1;
		l = 0;
		return x;
	}
	ll g = euclid(y, x % y, l, k);
	l -= k * (x / y);
	return g;
}
ll rev(ll x) {
	ll k, l;
	if (euclid(x, MOD, k, l) != 1) throw;
	k %= MOD;
	if (k < 0) k += MOD;
	return k;
}

const int K = 9;
const int C = (int)1e5 + 2;

vector<ll> pr;
vector<ll> pws[K];
int m = 0;

struct Num {
	ll x;
	int a[K];

	Num() {
		//cerr << "here" << endl;
		x = 0;
		for (int i = 0; i < m; i++)
			a[i] = 0;
	}
	Num(ll z) {
		if (z == -1) {
			x = -1;
		} else {
			for (int i = 0; i < m; i++) {
				a[i] = 0;
				while(z % pr[i] == 0) {
					z /= pr[i];
					a[i]++;
				}
			}
			x = z % MOD;
		}
	}

	ll getVal() {
		ll res = x;
		for (int i = 0; i < m; i++) {
			if (a[i] < 0) throw;
			res = mult(res, pws[i][a[i]]);
		}
		return res;
	}

	Num operator + (const Num &A) const {
		if (A.x == -1) return *this;
		if (x == -1) return A;
		Num R = Num();
		ll c1 = x, c2 = A.x;
		for (int i = 0; i < m; i++) {
			R.a[i] = min(a[i], A.a[i]);
			c1 = mult(c1, pws[i][a[i] - R.a[i]]);
			c2 = mult(c2, pws[i][A.a[i] - R.a[i]]);
		}
		R.x = add(c1, c2);
		return R;
	}
	Num operator * (const Num &A) const {
		Num R = Num();
		R.x = mult(x, A.x);
		for (int i = 0; i < m; i++)
			R.a[i] = a[i] + A.a[i];
		return R;
	}
	Num inv() const {
		Num R = Num();
		R.x = rev(x);
		for (int i = 0; i < m; i++)
			R.a[i] = -a[i];
		return R;
	}
};

const int N = 1 << 17;
struct Node {
	int l, r;
	Num val, toMult;

	Node() : l(), r(), val(Num(-1)), toMult(Num(1)) {}
	Node(int _l, int _r) : l(_l), r(_r), val(Num(-1)), toMult(Num(1)) {}
};
Node tree[2 * N + 7];
ll a[N + 5];
int n;

void build() {
	for (int i = 0; i < N; i++) {
		tree[N + i] = Node(i, i + 1);
		if (i < n) tree[N + i].val = Num(a[i]);
	}
	for (int i = N - 1; i > 0; i--) {
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
		tree[i].val = tree[2 * i].val + tree[2 * i + 1].val;
	}
}

void push(int v) {
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		if (tree[u].val.x == -1) continue;
		tree[u].val = tree[u].val * tree[v].toMult;
		tree[u].toMult = tree[u].toMult * tree[v].toMult;
		//cerr << u << endl;
	}
	tree[v].toMult = Num(1);
}
void update(int v) {
	if (v >= N) throw;
	tree[v].val = tree[2 * v].val + tree[2 * v + 1].val;
}

void multOnSegm(int v, int l, int r, Num x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].val = tree[v].val * x;
		tree[v].toMult = tree[v].toMult * x;
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	multOnSegm(2 * v, l, r, x);
	multOnSegm(2 * v + 1, l, r, x);
	update(v);
}
Num getSum(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return Num(-1);
	push(v);
	Num R = getSum(2 * v, l, r) + getSum(2 * v + 1, l, r);
//	eprintf("getSum %d %d %d\n", v, l, r);
//	R.eprint();
	return R;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

//	return 0;

	scanf("%d%lld", &n, &MOD);
	ll x = MOD;
	for (ll y = 2; y * y <= x; y++) {
		//cerr << y << endl;
		if (x % y) continue;
		pr.push_back(y);
		while(x % y == 0) x /= y;
	}
	if (x > 1)
		pr.push_back(x);
	m = (int)pr.size();

	for (int k = 0; k < m; k++) {
		int L = 0;
		x = C;
		while(x > 0) {
			x /= pr[k];
			L++;
		}
		L *= C;
		L += 2;
		pws[k].resize(L);
		pws[k][0] = 1;
		for (int i = 1; i < L; i++)
			pws[k][i] = mult(pws[k][i - 1], pr[k]);
	}

	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

//	eprintf("before build\n");

	build();

//	eprintf("builded\n");

	int q;
	scanf("%d", &q);
	while(q--) {
		int t;
		scanf("%d", &t);
		//eprintf("%d\n", t);
		if (t == 1) {
			int l, r;
			scanf("%d%d%lld", &l, &r, &x);
			l--;
			multOnSegm(1, l, r, Num(x));
		} else if (t == 2) {
			int p;
			scanf("%d%lld", &p, &x);
			p--;
			multOnSegm(1, p, p + 1, Num(x).inv());
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			Num X = getSum(1, l, r);
//			X.eprint();
			printf("%lld\n", X.getVal());
		}
	}

	return 0;
}