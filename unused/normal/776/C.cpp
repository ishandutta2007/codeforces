#include <bits/stdc++.h>
using namespace std;

int dat[100005];
long long presum[100005];
map<long long, int> mp;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		presum[i] = presum[i - 1] + dat[i];
	}

	vector<long long> targets;
	if (k == 1) targets.push_back(1);
	else if (k == -1)
	{
		targets.push_back(1);
		targets.push_back(-1);
	}
	else
	{
		for (long long z = 1; abs(z) <= 1e16; z *= k)
		{
			targets.push_back(z);
		}
	}

	long long ans = 0;
	mp[0]++;

	for (int r = 1; r <= n; r++)
	{
		mp[presum[r]]++;
		for (long long t : targets)
		{
			auto itr = mp.find(presum[r] - t);
			if (itr != mp.end()) ans += itr->second;
		}
	}

	printf("%lld\n", ans);
}