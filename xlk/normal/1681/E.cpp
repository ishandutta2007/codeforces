#include <bits/stdc++.h>
using namespace std;
struct N
{
	long long a[2][2];
	void print() const
	{
		printf("%lld %lld\n", a[0][0], a[0][1]);
		printf("%lld %lld\n", a[1][0], a[1][1]);
		printf("\n");
	}
}a[100020], t[400020];
int n, q;
int x[2][100020];
int y[2][100020];
N merge(const N &a, const N &b, int m)
{
	N c;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			c.a[i][j] = 1e18;
			c.a[i][j] = min(c.a[i][j], a.a[i][0] + b.a[0][j] + abs(x[0][m] + 1 - x[0][m + 1]) + abs(y[0][m] - y[0][m + 1]));
			c.a[i][j] = min(c.a[i][j], a.a[i][0] + b.a[1][j] + abs(x[0][m] + 1 - x[1][m + 1]) + abs(y[0][m] - y[1][m + 1]));
			c.a[i][j] = min(c.a[i][j], a.a[i][1] + b.a[0][j] + abs(x[1][m] - x[0][m + 1]) + abs(y[1][m] + 1 - y[0][m + 1]));
			c.a[i][j] = min(c.a[i][j], a.a[i][1] + b.a[1][j] + abs(x[1][m] - x[1][m + 1]) + abs(y[1][m] + 1 - y[1][m + 1]));
		}
	}
	return c;
}
void build(int x, int l, int r)
{
	if (l == r)
	{
		t[x] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(x * 2, l, m);
	build(x * 2 + 1, m + 1, r);
	t[x] = merge(t[x * 2], t[x * 2 + 1], m);
}
N query(int x, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
	{
		return t[x];
	}
	int m = (l + r) / 2;
	if (R <= m)
	{
		return query(x * 2, l, m, L, R);
	}
	else if (m < L)
	{
		return query(x * 2 + 1, m + 1, r, L, R);
	}
	return merge(query(x * 2, l, m, L, R), query(x * 2 + 1, m + 1, r, L, R), m);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d%d", &x[0][i], &y[0][i], &x[1][i], &y[1][i]);
		a[i].a[0][0] = 1;
		a[i].a[1][1] = 1;
		a[i].a[0][1] = abs(x[0][i] - x[1][i]) + abs(y[0][i] - y[1][i]) + 1;
		a[i].a[1][0] = abs(x[0][i] - x[1][i]) + abs(y[0][i] - y[1][i]) + 1;
	}
	build(1, 1, n - 1);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (max(x1, y1) > max(x2, y2))
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		int d1 = max(x1, y1);
		int d2 = max(x2, y2);
		if (d1 == d2)
		{
			printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
		}
		else
		{
			N u = query(1, 1, n - 1, d1, d2 - 1);
			long long z = 1e18;
			// cout << u.a[0][0] << endl;
			// cout << u.a[0][1] << endl;
			// cout << u.a[1][0] << endl;
			// cout << u.a[1][1] << endl;
			z = min(z, abs(x[0][d1] - x1) + abs(y[0][d1] - y1) + u.a[0][0] + abs(x[0][d2 - 1] + 1 - x2) + abs(y[0][d2 - 1] - y2));
			z = min(z, abs(x[0][d1] - x1) + abs(y[0][d1] - y1) + u.a[0][1] + abs(x[1][d2 - 1] - x2) + abs(y[1][d2 - 1] + 1 - y2));
			z = min(z, abs(x[1][d1] - x1) + abs(y[1][d1] - y1) + u.a[1][0] + abs(x[0][d2 - 1] + 1 - x2) + abs(y[0][d2 - 1] - y2));
			z = min(z, abs(x[1][d1] - x1) + abs(y[1][d1] - y1) + u.a[1][1] + abs(x[1][d2 - 1] - x2) + abs(y[1][d2 - 1] + 1 - y2));
			printf("%lld\n", z);
		}
	}
	return 0;
}