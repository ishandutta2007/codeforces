#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long s64;

const int M = 1000000007;

const int MaxN = 100000;

int n;
vector<int> adj[MaxN * 2 + 1];
int dep[MaxN * 2 + 1];
int spV[MaxN * 2 + 1];

void dfs(int v, int fa)
{
	dep[v] = dep[fa] + 1;
	adj[v].erase(remove(adj[v].begin(), adj[v].end(), fa), adj[v].end());
	for (int k = 0; k < (int)adj[v].size(); k++)
		dfs(adj[v][k], v);
	spV[v] = adj[v].size() == 1 ? spV[adj[v][0]] : v;
}

int f[MaxN * 2 + 1];

int getF(int v);
int getG(int v, int u);

int getF(int v)
{
	if (f[v] != -1)
		return f[v];
	int s = dep[spV[v]] - dep[v] + 1;
	if (adj[spV[v]].size() == 0)
		return f[v] = s % 2 == 0 ? s / 2 : 0;
	int l = adj[spV[v]][0], r = adj[spV[v]][1];
	f[v] = 0;
	for (int t = 0; t < 2; t++, swap(l, r))
	{
		int d1 = dep[spV[v]] - dep[v] + 1, d2;
		switch (adj[l].size())
		{
			case 0:
			case 1:
				if (adj[spV[l]].size() == 0)
				{
					d2 = dep[spV[l]] - dep[spV[v]];
					if ((d1 + d2) % 2 == 0)
					{
						if (d2 <= d1)
							f[v] = (f[v] + getF(r)) % M;
						if (d2 <= d1 - 2)
							f[v] = (f[v] + getF(r)) % M;
					}
				}
				if (d1 % 2 == 1 && adj[l].size() == 1)
					f[v] = (f[v] + getG(r, adj[l][0])) % M;
				break;
			case 2:
				if (adj[spV[adj[l][0]]].size() == 0)
				{
					d2 = dep[spV[adj[l][0]]] - dep[spV[v]];
					if ((d1 + d2) % 2 == 0 && d2 <= d1)
						f[v] = (f[v] + getG(r, adj[l][1])) % M;
				}
				if (adj[spV[adj[l][1]]].size() == 0)
				{
					d2 = dep[spV[adj[l][1]]] - dep[spV[v]];
					if ((d1 + d2) % 2 == 0 && d2 <= d1)
						f[v] = (f[v] + getG(r, adj[l][0])) % M;
				}
				break;
		}
	}
	return f[v];
}
int getG(int v, int u)
{
	while (adj[v].size() == 1 && adj[u].size() == 1)
		v = adj[v][0], u = adj[u][0];
	if (adj[v].size() == 0 && adj[u].size() == 1)
		return getF(adj[u][0]);
	if (adj[v].size() == 1 && adj[u].size() == 0)
		return getF(adj[v][0]);
	if (adj[v].size() == 0 && adj[u].size() == 0)
		return 1;
	return 0;
}

int calcC(int vl, int vm, int vr)
{
	switch (adj[vm].size())
	{
		case 0:
			return (s64)getF(vl) * getF(vr) % M;
		case 1:
			return ((s64)getG(vl, adj[vm][0]) * getF(vr) + (s64)getF(vl) * getG(vr, adj[vm][0])) % M;
		case 2:
			return ((s64)getG(vl, adj[vm][0]) * getG(vr, adj[vm][1]) + (s64)getG(vl, adj[vm][1]) * getG(vr, adj[vm][0])) % M;
		default:
			return 0;
	}
}

int calc()
{
	if (n == 1)
		return 2;
	int cv = 0;
	for (int v = 1; v <= n * 2; v++)
	{
		if (adj[v].size() > 3)
			return 0;
		if (adj[v].size() == 3)
			cv = v;
	}
	if (!cv)
		return ((s64)n * (n - 1) * 2 + 4) % M;

	for (int v = 1; v <= n * 2; v++)
		f[v] = -1;

	dep[0] = 0;
	dfs(cv, 0);

	int res = 0;
	sort(adj[cv].begin(), adj[cv].end());
	do
		res = (res + calcC(adj[cv][0], adj[cv][1], adj[cv][2])) % M;
	while (next_permutation(adj[cv].begin(), adj[cv].end()));
	res = res * 2 % M;
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	cout << calc() << endl;

	return 0;
}