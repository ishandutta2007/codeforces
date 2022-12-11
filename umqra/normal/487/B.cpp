#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int pow2 = (1 << 18);
const int INF = (int)1e9;
const int LOG = 19;
const int N = (int)1e5 + 10;

struct SegmentTree
{
	int tree[pow2 * 2];
	void build()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = INF;
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
};

SegmentTree tree;

int n;
int sparseMin[LOG][N];
int sparseMax[LOG][N];
int a[N];
int h[N];

void calcSparse()
{
	for (int i = 0; i < LOG; i++)
		for (int s = 0; s <= n - (1 << i); s++)
		{
			if (i == 0)
				sparseMin[i][s] = sparseMax[i][s] = a[s];
			else
			{
				sparseMin[i][s] = min(sparseMin[i - 1][s], sparseMin[i - 1][s + (1 << (i - 1))]);
				sparseMax[i][s] = max(sparseMax[i - 1][s], sparseMax[i - 1][s + (1 << (i - 1))]);
			}
		}
}

void calcH()
{
	h[1] = 0;
	for (int i = 2; i < N; i++)
		h[i] = h[i / 2] + 1;
}

int getMin(int l, int r)
{
	int d = h[r - l + 1];
	return min(sparseMin[d][l], sparseMin[d][r - (1 << d) + 1]);
}

int getMax(int l, int r)
{
	int d = h[r - l + 1];
	return max(sparseMax[d][l], sparseMax[d][r - (1 << d) + 1]);
}

int main()
{
	int delta, len;
	scanf("%d%d%d", &n, &delta, &len);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	calcSparse();
	calcH();
	tree.build();

	for (int i = 0; i < n; i++)
	{
		int l = -1, r = i;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if (getMax(m, i) - getMin(m, i) <= delta)
				r = m;
			else
				l = m;
		}
		int x = i - len;
		if (r == 0 && i + 1 >= len)
		{
			tree.setVal(i, 1);
			continue;
		}
		r = max(0, r - 1);
		if (r <= x)
		{
			int t = tree.getMin(r, x);
			if (t != INF)
				tree.setVal(i, t + 1);
		}
	}

	int res = tree.getMin(n - 1, n - 1);
	if (res == INF)
		puts("-1");
	else
		cout << res;
	return 0;
}