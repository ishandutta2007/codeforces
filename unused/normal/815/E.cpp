#include <bits/stdc++.h>
using namespace std;

long long n, k;

bool check(long long lim)
{
	map<long long, long long> left, right;
	pair<long long, long long> mid{ 2, n - 1 };
	long long rem = k;
	left[0] = 0; right[0] = 0;

	while (rem)
	{
		long long midlen = mid.second - mid.first + 1;
		long long L = left.rbegin()->first;
		long long R = right.rbegin()->first;
		long long mv = max({ midlen, L, R });

		if ((mv + 1) / 2 == (L + 1) / 2)
		{
			if (left.rbegin()->second >= rem) return true;
			rem -= left.rbegin()->second;
			left[(left.rbegin()->first - 1) / 2] += left.rbegin()->second;
			left[left.rbegin()->first / 2] += left.rbegin()->second;
			left.erase(prev(left.end()));
		}
		else if ((mv + 1) / 2 == (midlen + 1) / 2)
		{
			long long center = (mid.first + mid.second) / 2;
			if (rem == 1) return center <= lim;
			--rem;

			long long LL = mid.first;
			long long LR = center - 1;

			long long RL = center + 1;
			long long RR = mid.second;

			mid = { 0, -1 };

			if (LR <= lim) left[LR - LL + 1]++;
			else mid = { LL, LR };
			if (RL > lim) right[RR - RL + 1]++;
			else mid = { RL, RR };
		}
		else
		{
			if (right.rbegin()->second >= rem) return false;
			rem -= right.rbegin()->second;
			right[(right.rbegin()->first - 1) / 2] += right.rbegin()->second;
			right[right.rbegin()->first / 2] += right.rbegin()->second;
			right.erase(prev(right.end()));
		}
	}

	return false;
}

int main()
{
	for (;;)
	{
		if (scanf("%lld%lld", &n, &k) != 2) break;

		if (k == 1) { printf("1\n"); continue; }
		if (k == 2) { printf("%lld\n", n); continue; }

		k -= 2;

		long long lo = 2, hi = n - 2, ans = n - 1;

		while (lo <= hi)
		{
			long long mid = (lo + hi) / 2;
			if (check(mid))
			{
				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}

		printf("%lld\n", ans);
	}
}