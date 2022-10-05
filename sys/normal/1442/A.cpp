#include <bits/stdc++.h>
using namespace std;

const int Maxn = 30005;
int T, n, a[Maxn];
long long sum1, sum2;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		sum1 = sum2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 2; i <= n; i++)
			if (a[i - 1] > a[i]) sum1 += a[i - 1] - a[i];
			else sum2 += a[i] - a[i - 1];
		if (sum1 <= a[1] && sum2 <= a[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}