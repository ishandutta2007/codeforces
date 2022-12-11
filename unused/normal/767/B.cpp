#include <bits/stdc++.h>
using namespace std;

map<long long, int> st;

int main()
{
	long long ts, tf, t; int n;
	scanf("%lld%lld%lld%d", &ts, &tf, &t, &n);
	for (int i = 0; i < n; i++)
	{
		long long tmp;
		scanf("%lld", &tmp);
		st[tmp]++;
	}

	long long ans = 0, ansb = 1e18;

	int total = 0;

	for (auto &&e : st)
	{
		long long serv = ts + t * total;
		if (serv > tf - t) break;
		if (ansb > serv - (e.first - 1))
		{
			ansb = serv - (e.first - 1);
			ans = min(serv, e.first - 1);
			if (ansb <= 0)
			{
				printf("%lld\n", ans);
				return 0;
			}
		}
		total += e.second;
	}

	if (ansb > 0 && ts + t * total <= tf - t)
	{
		printf("%lld\n", ts + t * total);
	}
	else
	{
		printf("%lld\n", ans);
	}
}