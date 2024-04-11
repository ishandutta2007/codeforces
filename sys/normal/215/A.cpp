#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55;
int n, m, a[Maxn], b[Maxn], ans, maxi;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (b[j] % a[i] == 0)
				maxi = max(maxi, b[j] / a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (b[j] % a[i] == 0 && b[j] / a[i] == maxi) ans++;
	printf("%d", ans);
	return 0;
}