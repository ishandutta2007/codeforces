#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
#include <cassert>
#include <complex>
#include <valarray>
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

const int C = (int)2e9 + 10;

struct Node
{
	Node *l, *r;
	int sum;
	Node () : l(NULL), r(NULL), sum(0) {}
	Node (int s) : l(), r(), sum(s) {}
	Node (Node *_l, Node *_r)
	{
		l = _l;
		r = _r;
		sum = (l == NULL ? 0 : l -> sum) + (r == NULL ? 0 : r -> sum);
	}
};

Node * relax(Node *v)
{
	v -> sum = (v -> l == NULL ? 0 : v -> l -> sum) + (v -> r == NULL ? 0 : v -> r -> sum);
	return v;
}

Node* addVal(int pos, int val, Node *v, int l, int r)
{
	if (v == NULL)
		v = new Node(0);
	if (l == r)
	{
		v -> sum += val;
		return v;
	}
	int m = (l + r) / 2;
	if (pos <= m)
	{
		Node* t = addVal(pos, val, v -> l, l, m);
		v -> l = t;
		return relax(v);
	}
	else
	{
		Node* t = addVal(pos, val, v -> r, m + 1, r);
		v -> r = t;
		return relax(v);
	}
}

int getSum(int a, int b, Node *v, int l, int r)
{
	if (v == NULL)
		return 0;
	if (l >= a && r <= b)
		return v -> sum;
	if (l > b || r < a)
		return 0;
	int m = (l + r) / 2;
	return getSum(a, b, v -> l, l, m) + getSum(a, b, v -> r, m + 1, r);
}

const int pow2 = (1 << 20);

struct SegmentTree
{
	int tree[pow2 * 2];
	SegmentTree ()
	{
		memset(tree, 0, sizeof(tree));
	}
	void addVal(int pos, int val)
	{
		int v = pos + pow2;
		tree[v] += val;
		while (v > 1)
		{
			v /= 2;
			tree[v] = tree[2 * v] + tree[2 * v + 1];
		}
	}
	int getSum(int a, int b, int v, int l, int r)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 0;
		int m = (l + r) / 2;
		return getSum(a, b, 2 * v, l, m) + getSum(a, b, 2 * v + 1, m + 1, r);
	}
	int getSum(int a, int b)
	{
		return getSum(a, b, 1, 0, pow2 - 1);
	}
};
SegmentTree tree;

int allY[pow2];
int cntY = 0;

map <int, vector<pii>> hor, ver;

void join(map<int, vector<pii>> &forJ)
{
	for (auto &e : forJ)
	{
		vector <pii> &v = e.Y;
		sort(v.begin(), v.end());
		vector <pii> joined = {};
		int st = v[0].X;
		int en = v[0].Y;
		for (int i = 1; i < (int)v.size(); i++)
		{
			if (v[i].X <= en + 1)
				en = max(en, v[i].Y);
			else
			{
				joined.push_back(mp(st, en));
				st = v[i].X;
				en = v[i].Y;
			}
		}
		joined.push_back(mp(st, en));
		e.Y = joined;
	}
}

const int OPEN_HOR = -1;
const int VER = 0;
const int CLOSE_HOR = 1;


struct Event
{
	int type;
	int x;
	int l, r;
	Event () : type(), x(), l(), r() {}
	Event (int _t, int _x, int _l, int _r) : type(_t), x(_x), l(_l), r(_r) {}
	bool operator < (const Event &a) const
	{
		if (x != a.x)
			return x < a.x;
		return type < a.type;
	}
};

const int E = (int)3e5 + 10;
Event events[E];
int cntE = 0;

void addEvents()
{
	for (auto &e : hor)
	{
		for (pii x : e.Y)
		{
			events[cntE++] = Event(OPEN_HOR, x.X, e.X, e.X);
			events[cntE++] = Event(CLOSE_HOR, x.Y, e.X, e.X);
		}
	}
	for (auto &e : ver)
	{
		for (pii x : e.Y)
		{
			events[cntE++] = Event(VER, e.X, x.X, x.Y);
		}
	}
}

Node* root = new Node(0);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		allY[cntY++] = y1;
		allY[cntY++] = y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		if (x1 == x2)
			ver[x1].push_back(mp(y1, y2));
		else
			hor[y1].push_back(mp(x1, x2));
	}
	sort(allY, allY + cntY);
	cntY = unique(allY, allY + cntY) - allY;

	join(hor);
	join(ver);
	addEvents();
	sort(events, events + cntE);
	ll ans = 0;
	for (int i = 0; i < cntE; i++)
	{
		eprintf("Event: type - %d, x - %d, l - %d, r - %d\n", events[i].type, events[i].x, events[i].l, events[i].r);
		if (events[i].type == OPEN_HOR)
		{
			tree.addVal(lower_bound(allY, allY + cntY, events[i].l) - allY, 1);
//			root = addVal(events[i].l, 1, root, 0, C);
			ans -= events[i].x - 1;
		}
		else if (events[i].type == CLOSE_HOR)
		{
			tree.addVal(lower_bound(allY, allY + cntY, events[i].l) - allY, -1);
//			root = addVal(events[i].l, -1, root, 0, C);
			ans += events[i].x;
		}
		else
		{
//			ans += (events[i].r - events[i].l + 1) - getSum(events[i].l, events[i].r, root, 0, C);
			ans += (events[i].r - events[i].l + 1) - tree.getSum(lower_bound(allY, allY + cntY, events[i].l) - allY, lower_bound(allY, allY + cntY, events[i].r) - allY);
			eprintf("Sum: %d\n", getSum(events[i].l, events[i].r, root, 0, C));
		}
	}
	printf("%lld\n", ans);
	return 0;
}