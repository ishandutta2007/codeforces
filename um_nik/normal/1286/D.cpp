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

const ll MOD = 998244353;
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
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

struct Frac {
	ll p, q;

	Frac () : p(), q(1) {}
	Frac(ll _p, ll _q) {
		p = _p;
		q = _q;
		ll g = gcd(abs(p), abs(q));
		p /= g;
		q /= g;
		if (q < 0) {
			p *= -1;
			q *= -1;
		}
	}

	ll getMod() {
		return mult((p % MOD + MOD) % MOD, rev(q % MOD));
	}

	bool operator < (const Frac &F) const {
		return p * F.q < q * F.p;
	}
	bool operator == (const Frac &F) const {
		return p * F.q == q * F.p;
	}
};

struct Node {
	int l, r;
	ll val[2][2];

	Node() : l(-1), r(-1), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val() {}
};
const int M = 1 << 17;
Node tree[2 * M + 7];
bool canDo[M + 5][2][2];

Node merge(Node L, Node R) {
	if (R.l == -1) return L;
	if (L.l == -1) return R;
	Node A = Node(L.l, R.r);
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++) {
			A.val[x][y] = 0;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++) {
					if (!canDo[L.r][i][j]) continue;
					A.val[x][y] = add(A.val[x][y], mult(L.val[x][i], R.val[j][y]));
				}
		}
	return A;
}
void rebuild(int v, int p) {
	if (p <= tree[v].l || tree[v].r <= p) return;
	for (int u = 2 * v; u < 2 * v + 2; u++)
		rebuild(u, p);
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

Node getVal(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v];
	if (l >= tree[v].r || tree[v].l >= r) return Node();
	return merge(getVal(2 * v, l, r), getVal(2 * v + 1, l, r));
}

struct Event {
	int p, x, y;

	Event() : p(), x(), y() {}
	Event(int _p, int _x, int _y) : p(_p), x(_x), y(_y) {}
};

const int N = 200200;
Frac allT[N];
int n;
ll a[N][3];
int m;
ll RR = rev(10000);
ll ans[N];
vector<Event> ev[N];

void addEvent(Frac T, int p, int x, int y) {
	int pos = lower_bound(allT, allT + m, T) - allT;
	ev[pos].push_back(Event(p, x, y));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
	if (n == 1) {
		printf("0\n");
		return 0;
	}

	for (int i = 1; i < n; i++)
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++)
				canDo[i][x][y] = 1;

	for (int i = 0; i < M; i++)
		tree[M + i] = Node(i, i + 1);
	for (int i = 0; i < n; i++) {
		tree[M + i].val[0][0] = mult(100 - a[i][2], rev(100));
		tree[M + i].val[1][1] = mult(a[i][2], rev(100));
	}
	for (int i = M - 1; i > 0; i--)
		tree[i] = merge(tree[2 * i], tree[2 * i + 1]);

	for (int i = 0; i < n - 1; i++) {
		ll x = a[i + 1][0] - a[i][0];
		allT[m++] = Frac(x, a[i][1] + a[i + 1][1]);
		if (a[i][1] != a[i + 1][1])
			allT[m++] = Frac(x, abs(a[i][1] - a[i + 1][1]));
	}
	allT[m++] = Frac(0, 1);
	sort(allT, allT + m);
	m = unique(allT, allT + m) - allT;

	for (int i = 0; i < n - 1; i++) {
		ll D = a[i + 1][0] - a[i][0];
		addEvent(Frac(D, a[i][1] + a[i + 1][1]), i + 1, 1, 0);
		if (a[i][1] != a[i + 1][1]) {
			int x = 0, y = 0;
			if (a[i][1] > a[i + 1][1]) {
				x = y = 1;
			}
			addEvent(Frac(D, abs(a[i][1] - a[i + 1][1])), i + 1, x, y);
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (Event e : ev[i]) {
//			eprintf("ban %d %d %d\n", e.p, e.x, e.y);
			canDo[e.p][e.x][e.y] = 0;
			rebuild(1, e.p);
		}
		Node A = getVal(1, 0, n);
		ans[i] = 0;
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++)
				ans[i] = add(ans[i], A.val[x][y]);
	}

//	for (int i = 0; i < m; i++)
//		eprintf("%lld ", ans[i]);
//	eprintf("\n");

	for (int i = 0; i < m - 1; i++)
		ans[i] = sub(ans[i], ans[m - 1]);
	ll res = 0;
	for (int i = 0; i < m - 1; i++) {
		res = add(res, mult(ans[i], sub(allT[i + 1].getMod(), allT[i].getMod())));
	}
	printf("%lld\n", res);
	return 0;
}