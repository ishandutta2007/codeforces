#include <bits/stdc++.h>
using namespace std;

vector<int> x, y;
set<unsigned long long> mp;
pair<int, int> dat[200005];

inline unsigned long long gh(int x, int y)
{
	return (unsigned long long)x << 31 | y;
}

constexpr int bojeong = (int)5e8;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	if (k >= n)
	{
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &dat[i].first, &dat[i].second);
		dat[i].first += bojeong;
		dat[i].second += bojeong;
		mp.insert(gh(dat[i].first, dat[i].second));
	}

	sort(dat, dat + n);

	set<pair<int, int>> ans;

	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			int cx = dat[i].first + dat[n - 1 - j].first;
			int cy = dat[i].second + dat[n - 1 - j].second;
			if (ans.count({ cx, cy })) continue;

			int fail = 0;

			for (int i = 0; i < n; i++)
			{
				fail += (cx < dat[i].first || cy < dat[i].second || mp.count(gh(cx - dat[i].first, cy - dat[i].second)) == 0);
				if (fail > k) break;
			}

			if (fail <= k) ans.emplace(cx, cy);
		}
	}

	/*if (k == n - 1)
	{
	for (int i = 0; i < n; i++) ans.emplace(dat[i].first * 2, dat[i].second * 2);
	}*/

	printf("%zd\n", ans.size());
	for (pair<int, int> e : ans)
	{
		e.first -= bojeong * 2;
		e.second -= bojeong * 2;
		printf("%.1f %.1f\n", e.first / 2.0, e.second / 2.0);
	}

	fflush(stdout);
	_Exit(0);
}