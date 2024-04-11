#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

const int INF = 1000000000;

const int MaxN = 100000;
const int MaxM = 100000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}
template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int tot_min, tot_max;
int n, m;
int al[MaxN], ar[MaxN];
int col[MaxN];
vector<int> adj[MaxN];

int totl, totr;

void dfs(int v, int c)
{
	if (col[v])
	{
		if (col[v] != c)
		{
			puts("IMPOSSIBLE");
			exit(0);
		}
		return;
	}
	col[v] = c;
	for (int i = 0; i < (int)adj[v].size(); i++)
		dfs(adj[v][i], 3 - c);
}

void handle()
{
	totl = INF, totr = 0;
	for (int i = 0; i < n; i++)
		tension(totl, ar[i]), relax(totr, al[i]);
	if (totl + totr < tot_min)
		totr = tot_min - totl;
	else if (totl + totr > tot_max)
		totl = tot_max - totr;
	if (totl < 0)
	{
		puts("IMPOSSIBLE");
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		if (!(al[i] <= totl && totl <= ar[i]))
			dfs(i, 2);
		if (!(al[i] <= totr && totr <= ar[i]))
			dfs(i, 1);
	}
	for (int i = 0; i < n; i++)
		if (!col[i])
			dfs(i, 1);
}

int main()
{
	cin >> tot_min >> tot_max;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &al[i], &ar[i]);
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u), v--, u--;
		adj[v].push_back(u), adj[u].push_back(v);
	}

	handle();
	puts("POSSIBLE");
	printf("%d %d\n", totl, totr);
	for (int i = 0; i < n; i++)
		putchar('0' + col[i]);
	printf("\n");

	return 0;
}