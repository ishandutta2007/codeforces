#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool flag = true, flag2 = true, flag3 = true;
		scanf("%d", &n);
		long long sum = 0, x = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &x);
			sum += x;
			if (sum < 0) flag = false;
			if (!flag2 && sum) flag3 = false;
			if (sum == 0) flag2 = false;
		}
		puts(flag && !sum && flag3 ? "YES" : "NO");
	}
	return 0;
}