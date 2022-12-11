#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

pair<long long, int> dat[100005];
long long scost[100005];
long long res[100005];

int main()
{
	int n;long long a,cf,cm;long long m;
	scanf("%d%lld%lld%lld%lld",&n,&a,&cf,&cm,&m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld",&dat[i].first);
		dat[i].second = i;
	}

	{
		long long sum = 0;
		for (int i = 0; i < n; i++) sum += a - dat[i].first;
		if (sum <= m) {
			printf("%lld\n", n*cf+cm*a);
			for (int i = 0; i < n; i++) printf("%lld ", a);
			return 0;
		}
	}

	sort(dat,dat+n,greater<pair<long long,int>>());

	scost[n-1] = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		scost[i] = scost[i+1] + (dat[i].first - dat[i+1].first) * (n-1ll-i);
	}

	long long ans = 0;
	long long mcost = 0;

	for (int i = 0; i < n; i++)
	{
		long long remain = m - mcost;

		auto it = lower_bound(scost+i, scost+n, remain, greater<long long>());
		int idx = it - scost;

		ans = max(ans, i * cf + cm * (dat[idx].first + (remain - *it) / (n - idx)));

		mcost += a - dat[i].first;
		if (mcost > m) break;
	}

	mcost = 0;

	printf("%lld\n", ans);

	for (int i = 0; i < n; i++)
	{
		long long remain = m - mcost;

		// scost[0]~scost[i-1] remain     
		auto it = lower_bound(scost+i, scost+n, remain, greater<long long>());
		int idx = it - scost;

		if (ans == i * cf + cm * (dat[idx].first + (remain - *it) / (n - idx)))
		{
			long long target = dat[idx].first + (remain - *it) / (n - idx);
			for (int j = 0; j < i; j++)
			{
				res[dat[j].second] = a;
			}

			for (int j = i; j < n; j++)
			{
				res[dat[j].second] = max(0ll, target - dat[j].first) + dat[j].first;
			}

			for (int i = 0; i < n; i++) printf("%lld ", res[i]);
			return 0;
		}

		mcost += a - dat[i].first;
		if (mcost > m) break;
	}
}