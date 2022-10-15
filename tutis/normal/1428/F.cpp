/*input
12
011100011100

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	deque<pair<int, int>>X = {{0, n}};
	auto calcI = [&](int i)->ll
	{
		if (i >= (int)X.size())
			return 0;
		ll ret = 0;
		ll l = 0;
		if (i != 0)
			l = X[i - 1].first;
		ret -= l * (l + 1) / 2;
		l = X[i].first;
		ret += l * (l + 1) / 2;
		int nxt = n - 1;
		if (i + 1 < (int)X.size())
			nxt = X[i + 1].second + l - 1;
		int j = X[i].second + l;
		ret += l * (nxt - j + 1);
		return ret;
	};
	auto calc = [&]()
	{
		ll ret = 0;
		for (int i = 0; i < (int)X.size(); i++)
			ret += calcI(i);
		return ret;
	};
	ll ret = 0;
	ll dab = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '1')
		{
			while (X.size() >= 2 && X[1].first <= X.front().first + 1)
			{
				if (X.size() < 5)
				{
					dab -= calcI(0);
					dab -= calcI(1);
					dab -= calcI(2);
				}
				X.erase(X.begin() + 1);
				if (X.size() < 4)
				{
					dab += calcI(0);
					dab += calcI(1);
				}
				else
				{
					dab = calc();
				}
			}
			dab -= calcI(0);
			dab -= calcI(1);
			X.front().first++;
			X.front().second = i;
			dab += calcI(0);
			dab += calcI(1);
			dab = calc();
		}
		else
		{
			if (X.front().first != 0)
				X.push_front({0, i});
		}
		ret += dab;
	}
	cout << ret << "\n";
}