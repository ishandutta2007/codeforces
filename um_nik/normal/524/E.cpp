#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define mp make_pair

const int INF = (int)1e9;
const int pow2 = (1 << 18);
const int N = (int)4e5 + 100;

struct SegmentTree
{
	int tree[pow2 * 2];
	SegmentTree ()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = -INF;
	}
	void reset()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = -INF;
	}
	void setVal(int pos, int val, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l == r)
		{
			tree[v] = val;
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m)
			setVal(pos, val, 2 * v, l, m);
		else
			setVal(pos, val, 2 * v + 1, m + 1, r);
		tree[v] = min(tree[2 * v], tree[2 * v + 1]);
	}
	int getMin(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return INF;
		int m = (l + r) / 2;
		return min(getMin(a, b, 2 * v, l, m), getMin(a, b, 2 * v + 1, m + 1, r));
	}
} tree;

struct Roof
{
	int x, y;
	Roof () {}
	void scan()
	{
		scanf("%d%d", &x, &y);
	}
} roofs[N];

struct Query
{
	int type;
	int x1, x2;
	int l, r;
	int id;
	Query () {}
	Query (int _type, int _x1, int _x2, int _l, int _r, int _id) : type(_type), x1(_x1), x2(_x2), l(_l), r(_r), id(_id) {}
};

bool cmp(const Query &a, const Query &b)
{
	if (a.x1 != b.x1)
		return a.x1 < b.x1;
	return a.type > b.type;
}

struct Area
{
	int x1, y1, x2, y2;
	Area () {}
	void scan()
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	}
};

Area areas[N];
Query listQ[N];
bool answer[N];
int indQ = 0;

void solve()
{
	tree.reset();
	sort(listQ, listQ + indQ, cmp);
	for (int i = 0; i < indQ; i++)
	{
		if (listQ[i].type == 0)
			tree.setVal(listQ[i].l, listQ[i].x1);
		else
		{
			int l = listQ[i].l;
			int r = listQ[i].r;
			int minVal = tree.getMin(l, r);
			if (minVal >= listQ[i].x2)
				answer[listQ[i].id] |= true;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m, k, q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < k; i++)
		roofs[i].scan();
	for (int i = 0; i < q; i++)
		areas[i].scan();

	indQ = 0;
	for (int i = 0; i < k; i++)
		listQ[indQ++] = Query(0, roofs[i].x, roofs[i].x, roofs[i].y, roofs[i].y, -1);
	for (int i = 0; i < q; i++)
		listQ[indQ++] = Query(-1, areas[i].x2, areas[i].x1, areas[i].y1, areas[i].y2, i);
	
	solve();

	indQ = 0;
	for (int i = 0; i < k; i++)
		listQ[indQ++] = Query(0, roofs[i].y, roofs[i].y, roofs[i].x, roofs[i].x, -1);
	for (int i = 0; i < q; i++)
		listQ[indQ++] = Query(-1, areas[i].y2, areas[i].y1, areas[i].x1, areas[i].x2, i);

	solve();

	for (int i = 0; i < q; i++)
		printf("%s\n", answer[i] ? "YES" : "NO");
	return 0;
}