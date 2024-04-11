#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, k, a[Maxn], b[Maxn], ord[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long sum = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), b[i] = a[i] - n + i, sum += a[i], ord[i] = i;
		sort(ord + 1, ord + 1 + n, [](int x, int y){return b[x] < b[y];});
		long long ans = sum;
		for (int i = 1; i <= k; i++)
			ans = min(ans, sum -= b[ord[n - i + 1]] + i - 1);
		printf("%lld\n", ans);
	}
	return 0;
}