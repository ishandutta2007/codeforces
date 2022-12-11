#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)1e4;
vector <int> g[N];
bool used[N];
int a[N];
int ind;
bool dp[N];

int x;
bool bobr;

int dfs(int v)
{
	int t = 1;
	if (v == x)
		bobr = true;
	used[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
			t += dfs(to);
	}
	return t;
}

int p[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);  
		if (a[i] == 0)
			continue;
		g[i].push_back(a[i]);
		g[a[i]].push_back(i);
	}

	int len = 0;
	int t = a[x];
	while (t != 0)
	{
		len++;
		t = a[t];
	}

	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{       
			bobr = false;
			int l = dfs(i);
			if (!bobr)
				p[ind++] = l;
		}
	}

	dp[0] = 1;
	for (int i = 0; i < ind; i++)
	{
		for (int s = n; s >= 0; s--)
		{
			if (s - p[i] >= 0 && dp[s - p[i]])
				dp[s] = 1;
		}
	}                   


	for (int i = 0; i <= n; i++)
		if (dp[i])
			printf("%d\n", i + len + 1);

	return 0;
}