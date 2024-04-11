#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[200020];
long long h[200020];
long long z[200020];
vector<int> a[200020];
int F(int x)
{
	if (f[x])
	{
		return f[x];
	}
	set<int> v;
	for (int y : a[x])
	{
		v.insert(F(y));
	}
	while (v.count(f[x]))
	{
		f[x]++;
	}
	return f[x];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &h[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		z[F(i)] ^= h[i];
	}
	for (int i = 1000; i >= 0; i--)
	{
		if (z[i])
		{
			puts("WIN");
			for (int x = 1; x <= n; x++)
			{
				if (f[x] == i && h[x] > (h[x] ^ z[i]))
				{
					h[x] ^= z[i];
					z[i] = 0;
					for (int y : a[x])
					{
						h[y] ^= z[f[y]];
						z[f[y]] = 0;
					}
					for (int j = 1; j <= n; j++)
					{
						printf("%lld%c", h[j], j == n ? '\n' : ' ');
					}
					return 0;
				}
			}
		}
	}
	puts("LOSE");
	return 0;
}