#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dat[100005];
set<tuple<int, int>> now;
vector<int> sel;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		dat[b].emplace_back(a, i + 1);
	}

	for (int i = n; i >= 1; i--)
	{
		for (auto &&e : dat[i]) now.emplace(e.first, e.second);
		while (now.empty() == false && get<0>(*now.begin()) < n - i + 1)
			now.erase(now.begin());
		if (now.empty()) continue;
		auto itr = now.begin();
		sel.push_back(get<1>(*itr));
		now.erase(itr);
	}

	printf("%zd\n", sel.size());
	for (int t : sel) printf("%d ", t);
	printf("\n");
}