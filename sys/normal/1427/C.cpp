#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int r, n, t[Maxn], x[Maxn], y[Maxn], f[Maxn], maxi[Maxn];
int main()
{
	scanf("%d%d", &r, &n);
	x[0] = y[0] = 1;
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (t[i] - t[j] >= 1000)
			{
				f[i] = max(f[i], maxi[j] + 1);
				break;
			}
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
				f[i] = max(f[i], f[j] + 1);
		}
		maxi[i] = max(maxi[i - 1], f[i]);
	}
	printf("%d", maxi[n]);
	return 0;
}