#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = (int)1e5 + 100;
int n, m;
vector<int> g[N];
vector<int> gg[N];
vector<int> a[N];
int C;
int ans;
bool used[N];
int u[N];

void read()
{
	scanf("%d%d", &n, &m);
	int v, x;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &x);
		v--;
		x--;
		g[v].push_back(x);
		gg[v].push_back(x);
		gg[x].push_back(v);
	}
	return;
}

void dfs1(int v)
{
	used[v] = 1;
	a[C].push_back(v);
	ans++;
	for (int i = 0; i < (int)gg[v].size(); i++)
	{
		int to = gg[v][i];
		if (!used[to]) dfs1(to);
	}
	return;
}

bool dfs2(int v)
{
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (u[to] != 0)
		{
			if (u[to] == 1) return true;
		}
		else
		{
			if (dfs2(to)) return true;
		}
	}
	u[v] = 2;
	return false;
}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		if (used[i]) continue;
		dfs1(i);
		C++;
	}
	ans -= C;
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < (int)a[i].size(); j++)
		{
			int v = a[i][j];
			if (u[v] != 0) continue;
			if (dfs2(v))
			{
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return;
}

int main()
{
	read();
	solve();


	return 0;
}