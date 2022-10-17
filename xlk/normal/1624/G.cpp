#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int f[200020];
vector<array<int, 3> > a;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		a.resize(m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][0]);
		}
		int z = 0;
		for (int j = 29; j >= 0; j--)
		{
			for (int i = 1; i <= n; i++)
			{
				f[i] = i;
			}
			z += 1 << j;
			for (int i = 0; i < m; i++)
			{
				if ((a[i][0] & z) == 0)
				{
					f[F(a[i][1])] = F(a[i][2]);
				}
			}
			for (int i = 1; i <= n; i++)
			{
				if (F(1) != F(i))
				{
					z -= 1 << j;
					break;
				}
			}
		}
		printf("%d\n", (1 << 30) - 1 - z);
	}
	return 0;
}