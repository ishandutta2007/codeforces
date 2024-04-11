#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;
int n, S, E, x[Maxn], a[Maxn], b[Maxn], c[Maxn], d[Maxn];
long long f[Maxn], tmp[Maxn];
int main()
{
	scanf("%d%d%d", &n, &S, &E);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	for (int i = 1; i <= n; i++)
		c[i] += x[i], a[i] += x[i], b[i] -= x[i], d[i] -= x[i];
	for (int i = 1; i <= n; i++)
		f[i] = 0x3f3f3f3f3f3f3f3fLL;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			tmp[j] = 0x3f3f3f3f3f3f3f3fLL;
		if (i == n)
		{
			if (i == S) tmp[0] = f[0] + c[i];
			else if (i == E) tmp[0] = f[0] + a[i];
			else tmp[0] = f[0] + a[i] + c[i];
		}
		else
		{
			if (i == S)
			{
				for (int j = 0; j <= n; j++)
					tmp[j] = min(tmp[j], f[j] + d[i]);
				for (int j = 1; j <= n; j++)
					tmp[j - 1] = min(tmp[j - 1], f[j] + c[i]);
			}
			else if (i == E)
			{
				for (int j = 0; j <= n; j++)
					tmp[j] = min(tmp[j], f[j] + b[i]);
				for (int j = 1; j <= n; j++)
					tmp[j - 1] = min(tmp[j - 1], f[j] + a[i]);
			}
			else
			{
				for (int j = 0; j < n; j++)
					tmp[j + 1] = min(tmp[j + 1], f[j] + b[i] + d[i]);
				for (int j = 1 - (S < i); j <= n; j++)
					tmp[j] = min(tmp[j], f[j] + a[i] + d[i]);
				for (int j = 1 - (E < i); j <= n; j++)
					tmp[j] = min(tmp[j], f[j] + b[i] + c[i]);
				for (int j = 2 - (S < i || E < i); j <= n; j++)
					tmp[j - 1] = min(tmp[j - 1], f[j] + a[i] + c[i]);
			}
		}
		swap(tmp, f);
	}
	printf("%lld", f[0]);
	return 0;
}