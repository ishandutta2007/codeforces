#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1 << 17;

typedef long long ll;

struct Node
{
	int l, r;
	ll val;

	Node() : l(), r(), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val(0) {}
};
Node tree[2 * N];

int n;
ll a[N];
ll xs[N];

ll getMax(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	return max(getMax(2 * v, l, r), getMax(2 * v + 1, l, r));
}
void update(int v, ll w)
{
	v += N;
	tree[v].val = w;
	v >>= 1;
	while(v)
	{
		tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
		v >>= 1;
	}
	return;
}

void buildTree()
{
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		a[i] = x * x * y;
		xs[i] = a[i];
	}
	sort(xs, xs + n);
	int m = unique(xs, xs + n) - xs;
	ll ans = 0;
	buildTree();
	for (int i = 0; i < n; i++)
	{
		int r = lower_bound(xs, xs + m, a[i]) - xs;
		ll x = getMax(1, 0, r);
		x += a[i];
		ans = max(ans, x);
		update(r, x);
	}
//	printf("%lld\n", ans);
	printf("%.13lf\n", 4 * atan(1.) * ans);

	return 0;
}