#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

const int Q = (int)1e5 + 10;
const int permDir[] = {0, 1, 3, 2};
#ifdef LOCAL
const int N = 200;
const int SZ = N + 10;
const int pow2 = (1 << 8);
#else
const int N = 5010;
const int SZ = N + 10;
const int pow2 = (1 << 13);
#endif



struct Fenwick
{
	int f[SZ];
	Fenwick ()
	{
		memset(f, 0, sizeof(f));
	}
	void addVal(int pos, int val)
	{
		for (int i = pos; i < SZ; i |= (i + 1))
			f[i] += val;
	}
	int getSum(int pos)
	{
		int sum = 0;
		for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
			sum += f[i];
		return sum;
	}
	int getSum(int a, int b)
	{
		return getSum(b) - getSum(a - 1);
	}
};

const int ROW = 0;
const int DIAG = 1;
struct SegmentTree
{
	int type;
	Fenwick f[2 * pow2];
	SegmentTree ()
	{
		memset(f, 0, sizeof(f));
	}
	void setType(int t)
	{
		memset(f, 0, sizeof(f));
		type = t;
	}
	void addFullStrip(int x1, int x2, int y, int v, int l, int r)
	{
		int len = x2 - x1;
		int topY = y + len - (l - x1);
		if (type == ROW)
		{
			//eprintf("Add row : (%d %d) : y = %d\n", l, r, y);
			f[v].addVal(y, 1);
		}
		else
		{
			//eprintf("Add diag : (%d %d) : y = %d\n", l, r, topY + 1);
			f[v].addVal(topY + 1, -1);
			//eprintf("Res : %d\n", f[v].getSum(topY + 1));
		}
	}
	/*
	.
	..
	...
	....
	*/
	void addTriangle(int x1, int x2, int y, int v, int l, int r)
	{
		if (l >= x1 && r <= x2)
		{
			addFullStrip(x1, x2, y, v, l, r);
			return;
		}
		if (l > x2 || r < x1)
			return;
		int m = (l + r) / 2;
		addTriangle(x1, x2, y, 2 * v, l, m);
		addTriangle(x1, x2, y, 2 * v + 1, m + 1, r);
	}
	void addTriangle(int x1, int x2, int y)
	{
		addTriangle(x1, x2, y, 1, 0, pow2 - 1);
	}
	int getCntFullStrip(int x, int y, int v, int l, int r)
	{
		int projY = min(y + (x - l), N);
		int val;
		if (type == ROW)
			val = f[v].getSum(y);
		else
			val = f[v].getSum(projY);

		//eprintf("type : %s, x : %d, y : %d, [%d..%d], pr = %d, val = %d\n", type == ROW ? "ROW" : "DIAG", x, y, l, r, projY, val);
		return val;
	}
	int getCnt(int x, int y, int v, int l, int r)
	{
		int cnt = getCntFullStrip(x, y, v, l, r);
		if (l == r)
			return cnt;
		int m = (l + r) / 2;
		if (x <= m)
			return cnt + getCnt(x, y, 2 * v, l, m);
		return cnt + getCnt(x, y, 2 * v + 1, m + 1, r);
	}
	int getCnt(int x, int y)
	{
		return getCnt(x, y, 1, 0, pow2 - 1);
	}
};
SegmentTree tree;

struct Query
{
	int type;
	int dir;
	int x, y;
	int len;
	int ans;
	Query () : type(), dir(), x(), y(), len (), ans() {}
	void scan()
	{
		ans = 0;
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d%d%d", &dir, &x, &y, &len);
			dir--;
			dir = permDir[dir];
		}
		else
			scanf("%d%d", &x, &y);
	}
	void apply()
	{
		if (type == 1)
		{
			//eprintf("x len y : %d %d %d\n", x, len, y);
			tree.addTriangle(x, x + len, y);
		}
		else
		{
			//eprintf("x y : %d %d\n", x, y);
			ans += tree.getCnt(x, y);
		}
	}
};

Query query[Q];

void rotate(int &x, int &y)
{
	int nx = N - y;
	int ny = x;
	x = nx;
	y = ny;
}

int q;
void processQuery(int d)
{
	//eprintf("d = %d\n", d);
	tree.setType(ROW);
	for (int i = 0; i < q; i++)
	{
		//eprintf("(%d %d)\n", query[i].x, query[i].y);
		if (query[i].dir == d || query[i].type == 2)
		{
			query[i].apply();
		}
	}
	tree.setType(DIAG);
	for (int i = 0; i < q; i++)
	{
		if (query[i].dir == d || query[i].type == 2)
			query[i].apply();
		if (query[i].type == 2);
			//eprintf("Ans = %d\n", query[i].ans);
		rotate(query[i].x, query[i].y);
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++)
		query[i].scan();
	for (int i = 0; i < 4; i++)
	{
		processQuery(i);
	}
	for (int i = 0; i < q; i++)
	{
		if (query[i].type == 2)
			printf("%d\n", query[i].ans);
	}

	return 0;
}