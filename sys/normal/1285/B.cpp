#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, a[Maxn];
long long sum, mini, ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = sum = 0;
		mini = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i < n; i++)
		{
			sum += a[i];
			ans = max(ans, sum - mini);
			mini = min(mini, sum);
		}
		sum = a[1];
		mini = a[1];
		for (int i = 2; i <= n; i++)
		{
			sum += a[i];
			ans = max(ans, sum - mini);
			mini = min(mini, sum);
		}
		if (ans < sum)
			puts("YES");
		else puts("NO");
	}
	return 0;
}