#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int LOG = 10;
const int N = 1 << LOG;
const int M = (int)1e6 + 7;
int n, m, q;

struct Query
{
	int id;
	int x1, x2, y1, y2;

	Query() : id(), x1(), x2(), y1(), y2() {}

	void scan(int _id)
	{
		id = _id;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--;
		x2--;
		y1--;
		y2--;
	}
};

int a[N][N];
int sum[N][N];
int p[N];
int tree[2 * N + 1][LOG][N + 1];

void build()
{
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
			tree[N + x][0][y] = a[x][y];
		for (int k = 1; k < LOG; k++)
			for (int y = 0; y + (1 << k) <= m; y++)
				tree[N + x][k][y] = max(tree[N + x][k - 1][y], tree[N + x][k - 1][y + (1 << (k - 1))]);
	}
	for (int v = N - 1; v > 0; v--)
		for (int k = 0; k < LOG; k++)
			for (int y = 0; y + (1 << k) <= m; y++)
				tree[v][k][y] = max(tree[2 * v][k][y], tree[2 * v + 1][k][y]);
	return;
}

int getMax(int v, int a, int b, int x1, int x2, int y1, int y2, int k)
{
	if (x1 <= a && b <= x2)
		return max(tree[v][k][y1], tree[v][k][y2]);
	if (x1 >= b || a >= x2) return 0;
	int mid = (a + b) / 2;
	return max(getMax(2 * v, a, mid, x1, x2, y1, y2, k), getMax(2 * v + 1, mid, b, x1, x2, y1, y2, k));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p[0] = p[1] = 0;
	for (int i = 2; i < N; i++)
		p[i] = p[i >> 1] + 1;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &sum[i + 1][j + 1]);
			sum[i + 1][j + 1] += sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
		}
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
		{
			int l = 0, r = min(n - x, m - y) + 1;
			while(r - l > 1)
			{
				int mid = (l + r) / 2;
				int S = sum[x + mid][y + mid] - sum[x][y + mid] - sum[x + mid][y] + sum[x][y];
				if (S == mid * mid)
					l = mid;
				else
					r = mid;
			}
			a[x][y] = l;
		}

	/*
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
			printf("%d ", a[x][y]);
		printf("\n");
	}
	*/

	build();

	scanf("%d", &q);
	while(q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		int l = 0, r = min(x2 - x1, y2 - y1) + 1;
		while(r - l > 1)
		{
			int mid = (l + r) / 2;
			int k = p[y2 - mid + 1 - y1];
			if (getMax(1, 0, N, x1, x2 - mid + 1, y1, y2 - mid + 1 - (1 << k), k) >= mid)
				l = mid;
			else
				r = mid;
		}
		printf("%d\n", l);
	}

	return 0;
}