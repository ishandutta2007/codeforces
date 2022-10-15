/*input
cacbac
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string s;
string ret;
void atsakymas(int l, int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		ret.push_back(s[l]);
		return;
	}
	if (l + 1 == r)
	{
		ret.push_back(s[l]);
		if (s[l] == s[r])
			ret.push_back(s[r]);
		return;
	}
	if (l + 2 == r)
	{
		if (s[l] == s[r])
		{
			ret.push_back(s[l]);
			ret.push_back(s[l + 1]);
			ret.push_back(s[r]);
			return;
		}
		if (s[l] == s[l + 1])
		{
			ret.push_back(s[l]);
			ret.push_back(s[l + 1]);
			return;
		}
		if (s[l + 1] == s[l + 2])
		{
			ret.push_back(s[l + 1]);
			ret.push_back(s[r]);
			return;
		}
		ret.push_back(s[l + 1]);
		return;
	}
	for (int a = l; a <= l + 1; a++)
	{
		for (int b = r; b >= r - 1; b--)
		{
			if (s[a] == s[b])
			{
				ret.push_back(s[a]);
				atsakymas(a + 1, b - 1);
				ret.push_back(s[a]);
				return;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> s;
	atsakymas(0, s.size() - 1);
	if (ret.size() >= s.size() / 2)
	{
		cout << ret << "\n";
		return 0;
	}
	cout << "IMPOSSIBLE\n";
}