#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e18;

struct Node
{
	int l, r;
	ll sum, maxAns, maxLeft, maxRight;

	Node () : l(), r(), sum(), maxAns(), maxLeft(), maxRight() {}
	Node (int _l, int _r, ll h, ll d)
	{
		l = _l;
		r = _r;
		sum = d;
		maxAns = -INF;
		maxLeft = 2 * h;
		maxRight = 2 * h + d;
	}
};

const int N = 1 << 18;
Node tree[2 * N];
ll a[N][2];
int n, q;

void read()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i][1]);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i][0]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			a[n + i][j] = a[i][j];
	return;
}

Node merge(Node L, Node R)
{
	Node res;
	if (R.sum == -INF)
	{
		res = L;
		res.r = R.r;
		return res;
	}
	if (L.sum == -INF)
	{
		res = R;
		res.l = L.l;
		return res;
	}
	res = Node(L.l, R.r, 0, 0);
	res.sum = L.sum + R.sum;
	res.maxAns = max(L.maxAns, R.maxAns);
	res.maxAns = max(res.maxAns, L.maxRight + R.maxLeft);
	res.maxLeft = max(L.maxLeft, L.sum + R.maxLeft);
	res.maxRight = max(R.maxRight, R.sum + L.maxRight);
	return res;
}

void buildTree()
{
	for (int i = 0; i < N; i++)
	{
		if (i < 2 * n)
			tree[N + i] = Node(i, i + 1, a[i][0], a[i][1]);
		else
			tree[N + i] = Node(i, i + 1, -INF, -INF);
	}
	for (int i = N - 1; i > 0; i--)
		tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
	return;
}

void init()
{
	read();
	buildTree();
	return;
}

Node getMax(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v];
	int mid = (tree[v].l + tree[v].r) / 2;
	if (r <= mid)
		return getMax(2 * v, l, r);
	if (l >= mid)
		return getMax(2 * v + 1, l, r);
	return merge(getMax(2 * v, l, r), getMax(2 * v + 1, l, r));
}

void query()
{
	int l, r;
	scanf("%d%d", &l, &r);
	l--;r--;
	if (l <= r)
	{
		swap(l, r);
		l++;
		r += n;
	}
	else
	{
		swap(l, r);
		l++;
	}
	printf("%I64d\n", (getMax(1, l, r).maxAns));
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	while(q--)
		query();

	return 0;
}