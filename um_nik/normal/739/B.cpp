#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;
const int N = 200200;
const int LOG = 18;
int n;
vector<int> g[N];
ll a[N];
int par[N][LOG];
ll w[N][LOG];
int b[N];

void read()
{
	scanf("%d", &n);
	for (int v = 0; v < n; v++)
		for (int i = 0; i < LOG; i++)
		{
			par[v][i] = -1;
			w[v][i] = 0;
		}
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int v;
		ll x;
		scanf("%d%lld", &v, &x);
		v--;
		g[v].push_back(i);
		par[i][0] = v;
		w[i][0] = x;
	}
	return;
}

void dfs(int v)
{
	for (int u : g[v])
	{
		for (int k = 1; k < LOG; k++)
		{
			int s = par[u][k - 1];
			if (s == -1)
			{
				par[u][k] = -1;
				w[u][k] = 0;
				continue;
			}
			par[u][k] = par[s][k - 1];
			w[u][k] = w[u][k - 1] + w[s][k - 1];
		}
		dfs(u);
	}
	return;
}

void solve(int v)
{
	for (int u : g[v])
	{
		solve(u);
		b[v] += b[u];
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	dfs(0);
	for (int v = 1; v < n; v++)
	{
		ll x = a[v];
		int u = v;
		for (int k = LOG - 1; k >= 0; k--)
		{
			if (par[u][k] == -1) continue;
			if (w[u][k] > x) continue;
			x -= w[u][k];
			u = par[u][k];
		}
//		printf("%d %d\n", v, u);
		if (par[u][0] != -1)
			b[par[u][0]]--;
		if (par[v][0] != -1)
			b[par[v][0]]++;
	}
	solve(0);
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}