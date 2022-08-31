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

const int pow2 = (1 << 20);
const int S = (int)4e5 + 100;
const int C = (int)1e6 + 100;


int listCoords[C];
int indC = 0;

struct Segment
{
	int id;
	int l, r;
	int cost;
	Segment() {}
	Segment (int _l, int _r, int _cost) : l(_l), r(_r), cost(_cost) {}
	void scan(int type, int _id)
	{
		id = _id;
		if (type == 0)
		{
			scanf("%d%d", &l, &r);
			cost = -1;
		}
		else
		{
			scanf("%d%d%d", &l, &r, &cost);
		}
		listCoords[indC++] = l;
		listCoords[indC++] = r;
	}
};

Segment seg[S];
pii answer[S];
int cost[S];

struct SegmentTree
{
	pii tree[pow2 * 2];
	SegmentTree ()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = mp(0, 0);
	}
	void relaxValue(int pos, pii value, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l == r)
		{
			tree[v] = max(tree[v], value);
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m)
			relaxValue(pos, value, 2 * v, l, m);
		else
			relaxValue(pos, value, 2 * v + 1, m + 1, r);
		tree[v] = max(tree[2 * v], tree[2 * v + 1]);
	}
	pii getMax(int a, int b, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return mp(0, 0);
		int m = (l + r) / 2;
		return max(getMax(a, b, 2 * v, l, m), getMax(a, b, 2 * v + 1, m + 1, r));
	}
} tree;

bool cmpFull(const Segment &a, const Segment &b)
{
	if (a.r != b.r)
		return a.r < b.r;
	return a.cost < b.cost;
}

int getCoord(int x)
{
	return lower_bound(listCoords, listCoords + indC, x) - listCoords;
}

void relaxAnswer(int id, pii cur)
{
	answer[id] = max(answer[id], cur);
}

void findFullSegments(int q)
{
	sort(seg, seg + q, cmpFull);
	for (int i = 0; i < q; i++)
	{
		int a = getCoord(seg[i].l);
		int b = getCoord(seg[i].r);
		if (seg[i].cost < 0)
		{
			tree.relaxValue(a, mp(seg[i].r - seg[i].l, seg[i].id));
		}
		else
		{
			pii best = tree.getMax(a, b);
			relaxAnswer(seg[i].id, best);
		}
	}
}

bool cmpLeft(const Segment &a, const Segment &b)
{
	if (a.l != b.l)
		return a.l < b.l;
	return a.cost < b.cost;
}

void findLeftSegments(int q)
{
	sort(seg, seg + q, cmpLeft);
	int maxR = 0;
	int maxId = -1;
	for (int i = 0; i < q; i++)
	{
		if (seg[i].cost < 0)
		{
			if (maxR < seg[i].r)
			{
				maxR = seg[i].r;
				maxId = seg[i].id;
			}
		}
		else
		{
			int curLen = min(maxR, seg[i].r) - seg[i].l;
			relaxAnswer(seg[i].id, mp(curLen, maxId));
		}
	}
}

bool cmpRight(const Segment &a, const Segment &b)
{
	if (a.r != b.r)
		return a.r > b.r;
	return a.cost < b.cost;
}

void findRightSegments(int q)
{
	sort(seg, seg + q, cmpRight);
	int minL = (int)1e9 + 100;
	int minId = -1;
	for (int i = 0; i < q; i++)
	{
		if (seg[i].cost < 0)
		{
			if (minL > seg[i].l)
			{
				minL = seg[i].l;
				minId = seg[i].id;
			}
		}
		else
		{
			int curLen = seg[i].r - max(minL, seg[i].l);
			relaxAnswer(seg[i].id, mp(curLen, minId));
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		seg[i].scan(0, i);
	for (int s = 0; s < m; s++)
	{
		seg[n + s].scan(1, s);
		cost[s] = seg[n + s].cost;
	}

	sort(listCoords, listCoords + indC);
	indC = unique(listCoords, listCoords + indC) - listCoords;

	findFullSegments(n + m);
	findLeftSegments(n + m);
	findRightSegments(n + m);

	ll bestValue = 0;
	int bestIndex = -1;
	for (int i = 0; i < m; i++)
	{
		ll curValue = (ll)cost[i] * (ll)answer[i].first;
		if (curValue > bestValue)
		{
			bestValue = curValue;
			bestIndex = i;
		}
	}
	if (bestValue == 0)
	{
		cout << 0;
		return 0;
	}
	cout << bestValue << endl;
	cout << answer[bestIndex].second + 1 << " " << bestIndex + 1;

	return 0;
}