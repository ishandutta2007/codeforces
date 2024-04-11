#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <complex>
#include <valarray>
#include <cassert>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int N = (int)5e5 + 10;
vector <int> g[N];
int sz[N];
int maxDownCut[N];
int maxUpCut[N];
int n;
int ans[N];

void dfs(int v, int p)
{
	sz[v] = 1;
	for (int to : g[v])
	{
		if (to == p)
			continue;
		dfs(to, v);
		sz[v] += sz[to];
		if (2 * sz[to] <= n)
			maxDownCut[v] = max(maxDownCut[v], sz[to]);
		maxDownCut[v] = max(maxDownCut[v], maxDownCut[to]);
	}
}

void dfsUp(int v, int p, int curCut)
{
	maxUpCut[v] = curCut;
	int m1 = 0, pos1 = -1, m2 = 0, pos2 = -1;
	for (int to : g[v])
	{
		if (to == p)
			continue;
		int cur = maxDownCut[to];
		int a = sz[to];
		if (2 * a <= n)
			cur = max(cur, a);
		if (cur > m1)
		{
			m2 = m1;
			pos2 = pos1;
			
			m1 = cur;
			pos1 = to;
		}
		else if (cur > m2)
		{
			m2 = cur;
			pos2 = to;
		}
	}
	for (int to : g[v])
	{
		if (to == p)
			continue;
		int passed = curCut;
		int up = n - sz[to];
		if (2 * up <= n)
			passed = max(passed, up);
		if (pos1 == to)
			passed = max(passed, m2);
		else
			passed = max(passed, m1);
		dfsUp(to, v, passed);
	}
}

void solve(int v, int p)
{
	//cout << v << ":" << maxDownCut[v] << ":" << maxUpCut[v] << endl;
	int m = 0, pos = 0;
	for (int to : g[v])
	{
		if (to == p)
			continue;
		if (sz[to] > m)
		{
			m = sz[to];
			pos = to;
		}
	}
	if (n - sz[v] > m)
	{
		m = n - sz[v];
		pos = -1;
	}
	if (2 * m <= n)
		ans[v] = 1;
	else
	{
		if (pos != -1)
		{
			int rem = m - maxDownCut[pos];
			ans[v] = (2 * rem <= n);
		}
		else
		{
			int rem = m - maxUpCut[v];
			ans[v] = (2 * rem <= n);
		}
	}
	for (int to : g[v])
	{
		if (to == p)
			continue;
		solve(to, v);
	}
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(0, -1);
	dfsUp(0, -1, 0);
	solve(0, -1);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	puts("");
	
	return 0;
}