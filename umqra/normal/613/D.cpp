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

const int N = (int)4e5 + 100;
const int LOG = 20;
int n, q;
int cnt;
int qV[N];
vector <int> g[N];
int jump[LOG][N];
int h[N];
int used[N];
int tin[N];
int tout[N];
int tme = 0;

void dfs(int v)
{
	eprintf("Dfs: %d\n", v);
	tin[v] = tme++;
	used[v] = 1;
	for (int i = 1; i < LOG; i++)
	{
		jump[i][v] = jump[i - 1][jump[i - 1][v]];
	}
	for (int to : g[v])
	{
		if (!used[to])
		{
			h[to] = h[v] + 1;
			jump[0][to] = v;
			dfs(to);
		}
	}
	tout[v] = tme - 1;
}

int go(int v, int d)
{
	for (int i = 0; i < LOG; i++)
	{
		if (d & (1 << i))
			v = jump[i][v];
	}
	return v;
}

int getLca(int a, int b)
{
	if (h[a] > h[b])
		return getLca(b, a);
	b = go(b, h[b] - h[a]);
	if (a == b)
		return a;
	for (int i = LOG - 1; i >= 0; i--)
	{
		int va = jump[i][a];
		int vb = jump[i][b];
		if (va != vb)
			a = va, b = vb;
	}
	return jump[0][a];
}

const int pow2 = (1 << 20);
const int INF = (int)1e9 + 10;

int posIn[N];
int on[N];

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
} tree;

int add(int a, int b)
{
	a += b;
	if (a > INF)
		return INF;
	return a;
}

void fadd(int &a, int b)
{
	a = add(a, b);
}

pii solve(int pos)
{
	int v = qV[pos];
	tree.setVal(tin[qV[pos]], INF);
	pii result = mp(INF, INF);

	vector <pii> childs = vector<pii>();
	eprintf("%d\n", v);
	while (1)
	{
		eprintf("%d %d\n", tin[v], tout[v]);
		pii res = tree.getMin(tin[v], tout[v]);
//		eprintf("%d %d\n", res.X, res.Y);
		if (res.X == INF)
			break;
		int value = res.X;
		int newPos = posIn[value];
		pii child = solve(newPos);
		eprintf("From %d, %d %d\n", qV[newPos], child.X, child.Y);
		childs.push_back(child);
	}
	
	ll curValue;
	if (!on[v])
	{
		curValue = 1;
		for (pii x : childs)
			curValue += min(x.X, x.Y);
		curValue = min(curValue, (ll)INF);
		result.X = min(result.X, (int)curValue);

		curValue = 0;
		for (pii x : childs)
			curValue += x.X;

		curValue = min(curValue, (ll)INF);
		result.X = min(result.X, (int)curValue);

		curValue = 0;
		for (pii x : childs)
			curValue += x.X;
		int curMin = INF;
		for (pii x : childs)
		{
			if (-x.X + x.Y < curMin)
				curMin = -x.X + x.Y;
		}
		curValue = curValue + curMin;
		result.Y = min(curValue, (ll)INF);
	}
	
	if (on[v])
	{
		curValue = 0;
		for (pii x : childs)
			curValue += x.X;
		result.Y = min(result.Y, (int)min(curValue, (ll)INF));
		result.X = INF;
	}
	return result;
}

void clear()
{ 
	for (int i = 0; i < cnt; i++)
		on[qV[i]] = 0;
}

void solve()
{
	sort(qV, qV + cnt, [](int a, int b) { return tin[a] < tin[b]; });		
	for (int i = 0; i < cnt; i++)
		on[qV[i]] = 1;
	for (int i = 0; i < n; i++)
		eprintf("%d: %d\n", i, tin[i]);
	eprintf("\n");
	for (int i = 0; i < cnt; i++)
		eprintf("%d ", qV[i]);
	eprintf("\n");
	int oldCnt = cnt;
	for (int i = 0; i < oldCnt - 1; i++)
	{
		int a = qV[i];
		int b = qV[i + 1];
		eprintf("%d %d\n", a, b);
		int c = getLca(a, b);
		qV[cnt++] = c;
	}
	oldCnt = cnt;
	for (int i = 0; i < oldCnt; i++)
	{
		qV[cnt++] = jump[0][qV[i]];
	}
	sort(qV, qV + cnt, [](int a, int b) { return tin[a] < tin[b]; });		
	cnt = unique(qV, qV + cnt) - qV;
	for (int i = 0; i < cnt; i++)
		eprintf("%d ", qV[i]);
	eprintf("\n");
	for (int i = 0; i < cnt; i++)
	{
		posIn[tin[qV[i]]] = i;
		tree.setVal(tin[qV[i]], tin[qV[i]]);
	}

	pii res = solve(0);
	int ans = min(res.X, res.Y);
	printf("%d\n", ans == INF ? -1 : ans);
	clear();
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	eprintf("Query:\n");

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &cnt);
		for (int s = 0; s < cnt; s++)
		{
			scanf("%d", &qV[s]);
			qV[s]--;
		}
		solve();
	}
	return 0;
}