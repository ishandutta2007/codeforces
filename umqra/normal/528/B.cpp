#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int pow2 = (1 << 20);
const int N = (int)2e5 + 10;

struct Point
{
	int x, w;
	int id;
	Point () {}
	Point (int _x, int _w) : x(_x), w(_w) {}
	void scan(int i)
	{
		id = i;
		scanf("%d%d", &x, &w);
	}
} p[N], order[N];
int pos[N];

struct SegmentTree
{
	int tree[pow2 * 2];
	SegmentTree () 
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = 0;
	}
	void setVal(int position, int val, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l == r)
		{
			tree[v] = val;
			return;
		}
		int m = (l + r) / 2;
		if (position <= m)
			setVal(position, val, 2 * v, l, m);
		else
			setVal(position, val, 2 * v + 1, m + 1, r);
		tree[v] = max(tree[2 * v], tree[2 * v + 1]);
	}
	int getMax(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 0;
		int m = (l + r) / 2;
		return max(getMax(a, b, 2 * v, l, m), getMax(a, b, 2 * v + 1, m + 1, r));
	}
} tree;

bool cmpByX(const Point &a, const Point &b)
{
	return a.x < b.x;
}

bool cmpByMagic(const Point &a, const Point &b)
{
	return a.w + a.x < b.w + b.x;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i].scan(i);
		order[i] = p[i];
	}

	sort(p, p + n, cmpByX);
	sort(order, order + n, cmpByMagic);
	for (int i = 0; i < n; i++)
		pos[order[i].id] = i;

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		Point curPoint = Point(p[i].x - p[i].w, 0);
		int start = upper_bound(order, order + n, curPoint, cmpByMagic) - order - 1;
		int result = 0;
		if (start >= 0)
			result = tree.getMax(0, start);
		answer = max(answer, result + 1);
		tree.setVal(pos[p[i].id], result + 1);
	}
	cout << answer;

	return 0;
}