#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 333;
int n;
int a[N];
bool g[N][N];
char s[N];
int col[N];
int C;
int b[N];

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		scanf(" %s ", s);
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				g[i][j] = 1;
	}
	return;
}

void dfs(int v)
{
	col[v] = C;
	for (int u = 0; u < n; u++)
	{
		if (col[u] != 0 || !g[v][u]) continue;
		dfs(u);
	}
	return;
}

void solve()
{
	C = 0;
	for (int i = 0; i < n; i++)
	{
		if (col[i] != 0) continue;
		C++;
		dfs(i);
	}

	for (int c = 1; c <= C; c++)
	{
		int sz = 0;
		for (int i = 0; i < n; i++)
			if (col[i] == c)
				b[sz++] = a[i];
		sort(b, b + sz);
		int idx = 0;
		for (int i = 0; i < n; i++)
			if (col[i] == c)
				a[i] = b[idx++];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);

	read();
	solve();
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}