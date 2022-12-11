#include <bits/stdc++.h>
using namespace std;

map<int, int> dat;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		dat[t]++;
	}

	set<pair<int, int>, greater<>> st;
	for (auto &&e : dat)
	{
		st.emplace(e.second, e.first);
	}

	vector<vector<int>> ans;

	while (st.size() >= 3)
	{
		auto itr1 = st.begin();
		auto itr2 = next(itr1);
		auto itr3 = next(itr2);

		auto d1 = *itr1;
		auto d2 = *itr2;
		auto d3 = *itr3;

		ans.push_back(
		{
			d1.second,
			d2.second,
			d3.second
		});

		st.erase(itr1);
		st.erase(itr2);
		st.erase(itr3);

		if (d1.first > 1) st.emplace(d1.first - 1, d1.second);
		if (d2.first > 1) st.emplace(d2.first - 1, d2.second);
		if (d3.first > 1) st.emplace(d3.first - 1, d3.second);
	}

	printf("%zu\n", ans.size());
	for (auto &&v : ans)
	{
		sort(v.begin(), v.end(), greater<>());
		for (int t : v) printf("%d ", t);
		printf("\n");
	}
}