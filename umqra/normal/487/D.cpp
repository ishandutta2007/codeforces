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
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 10;
const int M = 14;
const int pow2 = (1 << 17);

int nSize, mSize;
char table[N][M];
int mainPos[M];

void recalcLevel(pii *arr, int l)
{
	int cntPos = 0;
	mainPos[cntPos++] = -1;
	for (int s = 0; s < mSize; s++)
		arr[s] = mp(-2, -2);
	for (int s = 0; s < mSize; s++)
	{
		if (table[l][s] == '^')
		{
			mainPos[cntPos++] = s;
			arr[s] = mp(l - 1, s);
		}
	}
	mainPos[cntPos++] = mSize;
	for (int s = 0; s < cntPos; s++)
	{
		int p = mainPos[s];
		int delta = 1;
		while (p - delta >= 0 && table[l][p - delta] == '>')
		{
			arr[p - delta] = mp(l - (p != mSize ? 1 : 0), p);
			delta++;
		}
		delta = 1;
		while (p + delta < mSize && table[l][p + delta] == '<')
		{
			arr[p + delta] = mp(l - (p != -1 ? 1 : 0), p);
			delta++;
		}
	}
}

void mergeTree(pii *to, pii *a, pii *b, int coord)
{
	for (int i = 0; i < mSize; i++)
	{
		pii pos = b[i];
		to[i] = pos;
		if (pos.X != coord)
			continue;
		to[i] = a[pos.Y];
	}
}

struct SegmentTree
{
	pii tree[pow2 * 2][M];
	void build(int v, int l, int r)
	{
		if (l == r)
		{
			for (int s = 0; s < mSize; s++)
				tree[v][s] = mp(-2, -2);
			if (l >= nSize)
				return;
			recalcLevel(tree[v], l);
			return;
		}
		int m = (l + r) / 2;
		build(2 * v, l, m);
		build(2 * v + 1, m + 1, r);
		mergeTree(tree[v], tree[2 * v], tree[2 * v + 1], m);
	}
	pii getValue(int x, int y, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (r == x)
			return tree[v][y];
		int m = (l + r) / 2;
		if (x > m)
		{
			pii pos = getValue(x, y, 2 * v + 1, m + 1, r);
			if (pos.X != m)
				return pos;
			return tree[2 * v][pos.Y];
		}
		else
			return getValue(x, y, 2 * v, l, m);
	}
	void changeValue(int x, int y, char c, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l == r)
		{
			table[x][y] = c;
			recalcLevel(tree[v], l);
			return;
		}
		int m = (l + r) / 2;
		if (x <= m)
			changeValue(x, y, c, 2 * v, l, m);
		else
			changeValue(x, y, c, 2 * v + 1, m + 1, r);
		mergeTree(tree[v], tree[2 * v], tree[2 * v + 1], m);
	}
} tree;

int main()
{
	int q;
	scanf("%d%d%d", &nSize, &mSize, &q);
	for (int i = 0; i < nSize; i++)
		scanf(" %s", table[i]);

	tree.build(1, 0, pow2 - 1);
	for (int i = 0; i < q; i++)
	{
		char type;
		scanf(" %c", &type);
		if (type == 'A')
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--, y--;
			pii pos = tree.getValue(x, y);
			printf("%d %d\n", pos.X + 1, pos.Y + 1);
		}
		else
		{
			int x, y;
			char c;
			scanf("%d%d %c", &x, &y, &c);
			x--, y--;
			tree.changeValue(x, y, c);
		}
	}

	return 0;
}