#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[1 << 20];
long long f[22][2], z;
void F(int d, int l, int r)
{
	if (l + 1 == r)
	{
		return;
	}
	int m = (l + r) / 2;
	F(d - 1, l, m);
	F(d - 1, m, r);
	for (int i = l; i < m; i++)
	{
		f[d][0] += lower_bound(a + m, a + r, a[i]) - a - m;
		f[d][1] += a + r - upper_bound(a + m, a + r, a[i]);
	}
	sort(a + l, a + r);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; i++)
	{
		scanf("%d", &a[i]);
	}
	F(n, 0, 1 << n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		for (int i = 1; i <= x; i++)
		{
			swap(f[i][0], f[i][1]);
		}
		z = 0;
		for (int i = 1; i <= n; i++)
		{
			z += f[i][0];
		}
		printf("%lld\n", z);
	}
	return 0;
}