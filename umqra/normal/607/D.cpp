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

const int mod = (int)1e9 + 7;
const int pow2 = (1 << 19);
const int N = (int)4e5 + 10;

int add(int a, int b)
{
	a += b;
	if (a < mod)
		return a;
	return a - mod;
}

int mult(int a, int b)
{
	return (1LL * a * b) % mod;
}

int myPow(int a, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return mult(a, myPow(a, k - 1));
	int t = myPow(a, k / 2);
	return mult(t, t);
}

int rev(int a)
{
	return myPow(a, mod - 2);
}

struct SegmentTree
{
	int tree[pow2 * 2];
	int d[pow2 * 2];
	SegmentTree ()
	{
		for (int i = 0; i < pow2 * 2; i++)
		{
			tree[i] = 0;
			d[i] = 1;
		}
	}
	void push(int v, int len)
	{
		if (d[v] == 1)
			return;
		tree[2 * v] = mult(tree[2 * v], d[v]);
		d[2 * v] = mult(d[2 * v], d[v]);

		tree[2 * v + 1] = mult(tree[2 * v + 1], d[v]);
		d[2 * v + 1] = mult(d[2 * v + 1], d[v]);

		d[v] = 1;
	}
	void relax(int v)
	{
		tree[v] = add(tree[2 * v], tree[2 * v + 1]);
	}
	void addVal(int pos, int val, int v, int l, int r)
	{
		if (l == r)
		{
			tree[v] = add(tree[v], val);
			return;
		}
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		if (pos <= m)
			addVal(pos, val, 2 * v, l, m);
		else
			addVal(pos, val, 2 * v + 1, m + 1, r);
		relax(v);
	}
	void addVal(int pos, int val)
	{
		addVal(pos, val, 1, 0, pow2 - 1);
	}
	void setVal(int pos, int val, int v, int l, int r)
	{
		if (l == r)
		{
			tree[v] = val;
			return;
		}
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		if (pos <= m)
			setVal(pos, val, 2 * v, l, m);
		else
			setVal(pos, val, 2 * v + 1, m + 1, r);
		relax(v);
	}
	void setVal(int pos, int val)
	{
		setVal(pos, val, 1, 0, pow2 - 1);
	}
	void multSeg(int a, int b, int val, int v, int l, int r)
	{
		if (l >= a && r <= b)
		{
			d[v] = mult(d[v], val);
			tree[v] = mult(tree[v], val);
			return;
		}
		if (l > b || r < a)
			return;
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		multSeg(a, b, val, 2 * v, l, m);
		multSeg(a, b, val, 2 * v + 1, m + 1, r);
		relax(v);
	}
	void multSeg(int a, int b, int val)
	{
		multSeg(a, b, val, 1, 0, pow2 - 1);
	}
	int getSum(int a, int b, int v, int l, int r)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 0;
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		return add(getSum(a, b, 2 * v, l, m), getSum(a, b, 2 * v + 1, m + 1, r));
	}
	int getSum(int a, int b)
	{
		return getSum(a, b, 1, 0, pow2 - 1);
	}
	void printPrefix(int len, int v, int l, int r)
	{
		if (l > len)
			return;
		if (l == r)
		{
			eprintf("%d ", tree[v]);
			return;
		}
		push(v, (r - l + 1) / 2);
		int m = (l + r) / 2;
		printPrefix(len, 2 * v, l, m);
		printPrefix(len, 2 * v + 1, m + 1, r);
	}
	void printPrefix(int len)
	{
		printPrefix(len, 1, 0, pow2 - 1);
		eprintf("\n");
	}
};

struct SegmentTreeProd
{
	int tree[pow2 * 2];
	SegmentTreeProd ()
	{
		for (int i = 0; i < pow2 * 2; i++)
			tree[i] = 1;
	}
	void relax(int v)
	{
		tree[v] = mult(tree[2 * v], tree[2 * v + 1]);
	}
	void addVal(int pos, int val, int v, int l, int r)
	{
		if (l == r)
		{
			tree[v] = add(tree[v], val);
			return;
		}
		int m = (l + r) / 2;
		if (pos <= m)
			addVal(pos, val, 2 * v, l, m);
		else
			addVal(pos, val, 2 * v + 1, m + 1, r);
		relax(v);
	}
	void addVal(int pos, int val)
	{
		addVal(pos, val, 1, 0, pow2 - 1);
	}
	void setVal(int pos, int val, int v, int l, int r)
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
		relax(v);
	}
	void setVal(int pos, int val)
	{
		setVal(pos, val, 1, 0, pow2 - 1);
	}
	int getProd(int a, int b, int v, int l, int r)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return 1;
		int m = (l + r) / 2;
		return mult(getProd(a, b, 2 * v, l, m), getProd(a, b, 2 * v + 1, m + 1, r));
	}
	int getProd(int a, int b)
	{
		return getProd(a, b, 1, 0, pow2 - 1);
	}
	void printPrefix(int len, int v, int l, int r)
	{
		if (l > len)
			return;
		if (l == r)
		{
			eprintf("%d ", tree[v]);
			return;
		}
		int m = (l + r) / 2;
		printPrefix(len, 2 * v, l, m);
		printPrefix(len, 2 * v + 1, m + 1, r);
	}
	void printPrefix(int len)
	{
		printPrefix(len, 1, 0, pow2 - 1);
		eprintf("\n");
	}
};

int type[N];
int qA[N], qB[N], qC[N];
int value[N];

vector <int> g[N];
int posIn[N], posOut[N];
int inStart[N], inEnd[N];
int onlyIn[N];
int tinE[N], toutE[N];
int degs[N];
int tme = 0;
int inTme = 0;
int q;

SegmentTreeProd treeIn, treeOut;
SegmentTree ans;

void dfs(int v)
{
	inStart[v] = inTme;
	onlyIn[inTme++] = v;

	posIn[v] = tme;
	tinE[tme++] = v;
	for (int to : g[v])
	{
		dfs(to);
	}
	posOut[v] = tme;
	toutE[tme++] = v;
	inEnd[v] = inTme - 1;
}

int getDegOnPath(int v)
{
	return mult(treeIn.getProd(0, posIn[v]), rev(treeOut.getProd(0, posIn[v])));
}

void changeDeg(int v, int d)
{
	degs[v] = d;
	treeIn.setVal(posIn[v], d);
	treeOut.setVal(posOut[v], d);
}

void connect(int p, int v)
{
	int c = mult(add(degs[p], 1), rev(degs[p]));
	ans.multSeg(inStart[p], inEnd[p], c);			
	changeDeg(v, degs[v] + 1);
	changeDeg(p, degs[p] + 1);

	ans.setVal(inStart[v], mult(value[v], getDegOnPath(v)));
}

int getValue(int v)
{
	int res = ans.getSum(inStart[v], inEnd[v]);
	res = mult(res, mult(rev(getDegOnPath(v)), degs[v]));
	return res;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	scanf("%d%d", &value[0], &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &type[i]);
		scanf("%d", &qA[i]);
		qA[i]--;
		if (type[i] == 1)
			scanf("%d", &qB[i]);
	}
	int id = 1;
	for (int i = 0; i < q; i++)
	{
		if (type[i] == 1)
		{
			g[qA[i]].push_back(id);
			value[id] = qB[i];
			qC[i] = id;
			id++;
		}
	}
	dfs(0);
	changeDeg(0, 1);
	ans.setVal(inStart[0], value[0]);
	for (int i = 0; i < q; i++)
	{
		if (type[i] == 1)
			connect(qA[i], qC[i]);
		else
			printf("%d\n", getValue(qA[i]));
	}

	return 0;
}