#include <bits/stdc++.h>
using namespace std;
int a[200020];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			if ((x - j) % m == 0 && x <= n * m)
			{
				a[(i + n - (x - j) / m) % n + (j - 1) * n]++;
			}
		}
	}
	int z = 0;
	for (int j = 0; j < m; j++)
	{
		int t = 0;
		for (int i = 0; i < n; i++)
		{
			t = max(t, a[j * n + i] - i);
		}
		z += n - t;
	}
	printf("%d\n", z);
	return 0;
}