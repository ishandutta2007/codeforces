#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

int ans;
int k;
int n;
const int N = (int)6e4;
ll x[N][2], y[N][2];

struct Event
{
	ll x, y1, y2;
	bool type;

	Event () : x(), y1(), y2(), type() {}
	Event (ll _x, ll _y1, ll _y2, bool _type) : x(_x), y1(_y1), y2(_y2), type(_type) {}

	bool operator < (const Event &a) const
	{
		return x < a.x;
	}
};
Event ev[3 * N];
int ev_sz;
ll ys[3 * N];
int m;

struct Node
{
	int l, r;
	int min;
	int cnt_min;
	int add;

	Node () : l(0), r(0), min(0), cnt_min(0), add(0) {}
	Node (int l, int r, int min, int cnt_min, int add) : l(l), r(r), min(min), cnt_min(cnt_min), add(add) {}
};
const int MOD = 1 << 17;
Node tree[2 * MOD];

void update(int v)
{
	if (v >= MOD) throw;
	tree[v].min = min(tree[2 * v].min, tree[2 * v + 1].min);
	tree[v].cnt_min = 0;
	for (int i = 0; i < 2; i++)
		if (tree[v].min == tree[2 * v + i].min)
			tree[v].cnt_min += tree[2 * v + i].cnt_min;
	return;
}

void push(int v)
{
	if (v >= MOD) throw;
	int val = tree[v].add;
	tree[v].add = 0;
	for (int i = 0; i < 2; i++)
	{
		tree[2 * v + i].add += val;
		tree[2 * v + i].min += val;
	}
	return;
}

void buildTree()
{
	for (int i = 0; i < MOD; i++)
	{
		if (i < m)
		{
			int dy = 0;
			if (i < m - 1)
				dy = (int)(ys[i + 1] - ys[i]);
			tree[i + MOD] = Node(i, i + 1, 0, dy, 0);
		}
		else
			tree[i + MOD] = Node(i, i + 1, 0, 0, 0);
	}
	for (int i = MOD - 1; i > 0; i--)
	{
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r, 0, 0, 0);
		update(i);
	}
	return;
}

void addOnSegm(int v, int l, int r, int val)
{
	if (l >= tree[v].r || r <= tree[v].l) return;
	if (l <= tree[v].l && tree[v].r <= r)
	{
		tree[v].add += val;
		tree[v].min += val;
		return;
	}
	push(v);
	for (int i = 0; i < 2; i++)
		addOnSegm(2 * v + i, l, r, val);
	update(v);
	return;
}

int getSq()
{
	int res = (int)(ys[m - 1] - ys[0]);
	if (tree[1].min == 0)
		res -= tree[1].cnt_min;
	return res;
}

int getC(int x, int lvl)
{
	return ((x - 1) >> lvl) + 1;
}

ll solve(int lvl)
{
	ll res = 0LL;
	ev_sz = 0;
	m = 0;
	for (int i = 0; i < n; i++)
	{
		ev[ev_sz++] = Event(getC(x[i][0], lvl), getC(y[i][0], lvl), getC(y[i][1], lvl), true);
		ev[ev_sz++] = Event(getC(x[i][1], lvl), getC(y[i][0], lvl), getC(y[i][1], lvl), false);
		ys[m++] = getC(y[i][0], lvl);
		ys[m++] = getC(y[i][1], lvl);
	}
	sort(ys, ys + m);
	m = unique(ys, ys + m) - ys;
	buildTree();
	sort(ev, ev + ev_sz);
	for (int i = 0; i < ev_sz; i++)
	{
		int yl = lower_bound(ys, ys + m, ev[i].y1) - ys;
		int yr = lower_bound(ys, ys + m, ev[i].y2) - ys;
		ll dx = ev[i].x - ev[i - 1].x;
		if (i != 0)
			res += dx * getSq();
		addOnSegm(1, yl, yr, ev[i].type ? 1 : -1);
	}
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &n, &k);
	int tmp = 0;
	while ((1 << tmp) <= k) tmp++;
	k = tmp;
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d%I64d%I64d%I64d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
		x[i][1]++;
		y[i][1]++;
	}
	for (int i = 0; i < k; i++)
		if (solve(i) & 1LL)
		{
			printf("Hamed\n");
			return 0;
		}
	printf("Malek\n");

	return 0;
}