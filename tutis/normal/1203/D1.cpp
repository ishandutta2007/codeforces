/*input
asdfasdf
fasd

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool sub(const string &a, const string &b)
{
	int i = 0;
	for (char x : b)
	{
		if (i >= (int)a.size())
			return false;
		while (i + 1 < (int)a.size() && a[i] != x)
			i++;
		if (a[i] != x)
			return false;
		else
		{
			i++;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int lo = 0;
	int hi = s.size() - t.size();
	while (lo < hi)
	{
		int x = (lo + hi + 1) / 2;
		bool ok = false;
		for (int i = 0; i + x - 1 < s.size(); i++)
		{
			if (sub(s.substr(0, i) + s.substr(i + x, s.size() - x - i), t))
				ok = true;
		}
		if (ok)
			lo = x;
		else
			hi = x - 1;
	}
	cout << lo << "\n";
}