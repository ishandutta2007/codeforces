#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int LOG = 17;
const int N = 100100;
int a[N];
pii sparse[LOG + 1][N];
int n;

void getTL()
{
	int x = 0;
	while(true)
	{
		x++;
	}
	printf("%d\n", x);
}

struct Node
{
	int l, r;
	ll val;
	bool pushOne;
	int add;

	Node () : l(-1), r(-1), val(), pushOne(), add() {}
	Node(int _l, int _r) : l(_l), r(_r), val(0), pushOne(false), add(0) {}
};
const int SZ = 6 * LOG * N;
Node tree[SZ];
int m = 0;
ll ans;
int p[N];
int roots[N];

pii getSparse(int l, int r)
{
	int k = p[r - l];
	return max(sparse[k][l], sparse[k][r - (1 << k)]);
}

void push(int v, int l, int r)
{
	if (v == -1) throw;
	int mid = (l + r) / 2;
	
	int u = tree[v].l;
	if (u == -1) throw;
	int w = m++;
	if (m == SZ)
		getTL();
	tree[w] = tree[u];
	if (tree[v].pushOne)
	{
		tree[w].pushOne = 1;
		tree[w].add = 0;
		tree[w].val = mid - l;
	}
	tree[w].add += tree[v].add;
	tree[w].val += tree[v].add * (mid - l);
	tree[v].l = w;

	u = tree[v].r;
	if (u == -1) throw;
	w = m++;
	if (m == SZ)
		getTL();
	tree[w] = tree[u];
	if (tree[v].pushOne)
	{
		tree[w].pushOne = 1;
		tree[w].add = 0;
		tree[w].val = r - mid;
	}
	tree[w].add += tree[v].add;
	tree[w].val += tree[v].add * (r - mid);
	tree[v].r = w;

	tree[v].pushOne = 0;
	tree[v].add = 0;

	return;
}

int update(int v)
{
	if (v == -1 || tree[v].l == -1 || tree[v].r == -1) throw;
//	int u = m++;
	int u = v;
	tree[u] = tree[v];
	tree[u].val = tree[tree[u].l].val + tree[tree[u].r].val;
	return u;
}

int buildTree(int l, int r)
{
	if (l + 1 == r)
	{
		tree[m] = Node();
		if (m + 1 == SZ)
			getTL();
		return m++;
	}
	int mid = (l + r) / 2;
	int v = m++;
	if (m == SZ)
		getTL();
	tree[v] = Node(buildTree(l, mid), buildTree(mid, r));
	return v;
}

int addSegm(int v, int l, int r, int a, int b, ll d)
{
	if (a <= l && r <= b)
	{
		int u = m++;
		if (m == SZ)
			getTL();
		tree[u] = tree[v];
		tree[u].add += d;
		tree[u].val += d * (r - l);
		return u;
	}
	if (b <= l || r <= a) return v;
	push(v, l, r);
	int u = m++;
	if (m == SZ)
		getTL();
	tree[u] = tree[v];
	int mid = (l + r) / 2;
	tree[u].l = addSegm(tree[u].l, l, mid, a, b, d);
	tree[u].r = addSegm(tree[u].r, mid, r, a, b, d);
	return update(u);
}

int colorOne(int v, int l, int r, int a, int b)
{
	if (a <= l && r <= b)
	{
		int u = m++;
		if (m == SZ)
			getTL();
		tree[u] = tree[v];
		tree[u].add = 0;
		tree[u].pushOne = 1;
		tree[u].val = (r - l);
		return u;
	}
	if (r <= a || b <= l) return v;
	push(v, l, r);
	int u = m++;
	if (m == SZ)
		getTL();
	tree[u] = tree[v];
	int mid = (l + r) / 2;
	tree[u].l = colorOne(tree[u].l, l, mid, a, b);
	tree[u].r = colorOne(tree[u].r, mid, r, a, b);
	return update(u);
}

ll getSum(int v, int l, int r, int a, int b)
{
	if (a <= l && r <= b) return tree[v].val;
	if (b <= l || r <= a) return 0;
	push(v, l, r);
	int mid = (l + r) / 2;
	return getSum(tree[v].l, l, mid, a, b) + getSum(tree[v].r, mid, r, a, b);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	a[n - 1] = n;
	for (int i = 0; i < n; i++)
		sparse[0][i] = mp(a[i], i);
	for (int k = 1; k < LOG; k++)
		for (int i = 0; i + (1 << k) <= n; i++)
			sparse[k][i] = max(sparse[k - 1][i], sparse[k - 1][i + (1 << (k - 1))]);
	for (int i = 2; i < N; i++)
		p[i] = p[i / 2] + 1;

	roots[n - 1] = buildTree(0, n);
	for (int i = n - 2; i >= 0; i--)
	{
		int x = getSparse(i + 1, a[i] + 1).second;
		roots[i] = colorOne(addSegm(roots[x], 0, n, 0, n, 1), 0, n, 0, a[i] + 1);
		ans += getSum(roots[i], 0, n, i + 1, n);
	}
	printf("%lld\n", ans);

	return 0;
}