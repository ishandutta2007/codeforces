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

#pragma pack(1)
struct Inst
{
	unsigned short set;
	unsigned short add;
	Inst () : set(), add() {}
	Inst (int _set, int _add) : set(_set), add(_add) {}
};


#pragma pack(1)
struct Node
{
	int l, r;
	unsigned int sum;
	Inst inst;
	Node () : l(), r(), sum(), inst() {}
	Node (int _l, int _r) 
	{
		l = _l;
		r = _r;
		sum = 0;
		inst = Inst();
	}
};

const int SZ = (int)16e6;
Node tree[SZ];
int mv = 0;

int newNode()
{
	return mv++;
}

int newNode(int l, int r)
{
	int v = mv++;
	tree[v] = Node(l, r);
	tree[v].sum = tree[l].sum + tree[r].sum;
	return v;
}

int copyNode(int v)
{
	int nv = mv++;
	tree[nv] = tree[v];
	return nv;
}

int push(int v, int len)
{
	if ((tree[v].inst.set == 0 && tree[v].inst.add == 0) || len == 0)
		return copyNode(v);
	int l = copyNode(tree[v].l);
	int r = copyNode(tree[v].r);
	if (tree[v].inst.set > 0)
	{
		tree[l].inst = tree[r].inst = tree[v].inst;

		tree[l].sum = tree[v].inst.set * 1LL * len;
		tree[r].sum = tree[v].inst.set * 1LL * len;
	}
	if (tree[v].inst.add > 0)
	{
		tree[l].inst.add += tree[v].inst.add;
		tree[r].inst.add += tree[v].inst.add;

		tree[l].sum += tree[v].inst.add * 1LL * len;
		tree[r].sum += tree[v].inst.add * 1LL * len;
	}
	return newNode(l, r);
}

ll getSum(int a, int b, int v, int l, int r)
{
	if (l >= a && r <= b)
		return tree[v].sum;
	if (l > b || r < a)
		return 0;
	int m = (l + r) / 2;
	int interL = max(l, a);
	int interR = min(r, b);
	ll res = (interR - interL + 1) * 1LL * tree[v].inst.set + (interR - interL + 1) * 1LL * tree[v].inst.add;
	if (tree[v].inst.set == 0)
		res += getSum(a, b, tree[v].l, l, m) + getSum(a, b, tree[v].r, m + 1, r);
	return res;
}

int setVal(int a, int b, int val, int v, int l, int r)
{
	if (l >= a && r <= b)
	{
		int nv = copyNode(v);
		tree[nv].sum = val * 1LL * (r - l + 1);
		tree[nv].inst.set = val;
		tree[nv].inst.add = 0;
		return nv;
	}
	if (l > b || r < a)
		return v;
	v = push(v, (r - l + 1) / 2);
	int m = (l + r) / 2;
	int lv = setVal(a, b, val, tree[v].l, l, m);
	int rv = setVal(a, b, val, tree[v].r, m + 1, r);
	return newNode(lv, rv);
}

int addVal(int a, int b, int val, int v, int l, int r)
{
	if (l >= a && r <= b)
	{
//		eprintf("add for range: %d..%d\n", l, r);
//		eprintf("sum: %lld\n", tree[v].sum);
//		eprintf("inst: %d\n", tree[v].inst);
		int nv = copyNode(v);
		tree[nv].sum += (r - l + 1) * 1LL * val;
		tree[nv].inst.add = val;
//		eprintf("sum: %lld\n", tree[nv].sum);
		return nv;
	}
	if (l > b || r < a)
		return v;
	v = push(v, (r - l + 1) / 2);
	int m = (l + r) / 2;
	int lv = addVal(a, b, val, tree[v].l, l, m);
	int rv = addVal(a, b, val, tree[v].r, m + 1, r);
	return newNode(lv, rv);
}

int build(int l, int r)
{
	if (l == r)
		return newNode();
	int m = (l + r) / 2;
	return newNode(build(l, m), build(m + 1, r));
}

const int LOG = 17;
const int N = (int)1e5 + 10;
int posMax[LOG][N];
int h[N];
int to[N];
int root[N];

int getMax(int a, int b)
{
	int l = h[b - a + 1];
	int x = posMax[l][a];
	int y = posMax[l][b - (1 << l) + 1];
	if (to[x] > to[y])
		return x;
	return y;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif
	h[1] = 0;
	for (int i = 2; i < N; i++)
		h[i] = h[i / 2] + 1;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &to[i]);
		to[i]--;
	}
	for (int i = 0; i < LOG; i++)
	{
		for (int s = 0; s <= n - (1 << i); s++)
		{
			if (i == 0)
				posMax[i][s] = s;
			else
			{
				if (to[posMax[i - 1][s]] > to[posMax[i - 1][s + (1 << (i - 1))]])
					posMax[i][s] = posMax[i - 1][s];
				else
					posMax[i][s] = posMax[i - 1][s + (1 << (i - 1))];
			}
		}
	}
	root[n - 1] = build(0, n - 1);
	ll ans = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		int en = to[i];
		int mx = getMax(i, en);
		if (mx == i)
			mx = n - 1;
//		eprintf("mx: %d, en: %d\n", mx, en);
		root[i] = setVal(0, en, 1, root[mx], 0, n - 1);
//		for (int s = 0; s < n; s++)
//			eprintf("%lld ", getSum(s, s, root[4], 0, n - 1));
//		eprintf("\n");
//		for (int s = 0; s < n; s++)
//			eprintf("%lld ", getSum(s, s, root[i], 0, n - 1));
//		eprintf("\n");
		if (en + 1 <= n - 1)
			root[i] = addVal(en + 1, n - 1, 1, root[i], 0, n - 1);

//		eprintf("i: %d, sum: %lld\n", i, getSum(0, n - 1, root[i], 0, n - 1));
//		for (int s = 0; s < n; s++)
//			eprintf("%lld ", getSum(s, s, root[i], 0, n - 1));
//		eprintf("\n");
//		eprintf("sum: %lld\n", getSum(0, n - 1, root[i], 0, n - 1));
		ans += getSum(i + 1, n - 1, root[i], 0, n - 1);
	}
	printf("%lld\n", ans);
	return 0;
}