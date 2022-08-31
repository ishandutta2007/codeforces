#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int N = 220;
const int M = N * N;
int n, m;
vector<int> g[N];
int ed[M][2];
bool badEd[M];
int ord[M];
int k;
set<pii> setik;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		ed[i][0] = v;
		ed[i][1] = u;
		badEd[i] = 0;
		g[v].push_back(i);
		g[u].push_back(i);
	}
	return;
}

int getOther(int id, int v)
{
	return v ^ ed[id][0] ^ ed[id][1];
}

void dfs(int v)
{
	while(!g[v].empty())
	{
		int id = g[v].back();
		g[v].pop_back();
		if (badEd[id]) continue;
		badEd[id] = 1;
		dfs(getOther(id, v));
	}
	ord[k++] = v;
	return;
}

void solve()
{
	read();
	setik.clear();
	int v = -1;
	int ans = n;
	for (int i = 0; i < n; i++)
	{
		if ((int)g[i].size() % 2 == 0) continue;
		ans--;
		if (v == -1)
			v = i;
		else
		{
			setik.insert(mp(v, i));
			g[v].push_back(m);
			g[i].push_back(m);
			ed[m][0] = v;
			ed[m][1] = i;
			badEd[m] = 0;
			m++;
			v = -1;
		}
	}
	if (v != -1) throw;
	printf("%d\n", ans);
	for (int v = 0; v < n; v++)
	{
		if (!g[v].empty())
		{
			k = 0;
			dfs(v);
			for (int i = 0; i < k - 1; i++)
			{
				int v = ord[i], u = ord[i + 1];
				if (setik.count(mp(v, u)) > 0)
				{
					setik.erase(mp(v, u));
					continue;
				}
				if (setik.count(mp(u, v)) > 0)
				{
					setik.erase(mp(u, v));
					continue;
				}
				printf("%d %d\n", v + 1, u + 1);
			}
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--)
		solve();

	return 0;
}