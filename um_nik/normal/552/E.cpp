#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

string s;
int n;
ll ans = 0;
vector<int> ls, rr;

ll calc(int l, int r)
{
	ll val = 0;
	ll tmp = (ll)(s[l] - '0');
	for (int i = l + 1; i < r; i += 2)
	{
		if (s[i] == '*')
			tmp *= (ll)(s[i + 1] - '0');
		else
		{
			val += tmp;
			tmp = (ll)(s[i + 1] - '0');
		}
	}
	val += tmp;
	ll res = 0;
	tmp = (ll)(s[0] - '0');
	if (l == 0)
		tmp = val;
	for (int i = (l == 0 ? r : 1); i < n; i += 2)
	{
		if (i + 1 == l)
		{
			tmp *= val;
			i = r - 2;
			continue;
		}
		if (s[i] == '*')
			tmp *= (ll)(s[i + 1] - '0');
		else
		{
			res += tmp;
			tmp = (ll)(s[i + 1] - '0');
		}
	}
	res += tmp;
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> s;
	n = (int)s.length();
	ls.push_back(0);
	rr.push_back(n);
	for (int i = 1; i < n; i += 2)
	{
		if (s[i] != '*') continue;
		ls.push_back(i + 1);
		rr.push_back(i);
	}
	for (int l : ls)
		for (int r : rr)
		{
			if (l >= r) continue;
			ans = max(ans, calc(l, r));
		}
	cout << ans << endl;

	return 0;
}