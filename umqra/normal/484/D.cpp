#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
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

const int pow2 = (1 << 20);
const int N = (int)1e6 + 10;

struct SegmentTree
{
	ll tree[pow2 * 2];
	ll d[pow2 * 2];
	SegmentTree()
	{
		memset(d, 0, sizeof(d));
		memset(tree, 0, sizeof(tree));
	}
	void push(int v)
	{
		tree[2 * v] += d[v];
		tree[2 * v + 1] += d[v];
		d[v] = 0;
	}
	void addVal(int a, int b, ll val, int v = 1, int l = 0, int r = pow2 - 1)
	{
		if (l >= a && r <= b)
		{
			tree[v] += val;
			d[v] += val;
			return;
		}
		if (l > b || r < a)
			return;
		push(v);
		int m = (l + r) / 2;
		addVal(a, b, val, 2 * v, l, m);
		addVal(a, b, val, 2 * v + 1, m + 1, r);
		tree[v] = max(tree[2 * v], tree[2 * v + 1]);
	}
	ll getMax()
	{
		return tree[1];
	}
} tree;

struct Stack
{
	int val[N];
	int it;
	Stack()
	{
		it = 0;
	}
	int size()
	{
		return it;
	}
	int get()
	{
		if (it == 0)
			return -1;
		return val[it - 1];
	}
	void pop()
	{
		it--;
	}
	void push(int x)
	{
		val[it++] = x;
	}
};

Stack stackMin, stackMax;
int a[N];
ll dp[N];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	stackMin.push(0);
	stackMax.push(0);
	for (int i = 1; i < n; i++)
	{
		while (stackMin.size() > 0 && a[stackMin.get()] >= a[i])
		{
			int p1 = stackMin.get();
			stackMin.pop();
			int p2 = stackMin.get() + 1;
			int old = a[p1];
			tree.addVal(p2, p1, old - a[i]);
		}
		stackMin.push(i);

		while (stackMax.size() > 0 && a[stackMax.get()] <= a[i])
		{
			int p1 = stackMax.get();
			stackMax.pop();
			int p2 = stackMax.get() + 1;
			int old = a[p1];
			tree.addVal(p2, p1, -old + a[i]);
		}
		stackMax.push(i);
		
		dp[i + 1] = tree.getMax();
		tree.addVal(i + 1, i + 1, dp[i + 1]);
	}
	cout << dp[n];

	return 0;
}