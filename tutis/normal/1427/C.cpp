/*input
6 9
1 2 6
7 5 1
8 5 5
10 3 1
12 4 4
13 6 2
17 6 6
20 1 4
21 5 4

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r, n;
	cin >> r >> n;
	vector<pair<pair<int, int>, int>>cnt[n + 3];
	cnt[0].push_back({{1, 1}, 0});
	int ans = 0;
	while (n--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		int lo = 0;
		int hi = ans + 1;
		while (lo < hi)
		{
			int m = (lo + hi + 1) / 2;
			bool ok = false;
			for (auto c : cnt[m])
			{
				int t_ = c.second;
				int x_ = c.first.first;
				int y_ = c.first.second;
				if (t_ + abs(x - x_) + abs(y - y_) <= t)
				{
					ok = true;
					break;
				}
			}
			if (ok)
				lo = m;
			else
				hi = m - 1;
		}
		int a = lo + 1;
		if (lo == 0 && x - 1 + y - 1 > t)
			a = 0;
		if (a != 0)
			cnt[a].push_back({{x, y}, t});
		ans = max(ans, a);
	}
	cout << ans << "\n";
}