#include <bits/stdc++.h>
using namespace std;

pair<int, int> dat[4];
set<pair<int, int>> ans;

int main()
{
	for (int i = 0; i < 3; i++) scanf("%d%d", &dat[i].first, &dat[i].second);

	sort(dat, dat + 3);
	do
	{
		// 1 - 2 - 3
		dat[3].first = dat[2].first + (dat[0].first - dat[1].first);
		dat[3].second = dat[2].second + (dat[0].second - dat[1].second);
		ans.insert(dat[3]);
	} while (next_permutation(dat, dat + 3));

	printf("%zd\n", ans.size());
	for (auto &&e : ans) printf("%d %d\n", e.first, e.second);
}