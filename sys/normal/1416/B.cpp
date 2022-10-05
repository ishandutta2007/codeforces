#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 30005;
int T, n, ct, ave, a[Maxn], aa[Maxn], ord[Maxn];
long long sum;
queue <pair <int, int> > Qu;
struct tri
{
	int first, second, third;
} ans[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0, sum = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), sum += a[i];
		if (sum % n)
		{
			puts("-1");
			continue;
		}
		ave = sum / n;
		for (int i = 1; i <= n; i++)
			ans[++ct] = (tri){i, i % n + 1, a[i] / i}, a[i % n + 1] += a[i] / i * i, a[i] %= i;
		for (int i = 2; i <= n; i++)
			if (a[i] >= ave)
			{
				ans[++ct] = (tri){1, i, i + ave - a[i]};
				ans[++ct] = (tri){i, 1, 1};
			}
		for (int i = 2; i <= n; i++)
			if (a[i] < ave)
				ans[++ct] = (tri){1, i, ave - a[i]};
		printf("%d\n", ct);
		for (int i = 1; i <= ct; i++)
			printf("%d %d %d\n", ans[i].first, ans[i].second, ans[i].third);
	}
	return 0;
}