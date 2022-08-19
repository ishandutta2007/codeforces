#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int N = 1 << 19;
struct Node
{
	int l, r;
	int val;

	Node() : l(), r(), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val() {}
};
Node tree[2 * N];

void build()
{
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
	return;
}

void addVal(int v)
{
	v += N;
	tree[v].val++;
	while(v > 1)
	{
		v >>= 1;
		tree[v].val = tree[2 * v].val + tree[2 * v + 1].val;
	}
	return;
}

int getSum(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	return getSum(2 * v, l, r) + getSum(2 * v + 1, l, r);
}

int n;
pii a[N];
pii ev[N];
int m;
int xs[N];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = mp(x, y);
		xs[2 * i] = x;
		xs[2 * i + 1] = y;
	}
	sort(xs, xs + 2 * n);
	for (int i = 0; i < n; i++)
	{
		int x = a[i].first, y = a[i].second;
		x = lower_bound(xs, xs + 2 * n, x) - xs;
		y = lower_bound(xs, xs + 2 * n, y) - xs;
		a[i] = mp(x, y);
		ev[m++] = mp(x, -i - 1);
		ev[m++] = mp(y, i + 1);
	}
	sort(ev, ev + m);
	build();
	for (int i = 0; i < m; i++)
	{
		int id = ev[i].second;
		if (id < 0)
		{
			id *= -1;
			id--;
			ans[id] -= getSum(1, 0, a[id].second);
			addVal(a[id].second);
		}
		else
		{
			id--;
			ans[id] += getSum(1, 0, a[id].second);
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);

	return 0;
}