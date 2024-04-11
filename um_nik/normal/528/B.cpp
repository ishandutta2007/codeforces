#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200200;
int n;
pii a[N];
map<int, int> b;
int c[2 * N];
int sz;
int ans = 0;

const int L = 1 << 19;
struct Node
{
	int l, r;
	int val;

	Node () : l(), r(), val() {}
	Node (int _l, int _r, int _val) : l(_l), r(_r), val(_val) {}
};
Node tree[2 * L];

void buildTree()
{
	for (int i = 0; i < L; i++)
		tree[L + i] = Node(i, i + 1, 0);
	for (int i = L - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r, 0);
	return;
}

void setVal(int v, int w)
{
	v += L;
	tree[v].val = w;
	v /= 2;
	while(v > 0)
	{
		tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
		v /= 2;
	}
	return;
}

int getMax(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	return max(getMax(2 * v, l, r), getMax(2 * v + 1, l, r));
}

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = mp(x, y);
		c[sz++] = x + y;
		c[sz++] = x - y;
	}
	sort(c, c + sz);
	sz = unique(c, c + sz) - c;
	for (int i = 0; i < sz; i++)
		b[c[i]] = i;
	sort(a, a + n);
	return;
}

void query(int x, int w)
{
	int y = b[x - w];
	int res = getMax(1, 0, y + 1) + 1;
	ans = max(ans, res);
	y = b[x + w];
	setVal(y, res);
	return;
}

void solve()
{
	buildTree();
	for (int i = 0; i < n; i++)
		query(a[i].first, a[i].second);
	printf("%d\n", ans);
	return;
}

int main()
{
	read();
	solve();

	return 0;
}