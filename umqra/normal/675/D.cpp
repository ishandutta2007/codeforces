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

const int INF = (int)1e9 + 10;
const int pow2 = (1 << 20);
const int N = (int)1e6 + 10;

struct SegmentTree
{
	pii tree[pow2 * 2];
	SegmentTree ()
	{
		for (int i = pow2; i < pow2 * 2; i++)
		{
			tree[i] = mp(INF, i - pow2);
		}
		for (int i = pow2 - 1; i >= 0; i--)
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	}
	pii getMin(int a, int b, int v, int l, int r)
	{
		if (l >= a && r <= b)
			return tree[v];
		if (l > b || r < a)
			return mp(INF, INF);
		int m = (l + r) / 2;
		return min(getMin(a, b, 2 * v, l, m), getMin(a, b, 2 * v + 1, m + 1, r));
	}
	pii getMin(int a, int b)
	{
		return getMin(a, b, 1, 0, pow2 - 1);
	}
	void setVal(int pos, int val)
	{
		int v = pos + pow2;
		tree[v].X = val;
		while (v > 1)
		{
			v /= 2;
			tree[v] = min(tree[2 * v], tree[2 * v + 1]);
		}
	}
};

SegmentTree tree;
int arr[N];
int coord[N];
int ans[N];
int cntC = 0;

void dfs(int pos, int p, int l, int r)
{
//	eprintf("%d %d\n", pos, p);
	if (p != -1)
		ans[pos] = coord[arr[p]];

	tree.setVal(arr[pos], INF);
	pii lCh = tree.getMin(l, arr[pos] - 1);
	pii rCh = tree.getMin(arr[pos] + 1, r);
	if (lCh.X != INF)
		dfs(lCh.X, pos, l, arr[pos] - 1);
	if (rCh.X != INF)
		dfs(rCh.X, pos, arr[pos] + 1, r);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		coord[i] = arr[i];
	}
	sort(coord, coord + n);
	cntC = unique(coord, coord + n) - coord;
	for (int i = 0; i < n; i++)
	{
		arr[i] = lower_bound(coord, coord + cntC, arr[i]) - coord;
		tree.setVal(arr[i], i);
	}
	dfs(0, -1, 0, pow2 - 1);
	for (int i = 1; i < n; i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}