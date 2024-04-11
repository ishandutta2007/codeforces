#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e8;
const int N = 100100;
int n, m;
vector<pii> g[N];
int q[N];
int p[N];
int sz;
int dist[N][2];
set<pii> r;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int v, u, z;
		scanf("%d%d%d", &v, &u, &z);
		g[v].push_back(mp(u, z));
		g[u].push_back(mp(v, z));
	}
	return;
}

void tryAddQ(int v, int par, int d, int d2)
{
	if (dist[v][0] < d) return;
	if (dist[v][0] == INF)
	{
		dist[v][0] = d;
		dist[v][1] = d2;
		p[v] = par;
		q[sz++] = v;
		return;
	}
	if (dist[v][0] != d) throw;
	if (dist[v][1] <= d2) return;
	dist[v][1] = d2;
	p[v] = par;
	return;
}

void solve()
{
	for (int i = 1; i <= n; i++)
		dist[i][0] = INF;
	dist[1][0] = 0;
	q[sz++] = 1;
	for (int k = 0; k < sz; k++)
	{
		int v = q[k];
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			int to = g[v][i].first;
			tryAddQ(to, v, dist[v][0] + 1, dist[v][1] + 1 - g[v][i].second);
		}
	}
	return;
}

void printAns()
{
	int v = n;
	while(p[v])
	{
		int nv = p[v];
//		printf("%d ", nv);
		r.insert( min(mp(v, nv), mp(nv, v)) );
		v = nv;
	}
	vector<pii> ans;
	for (int v = 1; v <= n; v++)
		for (int i = 0; i < (int)g[v].size(); i++)
		{
			int u = g[v][i].first;
			if (v > u) continue;
			pii tmp = mp(v, u);
			int x = (r.count(tmp) ? 1 : 0) ^ g[v][i].second;
			if (x)
				ans.push_back(tmp);
		}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
	{
		pii tmp = ans[i];
		int v = tmp.first;
		int u = tmp.second;
		printf("%d %d %d\n", v, u, (int)r.count(tmp));
	}
	return;
}

int main()
{
	read();
	solve();
	printAns();

	return 0;
}