#include "bits/stdc++.h"
using namespace std;

int dat[400005];
vector<pair<int, int>> query[400005];
int qidx[400005];
int ans[400005];
int ans2;
vector<int> lis;
vector<pair<int, int>> bucket[400005];
bool must[400005];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		query[a].emplace_back(b, i);
		qidx[i] = a;
	}

	for (int i = 1; i <= n; i++)
	{
		auto itr = lower_bound(lis.begin(), lis.end(), dat[i]);
		if (itr == lis.end())
		{
			lis.push_back(dat[i]);
			itr = prev(lis.end());
		}
		else *itr = dat[i];

		bucket[itr - lis.begin()].emplace_back(dat[i], i);
	}

	ans2 = lis.size();

	vector<pair<int, int>> cur = move(bucket[lis.size() - 1]);

	if (cur.size() == 1) must[cur[0].second] = true;

	for (int i = (int)lis.size() - 2; i >= 0; i--)
	{
		vector<pair<int, int>> nxt;

		for (auto &&b : bucket[i])
		{
			auto itr = lower_bound(cur.begin(), cur.end(), b.first,
				[](pair<int, int> p, int t) { return p.first > t; });

			if (itr == cur.begin()) continue;
			if (itr[-1].second < b.second) continue;

			nxt.push_back(b);
		}

		if (nxt.size() == 1) must[nxt[0].second] = true;

		swap(cur, nxt);
	}

	lis.clear();

	for (int i = 1; i <= n; i++)
	{
		for (auto &&q : query[i])
		{
			ans[q.second] += lower_bound(lis.begin(), lis.end(), q.first) - lis.begin() + 1;
		}

		auto itr = lower_bound(lis.begin(), lis.end(), dat[i]);
		if (itr == lis.end()) lis.push_back(dat[i]);
		else *itr = dat[i];
	}

	lis.clear();

	for (int i = n; i >= 1; i--)
	{
		for (auto &&q : query[i])
		{
			ans[q.second] += lower_bound(lis.begin(), lis.end(), q.first, greater<int>()) - lis.begin();
		}

		auto itr = lower_bound(lis.begin(), lis.end(), dat[i], greater<int>());
		if (itr == lis.end()) lis.push_back(dat[i]);
		else *itr = dat[i];
	}

	for (int i = 1; i <= m; i++)
	{
		printf("%d\n", max(ans2 - must[qidx[i]], ans[i]));
	}
}