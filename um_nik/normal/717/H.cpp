#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 50050;
const int M = 100100;
const int K = 1000100;
int n, m, k;
int a[N];
int b[K];
int ed[M][2];
vector<int> g[N];

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 2; j++)
		{
			scanf("%d", &ed[i][j]);
			ed[i][j]--;
		}
	for (int i = 0; i < n; i++)
	{
		int s;
		scanf("%d", &s);
		g[i].resize(s);
		for (int j = 0; j < s; j++)
		{
			scanf("%d", &g[i][j]);
			k = max(k, g[i][j]);
			g[i][j]--;
		}
	}
	return;
}

void solve1()
{
	while(true)
	{
		for (int i = 0; i < n; i++)
			a[i] = rand() & 1;
		int cnt = 0;
		for (int i = 0; i < m; i++)
			if (a[ed[i][0]] != a[ed[i][1]])
				cnt++;
		if (2 * cnt >= m) break;
	}
	return;
}
void solve2()
{
	while(true)
	{
		for (int i = 0; i < k; i++)
			b[i] = rand() & 1;
		bool ok = true;
		for (int i = 0; ok && i < n; i++)
		{
			bool cur = false;
			for (int x : g[i])
				cur |= (a[i] == b[x]);
			ok &= cur;
		}
		if (ok) break;
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	solve1();
	solve2();
	for (int i = 0; i < n; i++)
	{
		int it = 0;
		while(it < (int)g[i].size() && a[i] != b[g[i][it]]) it++;
		if (it == (int)g[i].size()) throw;
		printf("%d ", g[i][it] + 1);
	}
	printf("\n");
	for (int i = 0; i < k; i++)
		printf("%d ", b[i] + 1);
	printf("\n");

	return 0;
}