#include <bits/stdc++.h>
using namespace std;

long long n, k, l, r, ans = -1;
int main()
{
	scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
	if (n <= 10000)
	{
		long long tmp = r - l + 1;
		if (tmp <= 0) tmp += n;
		k -= tmp;
		for (int i = 0; i <= n; i++)
			for (int j = max(0LL, i - n + tmp); j <= min((long long) i, tmp); j++)
			{
				if ((k - j) % (n + i) == 0) ans = max(ans, (long long) i);
				if (i && j && (k - j + 1) % (n + i) == 0) ans = max(ans, (long long) i);
			}
		printf("%lld", ans);
	}
	else
	{
		long long tmp = r - l + 1;
		if (tmp <= 0) tmp += n;
		k -= tmp;
		for (long long t = 0; n * t <= k; t++)
		{
			long long kk = k - t * n, mini = 0, maxi = n;
			if (t) maxi = min(maxi, kk / t);
			maxi = min(maxi, (kk + n - tmp + 1) / (t + 1));
			if (t) mini = max(mini, (long long) ceil((kk - tmp) / (double) t));
			else if (kk > tmp) continue;
			mini = max(mini, (long long) ceil(kk / (double) (t + 1)));
			if (mini <= maxi) ans = max(ans, maxi);
		}
		printf("%lld", ans);
	}
	return 0;
}