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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e7;

struct Node
{
	int L, R;
	int l, r;
	int val;

	Node() : L(-1), R(-1), l(-1), r(-1), val(0) {}
	Node(int _l, int _r) : L(-1), R(-1), l(_l), r(_r), val(0) {}
};
const int S = (int)3e6;
Node tree[S];
int treeSz;

int build(int l, int r) {
	int v = treeSz++;
	tree[v] = Node(l, r);
	if (r - l == 1) return v;
	int mid = (l + r) / 2;
	tree[v].L = build(l, mid);
	tree[v].R = build(mid, r);
	return v;
}

int add(int v, int p, int x)
{
	if (tree[v].l > p || tree[v].r <= p) return v;
	if (tree[v].l + 1 == tree[v].r) {
		int u = treeSz++;
		tree[u] = tree[v];
		tree[u].val += x;
		return u;
	}
	int u = treeSz++;
	tree[u] = tree[v];
	tree[u].L = add(tree[v].L, p, x);
	tree[u].R = add(tree[v].R, p, x);
	tree[u].val += x;
	return u;
}

int getSum(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	return getSum(tree[v].L, l, r) + getSum(tree[v].R, l, r);
}

const int N = 35050;
int n, k;
int dp[2][N];
int a[N];
int b[N];
int nxt[N];
int roots[N];

int query(int l, int r)
{
	return getSum(roots[l], l, r);
}

void solve(int l, int r, int L, int R)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	int st = min(m, R);
	int bstVal = -INF;
	int bstPos = -1;
	int curVal = 0;
	if (st < m)
		curVal = query(st, m);
	for (int i = st - 1; i >= L; i--) {
		if (nxt[i] >= m) curVal++;
		if (curVal + dp[0][i] > bstVal) {
			bstVal = curVal + dp[0][i];
			bstPos = i;
		}
	}
	if (bstPos == -1) throw;
	dp[1][m] = bstVal;
	solve(l, m, L, bstPos + 1);
	solve(m + 1, r, bstPos, R);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		b[i] = n;
	for (int i = n - 1; i >= 0; i--) {
		nxt[i] = b[a[i]];
		b[a[i]] = i;
	}

	roots[n] = build(0, n);
	for (int i = n - 1; i >= 0; i--) {
		int v = roots[i + 1];
		if (nxt[i] < n)
			v = add(v, nxt[i], -1);
		v = add(v, i, 1);
		roots[i] = v;
	}

	for (int i = 0; i <= n; i++)
		dp[0][i] = -INF;
	dp[0][0] = 0;
	for (int it = 0; it < k; it++) {
		for (int i = 0; i <= n; i++)
			dp[1][i] = -INF;
		solve(it + 1, n + 1, 0, n);
		for (int i = 0; i <= n; i++)
			dp[0][i] = dp[1][i];
	}
	printf("%d\n", dp[0][n]);

	return 0;
}