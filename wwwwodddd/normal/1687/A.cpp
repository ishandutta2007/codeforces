#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[200020];
long long s[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &m);
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			s[i] = s[i - 1] + a[i];
			z += a[i];
		}
		if (m < n)
		{
			z = 0;
			for (int i = m; i <= n; i++)
			{
				z = max(z, s[i] - s[i - m]);
			}
			z += (long long)m * (m - 1) / 2;
		}
		else
		{
			z += (long long)n * (n - 1) / 2;
			z += (long long)(m - n) * n;
		}
		cout << z << endl;
	}
	return 0;
}