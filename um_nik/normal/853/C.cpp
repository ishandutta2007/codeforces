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

const int N = 200200;
struct Node {
	int L, R;
	int l, r;
	int val;

	Node() : L(-1), R(-1), l(-1), r(-1), val(0) {}
	Node(int _l, int _r) : L(-1), R(-1), l(_l), r(_r), val(0) {}
};
const int S = (int)7e6;
Node tree[S];
int treeSz;

int build(int l, int r) {
	int v = treeSz++;
	tree[v] = Node(l, r);
	if (l + 1 == r) return v;
	int mid = (l + r) / 2;
	tree[v].L = build(l, mid);
	tree[v].R = build(mid, r);
	return v;
}

int setVal(int v, int p, int x) {
	if (p < tree[v].l || tree[v].r <= p) return v;
	int u = treeSz++;
	tree[u] = tree[v];
	if (tree[v].L == -1) {
		tree[u].val = x;
		return u;
	}
	tree[u].L = setVal(tree[v].L, p, x);
	tree[u].R = setVal(tree[v].R, p, x);
	tree[u].val = tree[tree[u].L].val + tree[tree[u].R].val;
	return u;
}

int getSum(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	return getSum(tree[v].L, l, r) + getSum(tree[v].R, l, r);
}

int roots[N];
int n, q;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	roots[0] = build(0, n);
	for (int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);
		p--;
		roots[i + 1] = setVal(roots[i], p, 1);
	}
	while(q--) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		ll ans = (ll)n * (n - 1);
		ans -= (ll)x1 * (x1 - 1);
		ans -= (ll)(n - x2) * (n - x2 - 1);
		ans -= (ll)y1 * (y1 - 1);
		ans -= (ll)(n - y2) * (n - y2 - 1);
		ll cnt = getSum(roots[x1], 0, y1);
		ans += cnt * (cnt - 1);
		cnt = getSum(roots[x1], y2, n);
		ans += cnt * (cnt - 1);
		cnt = y1 - getSum(roots[x2], 0, y1);
		ans += cnt * (cnt - 1);
		cnt = n - y2 - getSum(roots[x2], y2, n);
		ans += cnt * (cnt - 1);
		printf("%lld\n", ans / 2);
	}

	return 0;
}