#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
vector<int> g[N];
int n, m;
int e[N][2];
int ord[N];
int ordSz;
set<pii> E;
bool used[N];

void dfs(int v)
{
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfs(u);
	ord[ordSz++] = v;
	return;
}

bool solve(int r)
{
	E.clear();
	for (int i = 0; i < n; i++)
		g[i].clear();
	ordSz = 0;
	for (int i = 0; i < n; i++)
		used[i] = false;
	for (int i = 0; i < r; i++)
	{
		int v = e[i][0], u = e[i][1];
		g[v].push_back(u);
		E.insert(mp(v, u));
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);
	for (int i = 0; i < ordSz - 1; i++)
		if (E.count(mp(ord[i + 1], ord[i])) == 0)
			return false;
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &e[i][j]);
			e[i][j]--;
		}
	int l = 0, r = m + 1;
	while(r - l > 1)
	{
		int x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	if (r == m + 1)
		r = -1;
	printf("%d\n", r);

	return 0;
}