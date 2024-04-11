#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int N = 5002;
int n, m, T;
vector<pii> g[N];
int dp[N][N];
int par[N][N];
int ord[N];
bool used[N];
int id[N];
int ans[N];

void dfs(int v)
{
	used[v] = 1;
	for (pii e : g[v])
	{
		int u = e.first;
		if (!used[u]) dfs(u);
	}
	ord[m++] = v;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &T);
	while(m--)
	{
		int v, u, t;
		scanf("%d%d%d", &v, &u, &t);
		v--;u--;
		g[v].push_back(mp(u, t));
	}
	m = 0;
	for (int i = 0; i < n; i++)
	{
		if (used[i]) continue;
		dfs(i);
	}
	reverse(ord, ord + m);
/*	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", ord[i]);
	printf("\n");*/
	int k = 0;
	while(ord[k] != 0) k++;
	for (int i = k; i < n; i++)
		ord[i - k] = ord[i];
	m = n - k;
	while(ord[m - 1] != n - 1) m--;
/*	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", ord[i]);
	printf("\n");*/
	for (int i = 0; i < n; i++)
		id[i] = -1;
	for (int i = 0; i < m; i++)
		id[ord[i]] = i;
	for (int i = 0; i <= m; i++)
		for (int x = 0; x <= m; x++)
			dp[i][x] = T + 1;
	dp[0][1] = 0;
	for (int i = 0; i < m - 1; i++)
	{
		int v = ord[i];
		for (pii e : g[v])
		{
			int u = id[e.first];
			if (u == -1) continue;
			for (int x = 0; x <= m; x++)
			{
				if (dp[i][x] == T + 1) continue;
				int t = dp[i][x] + e.second;
				if (t < dp[u][x + 1])
				{
					dp[u][x + 1] = t;
					par[u][x + 1] = i;
				}
			}
		}
	}
	int x = m;
	while(x > 0 && dp[m - 1][x] == T + 1) x--;
	if (x == 0) throw;
	printf("%d\n", x);
	int ansSz = x;
	int v = m - 1;
	while(x > 0)
	{
		int u = par[v][x];
		x--;
		ans[x] = ord[v];
		v = u;
	}
	ans[0] = 0;
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}