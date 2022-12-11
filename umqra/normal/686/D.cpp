#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int LOG = 20;
const int N = (int)4e5 + 10;
vector <int> g[N];
int sz[N];
int query[N];
int nxt[LOG][N];
int n, q;

void read()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n - 1; i++)
	{
		int p;
		scanf("%d", &p);
		p--;
		g[p].push_back(i);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &query[i]);
		query[i]--;
	}
}

int dfs(int v)
{
	sz[v] = 1;
	for (int to : g[v])
	{
		sz[v] += dfs(to);
	}
	return sz[v];
}

void init()
{
	for (int i = 0; i < n; i++)
	{
		nxt[0][i] = -1;
	 	for (int to : g[i])
	 	{
	 		if (2 * sz[to] >= sz[i])
	 			nxt[0][i] = to;
	 	}
	}
	for (int i = 1; i < LOG; i++)
	{
		for (int s = 0; s < n; s++)
		{
			int x = nxt[i - 1][s];
			if (x == -1)
				nxt[i][s] = -1;
			else
				nxt[i][s] = nxt[i - 1][x];
		}
	}
}

int solve(int v)
{
	int st = v;
	for (int i = LOG - 1; i >= 0; i--)
	{
		int to = nxt[i][v];
		if (to != -1 && 2 * sz[to] >= sz[st])
			v = to;
	}
	return v;
}

void solve()
{
	dfs(0);
	init();
	for (int i = 0; i < q; i++)
	{
		printf("%d\n", solve(query[i]) + 1);
	}
}

int main()
{
	read();
	solve();
	return 0;
}