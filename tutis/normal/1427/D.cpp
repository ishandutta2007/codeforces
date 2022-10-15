/*input
4
3 1 2 4
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int c[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	vector<pair<int, vector<int>>>ans;
	auto execu = [&](vector<int>move)
	{
		vector<vector<int>>x;
		int id = 1;
		for (int i : move)
		{
			x.push_back({});
			while (i--)
			{
				x.back().push_back(c[id]);
				id++;
			}
		}
		assert(id == n + 1);
		reverse(x.begin(), x.end());
		id = 1;
		for (auto j : x)
		{
			for (int i : j)
			{
				c[id] = i;
				id++;
			}
		}
	};
	for (int x = 2; x <= n; x++)
	{
		int p1 = 1;
		int px = 1;
		int px_ = 1;
		while (c[p1] != 1)
			p1++;
		while (c[px] != x)
			px++;
		while (c[px_] != x - 1)
			px_++;
		if (p1 <= px_)
		{
			vector<int>r;
			if (px <= p1)
			{
				if (px != 1)
					r.push_back(px - 1);
				r.push_back(p1 - px);
				r.push_back(px_ - p1 + 1);
				if (n != px_)
					r.push_back(n - px_);
			}
			else
			{
				if (p1 != 1)
					r.push_back(p1 - 1);
				for (int i = 0; i < (px_ - p1 + 1); i++)
					r.push_back(1);
				r.push_back(px - px_);
				if (n != px)
					r.push_back(n - px);
			}
			ans.push_back({(int)r.size(), r});
		}
		else
		{
			vector<int>r;
			if (px >= p1)
			{
				if (px_ != 1)
					r.push_back(px_ - 1);
				r.push_back(p1 - px_ + 1);
				r.push_back(px - p1);
				if (n != px)
					r.push_back(n - px);
			}
			else
			{
				if (px != 1)
					r.push_back(px - 1);
				r.push_back(px_ - px);
				for (int i = 0; i < (p1 - px_ + 1); i++)
					r.push_back(1);
				if (n != p1)
					r.push_back(n - p1);
			}
			ans.push_back({(int)r.size(), r});
		}
		execu(ans.back().second);
	}
	if (c[1] != 1)
	{
		vector<int>x;
		for (int i = 0; i < n; i++)
			x.push_back(1);
		ans.push_back({n, x});
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
	{
		cout << i.first << " ";
		for (int j : i.second)
			cout << j << " ";
		cout << "\n";
	}
}