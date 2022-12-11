#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll l, n, p, t;
pair<ll, ll> dat[100005];
unordered_map<ll, ll> dp[100005];

ll D(int i, ll j)
{
	if (i>=n) return 0;

	auto itr = dp[i].emplace(j,-1).first;
	if (itr->second == -1)
	{
		itr->second = D(i + 1, dat[i + 1].first);

		ll cnt = (dat[i].second - j) / p;
		if (cnt)
		{
			ll nxt = j + cnt * p + t;

			int lo = i + 1, hi = n - 1, idx = n;
			while (lo <= hi)
			{
				int mid = (lo + hi) / 2;
				if (dat[mid].first <= nxt && nxt <= dat[mid].second)
				{
					idx = mid;
					break;
				}
				else if (dat[mid].first > nxt)
				{
					idx = mid;
					hi = mid - 1;
				}
				else
				{
					lo = mid + 1;
				}
			}

			itr->second = max(itr->second, D(idx, max(dat[idx].first, nxt)) + cnt);
		}
	}
	return itr->second;
}

int main()
{
	scanf("%lld%lld%lld%lld", &l, &n, &p, &t);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &dat[i].first, &dat[i].second);
	}
	
	printf("%lld", D(0, dat[0].first));
}