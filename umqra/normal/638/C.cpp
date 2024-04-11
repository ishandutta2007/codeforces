#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
const int N = 200200;
int n;
vector<pii> g[N];
vector<int> ans[N];
int a[N];
bool used[N];

void read()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(mp(u, i));
		g[u].push_back(mp(v, i));
	}
	return;
}

void dfs(int v)
{
	used[v] = 1;
	int x = 0;
	for (pii e : g[v])
	{
		int u = e.first;
		if (used[u])
			ans[a[v]].push_back(e.second);
		else
		{
			if (a[v] == x) x++;
			a[u] = x++;
			dfs(u);
		}
	}
	return;
}

int main()
{
	read();
	a[0] = -1;
	dfs(0);
	int k = N;
	while(ans[k - 1].empty()) k--;
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d", (int)ans[i].size());
		for (int x : ans[i])
			printf(" %d", x);
		printf("\n");
	}

	return 0;
}