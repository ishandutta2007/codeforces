#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e8 + 10;
const int N = 100100;
int n, m;
vector<pii> g[N];
int k = 0;
vector<int> a[N][2];
int ans1, ans2;
int col[N];

bool dfs(int v, int X)
{
	for (pii e : g[v])
	{
		int u = e.first;
		int w = e.second ^ X;
		if (col[u] == -1)
		{
			col[u] = col[v] ^ w;
			a[k][col[u]].push_back(u);
			if (!dfs(u, X))
				return false;
		}
		else
		{
			if ((col[v] ^ w) != col[u])
				return false;
		}
	}
	return true;
}

int solve(int X)
{
	for (int i = 0; i < k + 3; i++)
	{
		a[i][0].clear();
		a[i][1].clear();
	}
	k = 0;
	for (int i = 0; i < n; i++)
		col[i] = -1;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (col[i] != -1) continue;
		col[i] = 0;
		a[k][0].push_back(i);
		if (!dfs(i, X))
			return INF;
		res += min((int)a[k][0].size(), (int)a[k][1].size());
		k++;
	}
	return res;
}

void printAns()
{
	int res = min(ans1, ans2);
	if (res == INF)
	{
		printf("-1\n");
		return;
	}
	printf("%d\n", res);
	for (int i = 0; i < k; i++)
	{
		int t = ((int)a[i][0].size() < (int)a[i][1].size() ? 0 : 1);
		for (int x : a[i][t])
			printf("%d ", x + 1);
	}
	printf("\n");
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int v, u;
		char _c;
		scanf("%d%d %c ", &v, &u, &_c);
		v--;u--;
		int c = (_c == 'B' ? 0 : 1);
		g[v].push_back(mp(u, c));
		g[u].push_back(mp(v, c));
	}
	ans1 = solve(0);
	ans2 = solve(1);
	if (ans1 < ans2)
		solve(0);
	else
		solve(1);
	printAns();

	return 0;
}