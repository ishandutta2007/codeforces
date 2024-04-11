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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

struct Linear {
	ll k, b;

	Linear() : k(1), b() {}
	Linear(ll _k, ll _b) : k(_k), b(_b) {}

	Linear apply(const Linear &A) const {
		return Linear(mult(k, A.k), add(A.b, mult(A.k, b)));
	}

	ll getVal(ll x) {
		return add(mult(k, x), b);
	}
};

const int N = 1 << 18;
struct Node {
	int l, r;
	ll val;
	Linear toAdd;

	Node() : l(-1), r(-1), val(), toAdd() {}
	Node(int _l, int _r) : l(_l), r(_r), val(), toAdd() {}

	void change(const Linear &A) {
		ll len = r - l;
		val = add(mult(val, A.k), mult(A.b, len));
		toAdd = toAdd.apply(A);
	}
};
Node tree[2 * N + 5];

void buildTree() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void push(int v) {
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].change(tree[v].toAdd);
	}
	tree[v].toAdd = Linear();
}
void update(int v) {
	if (v >= N) throw;
	tree[v].val = add(tree[2 * v].val, tree[2 * v + 1].val);
}

void applyOnSegm(int v, int l, int r, Linear L) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].change(L);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	applyOnSegm(2 * v, l, r, L);
	applyOnSegm(2 * v + 1, l, r, L);
	update(v);
}

ll getSum(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	push(v);
	return add(getSum(2 * v, l, r), getSum(2 * v + 1, l, r));
}

set<pii> setForCol[N + 5];
int n;

void solve(int c, int L, int R) {
	int LL = L, RR = R;
	while(L < R) {
		auto it = setForCol[c].lower_bound(mp(L, R));
		if (it != setForCol[c].begin()) {
			it--;
			if (it->second < L) it++;
		}
		if (it == setForCol[c].end()) break;
		if (it->first > R) break;
		int l = it->first, r = it->second;
		LL = min(LL, l);
		RR = max(RR, r);
		setForCol[c].erase(it);
		if (L < l) {
			applyOnSegm(1, L, l, Linear(1, 1));
			L = l;
		}
		applyOnSegm(1, L, min(r, R), Linear(2, 0));
		L = min(r, R);
	}
	if (L < R) {
		applyOnSegm(1, L, R, Linear(1, 1));
	}
	setForCol[c].insert(mp(LL, RR));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d%d", &n, &q);
	buildTree();
	while(q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		l--;
		if (t == 1) {
			int c;
			scanf("%d", &c);
			c--;
			solve(c, l, r);
		} else {
			printf("%lld\n", getSum(1, l, r));
		}
	}

	return 0;
}