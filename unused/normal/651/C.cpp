#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<pair<int, int>, int> dat;

struct comp
{
	bool operator()(pair<int, int> p1, pair<int, int> p2) const
	{
		return p1.second < p2.second;
	}
};

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vt;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		dat[{a, b}]++;
		vt.emplace_back(a, b);
	}
	long long ans = 0;

	for (auto &&elem : dat)
	{
		ans -= (long long)elem.second * (elem.second - 1) / 2;
	}

	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++)
	{
		int j;
		for (j = i + 1; j < vt.size(); j++)
		{
			if (vt[i].first != vt[j].first) break;
		}
		// j - i
		ans += (long long)(j - i) * (j - i - 1) / 2;
		i = j - 1;
	}

	sort(vt.begin(), vt.end(), comp());
	for (int i = 0; i < vt.size(); i++)
	{
		int j;
		for (j = i + 1; j < vt.size(); j++)
		{
			if (vt[i].second != vt[j].second) break;
		}
		// j - i
		ans += (long long)(j - i) * (j - i - 1) / 2;
		i = j - 1;
	}

	printf("%lld\n", ans);
}