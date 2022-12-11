#include <bits/stdc++.h>
using namespace std;

int ple[200005];
int len[200005];
int n, w, k;

set<pair<int, int>> half;
set<pair<int, int>> full;
int tsum, psum, ans;

void adjust()
{
	while (half.size() < w && full.empty() == false)
	{
		tsum -= full.rbegin()->first;
		tsum += (full.rbegin()->first + 1) / 2;
		half.emplace((full.rbegin()->first + 1) / 2, full.rbegin()->second);
		full.erase(prev(full.end()));
	}

	if (full.empty() == false)
	{
		while (len[half.begin()->second] < full.rbegin()->first)
		{
			tsum -= half.begin()->first + full.rbegin()->first;
			tsum += len[half.begin()->second] + (full.rbegin()->first + 1) / 2;

			auto a1 = make_pair((full.rbegin()->first + 1) / 2, full.rbegin()->second);
			auto a2 = make_pair(len[half.begin()->second], half.begin()->second);

			full.erase(prev(full.end()));
			half.erase(half.begin());
			full.insert(a2);
			half.insert(a1);
		}
	}
}

int main()
{

	scanf("%d%d%d", &n, &w, &k);
	for (int i = 0; i < n; i++) scanf("%d", &ple[i]);
	for (int i = 0; i < n; i++) scanf("%d", &len[i]);

	for (int l = 0, r = 0; r < n; r++)
	{
		full.emplace(len[r], r);
		tsum += len[r];
		psum += ple[r];

		adjust();

		while (l <= r && tsum > k)
		{
			psum -= ple[l];
			if (full.count({ len[l], l }))
			{
				tsum -= len[l];
				full.erase({ len[l], l });
			}
			else
			{
				tsum -= (len[l] + 1) / 2;
				half.erase({ (len[l] + 1) / 2, l });
			}

			l++;

			adjust();
		}

		ans = max(ans, psum);
	}
	printf("%d", ans);
}