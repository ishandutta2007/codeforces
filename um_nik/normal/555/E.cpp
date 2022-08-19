#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = 200200;
const int LOG = 18;
int n, m, q;
vector<int> g[N];
int col[N];
int ed[N][2];
bool br[N];
int Q[N][2];
int tm[N];
int T;

void read()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		ed[i][0] = v;
		ed[i][1] = u;
		g[v].push_back(i);
		g[u].push_back(i);
	}
	for (int i = 0; i < q; i++)
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &Q[i][j]);
			Q[i][j]--;
		}
	return;
}

void dfsCon(int v, int C)
{
	col[v] = C;
	for (int e : g[v])
	{
		if (br[e]) continue;
		int to = v ^ ed[e][0] ^ ed[e][1];
		if (col[to]) continue;
		dfsCon(to, C);
	}
	return;
}

bool checkConnectivity()
{
	int C = 1;
	for (int v = 0; v < n; v++)
	{
		if (col[v]) continue;
		dfsCon(v, C);
		C++;
	}
	for (int i = 0; i < q; i++)
		if (col[Q[i][0]] != col[Q[i][1]])
			return false;
	for (int v = 0; v < n; v++)
		col[v] = 0;
	return true;
}

void dfsBridges(int v, int parE)
{
	int oldT = T;
	tm[v] = T++;
	for (int e : g[v])
	{
		if (e == parE) continue;
		int u = v ^ ed[e][0] ^ ed[e][1];
		if (tm[u] == 0) dfsBridges(u, e);
		tm[v] = min(tm[v], tm[u]);
	}
	if (oldT == tm[v] && parE != -1)
		br[parE] = true;
	return;
}

void findBridges()
{
	T = 1;
	for (int v = 0; v < n; v++)
	{
		if (tm[v]) continue;
		dfsBridges(v, -1);
	}
	int C = 1;
	for (int v = 0; v < n; v++)
	{
		if (col[v]) continue;
		dfsCon(v, C);
		C++;
	}
	for (int i = 0; i < q; i++)
		for (int j = 0; j < 2; j++)
			Q[i][j] = col[Q[i][j]] - 1;
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 0; i < m; i++)
	{
		if (!br[i]) continue;
		int v = col[ed[i][0]] - 1;
		int u = col[ed[i][1]] - 1;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	n = C - 1;

	return;
}

int h[N];
int p[N][LOG];
bool used[N];

void dfsLog(int v)
{
	used[v] = true;
	for (int u : g[v])
	{
		if (used[u]) continue;
		h[u] = h[v] + 1;
		p[u][0] = v;
		for (int i = 1; i < LOG; i++)
		{
			if (p[u][i - 1] == -1)
			{
				p[u][i] = -1;
				continue;
			}
			p[u][i] = p[p[u][i - 1]][i - 1];
		}
		dfsLog(u);
	}
	return;
}

int goUp(int v, int dh)
{
	for (int k = LOG - 1; k >= 0; k--)
	{
		if ((1 << k) > dh) continue;
		dh -= 1 << k;
		v = p[v][k];
	}
	return v;
}

int getLCA(int v, int u)
{
	if (h[v] > h[u]) swap(v, u);
	u = goUp(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--)
	{
		if (p[v][k] != p[u][k])
		{
			v = p[v][k];
			u = p[u][k];
		}
	}
	return p[v][0];
}

void buildLog()
{
	for (int v = 0; v < n; v++)
	{
		if (used[v]) continue;
		h[v] = 0;
		for (int i = 0; i < LOG; i++)
			p[v][i] = -1;
		dfsLog(v);
	}
	return;
}

int up[N];
int down[N];

void dfsCollect(int v)
{
	for (int u : g[v])
	{
		if (h[u] <= h[v]) continue;
		dfsCollect(u);
		up[v] += up[u];
		down[v] += down[u];
	}
	return;
}

void collect()
{
	for (int v = 0; v < n; v++)
		if (h[v] == 0)
			dfsCollect(v);
	return;
}

bool solve()
{
	if (!checkConnectivity()) return false;
	findBridges();
	buildLog();
	for (int i = 0; i < q; i++)
	{
		int v = Q[i][0];
		int u = Q[i][1];
		if (v == u) continue;
		int w = getLCA(v, u);
		up[v]++;
		up[w]--;
		down[u]++;
		down[w]--;
	}
	collect();
	for (int v = 0; v < n; v++)
		if (up[v] > 0 && down[v] > 0)
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	read();
	if (solve())
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}