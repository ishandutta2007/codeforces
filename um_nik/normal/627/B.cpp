#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 1 << 18;
struct Node
{
	int l, r;
	int val;

	Node() : l(), r(), val(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(0) {}
};
Node t1[2 * N], t2[2 * N];
int n, k, q;
int a, b;

void build()
{
	for (int i = 0; i < N; i++)
		t1[N + i] = t2[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		t1[i] = t2[i] = Node(t1[2 * i].l, t1[2 * i + 1].r);
	return;
}
void add(int v, int d)
{
	v += N;
	t1[v].val = min(b, t1[v].val + d);
	t2[v].val = min(a, t2[v].val + d);
	v >>= 1;
	while(v > 0)
	{
		t1[v].val = t1[2 * v].val + t1[2 * v + 1].val;
		t2[v].val = t2[2 * v].val + t2[2 * v + 1].val;
		v >>= 1;
	}
	return;
}
int get1(int v, int l, int r)
{
	if (l <= t1[v].l && t1[v].r <= r)
		return t1[v].val;
	if (l >= t1[v].r || t1[v].l >= r)
		return 0;
	return get1(2 * v, l, r) + get1(2 * v + 1, l, r);
}
int get2(int v, int l, int r)
{
	if (l <= t2[v].l && t2[v].r <= r)
		return t2[v].val;
	if (l >= t2[v].r || t2[v].l >= r)
		return 0;
	return get2(2 * v, l, r) + get2(2 * v + 1, l, r);
}

void query()
{
	int t;
	scanf("%d", &t);
	if (t == 1)
	{
		int v, d;
		scanf("%d%d", &v, &d);
		add(v, d);
	}
	else
	{
		int p;
		scanf("%d", &p);
		printf("%d\n", get1(1, 0, p) + get2(1, p + k, n + 1));
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	build();
	while(q--)
		query();

	return 0;
}