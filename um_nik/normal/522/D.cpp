#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int pow2 = (1 << 20);
const int N = (int)5e5 + 100;
const int INF = (int)1e9;

struct SegmentTree
{
	int tree[pow2 * 2];
	SegmentTree ()
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

struct Query
{
	int id;
	int l, r;
	Query () {}
	bool operator < (const Query &q) const
	{
		return l < q.l;
	}
	void scan(int _id)
	{
		id = _id;
		scanf("%d%d", &l, &r);
		l--, r--;
	}
};

SegmentTree tree;
Query queries[N];
map <int, int> lastValue;
int nextEqual[N];
int answer[N];
int a[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = n - 1; i >= 0; i--)
	{
		if (lastValue.find(a[i]) != lastValue.end())
		{
			nextEqual[i] = lastValue[a[i]];
			tree.setVal(nextEqual[i], nextEqual[i] - i);
		}
		else
			nextEqual[i] = -1;
		lastValue[a[i]] = i;

	}

	for (int i = 0; i < m; i++)
		queries[i].scan(i);
	sort(queries, queries + m);

	int qit = 0;
	for (int i = 0; i < n; i++)
	{
		while (qit < m && queries[qit].l == i)
		{
			int id = queries[qit].id;
			answer[id] = tree.getMin(queries[qit].l, queries[qit].r);
			qit++;
		}
		if (nextEqual[i] != -1)
			tree.setVal(nextEqual[i], INF);
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", answer[i] == INF ? -1 : answer[i]);

	return 0;
}