/*input
14
wow
this
is
the
first
mcdics
codeforces
round
hooray
i
am
proud
about
that
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
mt19937_64 gen(12938712983ll);
set<char> vov = {'a', 'e', 'o', 'i', 'u'};
vector<string>x[5][1000001];
vector<string>y[1000001];
int nr(char c)
{
	int ret = 0;
	for (char x : vov)
	{
		if (x == c)
		{
			return ret;
		}
		ret++;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int kiek = 0;
		char w = 'a';
		for (char c : s)
		{
			if (vov.count(c))
			{
				kiek++;
				w = c;
			}
		}
		x[nr(w)][kiek].push_back(s);
	}
	vector<pair<string, string>>a1;
	vector<pair<string, string>>a2;
	for (int l = 1; l < 1000001; l++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (x[c][l].size() % 2 == 1)
			{
				y[l].push_back(x[c][l].back());
				x[c][l].pop_back();
			}
			for (int i = 1; i < x[c][l].size(); i += 2)
				a2.push_back({x[c][l][i], x[c][l][i - 1]});
		}
		for (int i = 1; i < y[l].size(); i += 2)
			a1.push_back({y[l][i], y[l][i - 1]});
	}
	while (a2.size() > a1.size())
	{
		a1.push_back(a2.back());
		a2.pop_back();
	}
	vector<string>ans;
	for (int i = 0; i < a1.size() && i < a2.size(); i++)
	{
		ans.push_back(a1[i].first + " " + a2[i].first);
		ans.push_back(a1[i].second + " " + a2[i].second);
	}
	cout << ans.size() / 2 << "\n";
	for (auto i : ans)
		cout << i << "\n";
}