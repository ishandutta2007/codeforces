#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = (int)1e5 + 100;
const int M = 6;
const int K = 20;
int a[N][M];
int n, m, q;
int sparse[M][N][K];
int ans[M];
int p[N];

void read()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	return;
}

void build()
{
	p[0] = p[1] = 0;
	for (int i = 2; i < N; i++)
		p[i] = p[i / 2] + 1;

	for (int it = 0; it < m; it++)
	{
		for (int i = 0; i < n; i++)
			sparse[it][i][0] = a[i][it];
		for (int k = 1; k < K; k++)
			for (int i = 0; i + (1 << k) <= n; i++)
				sparse[it][i][k] = max(sparse[it][i][k - 1], sparse[it][i + (1 << (k - 1))][k - 1]);
	}
	return;
}

int getMax(int it, int l, int r)
{
	int k = p[r - l];
	return max( sparse[it][l][k], sparse[it][r - (1 << k)][k] );
}

bool check(int len)
{
	for (int i = 0; i + len <= n; i++)
	{
		int l = i, r = i + len;
		for (int j = 0; j < m; j++)
			ans[j] = getMax(j, l, r);
		int s = 0;
		for (int j = 0; j < m; j++)
			s += ans[j];
		if (s <= q)
			return true;
	}
	return false;
}

void solve()
{
	int L = 0, R = n + 1;
	while(R - L > 1)
	{
		int val = (L + R) / 2;
		if (check(val))
			L = val;
		else
			R = val;
	}
	check(L);
	if (L == 0)
	{
		for (int i = 0; i < m; i++)
			ans[i] = 0;
	}
	for (int i = 0; i < m; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return;
}

int main()
{
	read();
	build();
	solve();

	return 0;
}