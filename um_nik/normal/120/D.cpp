#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 55;
int a[N][N];
int x[N], y[N];
int n, m;
int ans;
int b[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < 3; i++)
		scanf("%d", &x[i]);

	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
		for (int j = 0; j < m; j++)
			b[i] += a[i][j];
	}
	for (int l = 1; l < n; l++)
		for (int r = l + 1; r < n; r++)
		{
			for (int i = 0; i < 3; i++)
				y[i] = 0;
			int id = 0;
			for (int i = 0; i < n; i++)
			{
				if (i == l) id++;
				if (i == r) id++;
				y[id] += b[i];
			}
			sort(x, x + 3);
			sort(y, y + 3);
			bool ok = true;
			for (int i = 0; i < 3; i++)
				ok &= (x[i] == y[i]);
			if (ok) ans++;
		}

	swap(n, m);
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
		for (int j = 0; j < m; j++)
			b[i] += a[j][i];
	}
	for (int l = 1; l < n; l++)
		for (int r = l + 1; r < n; r++)
		{
			for (int i = 0; i < 3; i++)
				y[i] = 0;
			int id = 0;
			for (int i = 0; i < n; i++)
			{
				if (i == l) id++;
				if (i == r) id++;
				y[id] += b[i];
			}
			sort(x, x + 3);
			sort(y, y + 3);
			bool ok = true;
			for (int i = 0; i < 3; i++)
				ok &= (x[i] == y[i]);
			if (ok) ans++;
		}

	printf("%d\n", ans);

	return 0;
}