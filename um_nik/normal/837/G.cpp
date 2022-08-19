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

const ll MOD = (ll)1e9;

struct Node
{
	int L, R;
	int l, r;
	ll k, b;

	Node() : L(-1), R(-1), l(-1), r(-1), k(0), b(0) {}
	Node(int _l, int _r) : L(-1), R(-1), l(_l), r(_r), k(0), b(0) {}
};
const int S = (int)5e6;
const int N = 200100;
Node tree[S];
int sz;
int roots[N];

int build(int l, int r)
{
	int v = sz++;
	tree[v] = Node(l, r);
	if (l + 1 == r) return v;
	int mid = (l + r) / 2;
	tree[v].L = build(l, mid);
	tree[v].R = build(mid, r);
	return v;
}
int changePos(int v, int p, ll k, ll b) {
	if (p < tree[v].l || tree[v].r <= p)
		return v;
	int u = sz++;
	tree[u] = tree[v];
	if (tree[u].l + 1 == tree[u].r) {
		tree[u].k = k;
		tree[u].b = b;
		return u;
	}
	tree[u].L = changePos(tree[v].L, p, k, b);
	tree[u].R = changePos(tree[v].R, p, k, b);
	tree[u].k = tree[tree[u].L].k + tree[tree[u].R].k;
	tree[u].b = tree[tree[u].L].b + tree[tree[u].R].b;
	return u;
}
ll getVal(int v, int l, int r, ll x)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].k * x + tree[v].b;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	return getVal(tree[v].L, l, r, x) + getVal(tree[v].R, l, r, x);
}

struct Query
{
	int p;
	ll k, b;

	Query() : p(), k(), b() {}
	Query(int _p, ll _k, ll _b) : p(_p), k(_k), b(_b) {}
};
vector<Query> q[N];

void read()
{
	int n;
	scanf("%d", &n);
	int root = build(0, n);
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, a, b, y2;
		scanf("%d%d%d%d%d%d", &x1, &x2, &y1, &a, &b, &y2);
		if (x2 > N - 5) throw;
		root = changePos(root, i, 0, y1);
		q[x1 + 1].push_back(Query(i, a, b));
		q[x2 + 1].push_back(Query(i, 0, y2));
	}
	roots[0] = root;
	for (int i = 1; i < N; i++) {
		for (Query Q : q[i]) {
			root = changePos(root, Q.p, Q.k, Q.b);
		}
		roots[i] = root;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	ll last = 0;
	int Q;
	scanf("%d", &Q);
	while(Q--) {
		int l, r;
		ll x;
		scanf("%d%d%lld", &l, &r, &x);
		l--;
		x = (x + last) % MOD;
		last = getVal(roots[min((int)x, N - 1)], l, r, x);
		printf("%lld\n", last);
	}

	return 0;
}