#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100100;
int n, m;
vector<int> g[N];
int a[N];

bool dfs(int v)
{
	for (int u : g[v])
	{
		if (a[u] == 0)
		{
			a[u] = 3 - a[v];
			if (!dfs(u)) return false;
		}
		else
		{
			if (a[v] == a[u]) return false;
		}
	}
	return true;
}

void print(int k)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == k)
			cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		if (a[i] == k)
			printf("%d ", i + 1);
	printf("\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0) continue;
		a[i] = 1;
		if (!dfs(i))
		{
			printf("-1\n");
			return 0;
		}
	}
	print(1);
	print(2);

	return 0;
}