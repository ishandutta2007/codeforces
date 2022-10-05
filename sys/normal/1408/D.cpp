#include <bits/stdc++.h>
using namespace std;

int n, m, a[2005], b[2005], c[2005], d[2005], ans = 0x3f3f3f3f, maxi1[1000005], maxi2[1000005]; 
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &c[i], &d[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (c[j] >= a[i] && d[j] >= b[i])
			{
				maxi1[c[j] - a[i]] = max(maxi1[c[j] - a[i]], d[j] - b[i] + 1);
				maxi2[d[j] - b[i]] = max(maxi2[d[j] - b[i]], c[j] - a[i] + 1);
			}
	for (int i = 1e6; i >= 0; i--)
	{
		maxi1[i] = max(maxi1[i], maxi1[i + 1]), maxi2[i] = max(maxi2[i], maxi2[i + 1]);
		ans = min(ans, min(i + maxi1[i], i + maxi2[i]));
	}
	printf("%d", ans);
	return 0;
}