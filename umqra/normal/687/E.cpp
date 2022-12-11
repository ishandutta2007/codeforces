#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

#include <valarray>
#include <complex>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

int n, m;
const int N = (int)5050;
const int INF = (int)1e9 + 10;
vector <int> g[N], gT[N];
int topSort[N];
int cntT = 0;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b);
		gT[b].push_back(a);
	}
}

int used[N];

void dfs(int v)
{
	used[v] = 1;
	for (int to : g[v])
	{
		if (!used[to])
			dfs(to);
	}
	topSort[cntT++] = v;
}

int cc = 1;
int color[N];
int inDeg[N];

void paint(int v, int c)
{
	color[v] = c;
	for (int to : gT[v])
	{
		if (color[to] == 0)
			paint(to, c);
		else if (color[to] != c)
			inDeg[color[to]]++;
			
	}
}

int q[N];
int dist[N];

int getDist(int from, int to)
{
	int r = 0;
	fill(dist, dist + n, INF);
	dist[from] = 0;
	q[r++] = from;
	for (int i = 0; i < r; i++)
	{
		int v = q[i];
		if (v == to)
			break;
		for (int to : g[v])
		{
			if (dist[to] > dist[v] + 1)
			{
				dist[to] = dist[v] + 1;
				q[r++] = to;
			}
		}
	}
	return dist[to];
}

int getMinCycle(int c)
{
	int cntV = 0;
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		if (color[i] == c)
			cntV++;
		for (int to : g[i])
		{
			if (color[i] == c && color[to] == c)
			{
				ans = min(ans, getDist(to, i) + 1);
			}
		}
	}
	if (cntV == 1)
		return 0;
	return ans;
}

void getComps()
{
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			dfs(i);
	}

	for (int i = cntT - 1; i >= 0; i--)
	{
		int v = topSort[i];
		if (color[v] == 0)
			paint(v, cc++);
	}
	int ans = n;
	for (int i = 1; i < cc; i++)
	{
		if (inDeg[i] != 0)
			continue;
		int len = getMinCycle(i);
		if (len != 0)
			ans += len * 998 + 1;
	}
	printf("%d\n", ans);
}

void solve()
{
	getComps();
}

int main()
{
	read();
	solve();
    return 0;
}