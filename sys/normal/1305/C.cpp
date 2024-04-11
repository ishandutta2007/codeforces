#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, a[Maxn];
long long ans = 1;
int main()
{
	scanf("%d%d", &n, &m);
	if (n > m)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			(ans *= abs(a[i] - a[j])) %= m;
	printf("%lld", ans);
	return 0;
}