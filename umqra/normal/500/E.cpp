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
const int N = (int)2e5 + 100;
const int LOG = 18;

struct SegmentTree
{
	int tree[pow2 * 2];
	SegmentTree() 
	{
		memset(tree, 0, sizeof(tree));
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

int pos[N], l[N];
int endPos[N], nextIndex[N];
int jump[LOG][N];
int cost[LOG][N];

void calcJumps(int n)
{
	nextIndex[n] = n;
	for (int i = 0; i < LOG; i++)
	{
		jump[i][n] = n;
		cost[i][n] = 0;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cost[0][i] = max(0, pos[nextIndex[i]] - endPos[i]);
		jump[0][i] = nextIndex[i];
		for (int s = 1; s < LOG; s++)
		{
			jump[s][i] = jump[s - 1][jump[s - 1][i]];
			cost[s][i] = cost[s - 1][i] + cost[s - 1][jump[s - 1][i]];
		}
	}
}

int solve(int a, int b)
{
	if (nextIndex[a] > b)
		return 0;
	int ans = 0;
	for (int i = LOG - 1; i >= 0; i--)
	{
		int nxt = jump[i][a];
		if (nextIndex[nxt] <= b)
		{
			ans += cost[i][a];
			a = nxt;
		}
	}
	return ans + cost[0][a];
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d%d", &pos[i], &l[i]);

	for (int i = n - 1; i >= 0; i--)
	{
		endPos[i] = pos[i] + l[i];
		int index = upper_bound(pos, pos + n, endPos[i]) - pos;
		index--;
		endPos[i] = max(endPos[i], tree.getMax(i, index));
		tree.setVal(i, endPos[i]);
		nextIndex[i] = upper_bound(pos, pos + n, endPos[i]) - pos;
	}

	calcJumps(n);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		printf("%d\n", solve(a, b));
	}

	return 0;
}