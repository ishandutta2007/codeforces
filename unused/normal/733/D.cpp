#include <stdio.h>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

map<pair<int, int>, map<int,int>> st;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> ans1; int ans2 = 0;
	for (int i = 0; i < n; i++)
	{
		int a[3];
		scanf("%d%d%d", a, a + 1, a + 2);
		sort(a, a + 3);

		auto &aaa = st[{a[0], a[1]}][i]; aaa = max(aaa, a[2]);
		auto &bbb = st[{a[0], a[2]}][i]; bbb = max(bbb, a[1]);
		auto &ccc = st[{a[1], a[2]}][i]; ccc = max(ccc, a[0]);

		if (ans2 < a[0])
		{
			ans2 = a[0];
			ans1.clear();
			ans1.push_back(i);
		}
	}

	for (auto &&e : st)
	{
		int a1 = min(e.first.first, e.first.second);

		vector<pair<int, int>> vt;

		for (auto &&f : e.second)
		{
			vt.emplace_back(f.second, f.first);
		}

		if (vt.size() <= 1) continue;

		sort(vt.begin(), vt.end(), greater<pair<int,int>>());

		int a2 = min(a1, vt[0].first + vt[1].first);

		if (ans2 < a2)
		{
			ans2 = a2;
			ans1.clear();
			ans1.push_back(vt[0].second);
			ans1.push_back(vt[1].second);
		}
	}

	printf("%d\n", (int)ans1.size());
	for (int t : ans1) printf("%d ", t + 1);
}