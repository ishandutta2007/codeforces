/*input
20
53 86 76 100 16 12 13 97 79 23 28 64 42 10 23 56 59 76 48 12
48 49 49 49 48 49 48 49 49 49 48 48 48 49 49 49 49 49 49 48
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sgn(ll x)
{
	if (x > 0)
		return 1;
	if (x < 0)
		return -1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	pair<int, int>s[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].first;
		s[i].second = i + 1;
	}
	sort(s, s + n);
	int t[n];
	for (int i = 0; i < n; i++)
		cin >> t[i];
	sort(t, t + n);
	set<pair<int, int>>k;
	for (int i = 0; i < n; i++)
		if (t[i] < s[i].first)
		{
			k.insert({s[i].first, i});
		}
	vector<pair<pair<int, int>, int>>ans;
	for (int i = 0; i < n; i++)
		while (s[i].first < t[i])
		{
			auto it = k.upper_bound({s[i].first + 1, 1e9});
			if (it == k.end())
			{
				cout << "NO\n";
				return 0;
			}
			else
			{
				int j = it->second;
				k.erase(it);
				int d = min({(s[j].first - s[i].first) / 2, t[i] - s[i].first, s[j].first - t[j]});
				s[i].first += d;
				s[j].first -= d;
				ans.push_back({{s[i].second, s[j].second}, d});
				if (t[j] < s[j].first)
					k.insert({s[j].first, j});
			}
		}
	if (!k.empty())
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
}