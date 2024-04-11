/*input
5
12
040425524644
1
0
9
123456789
2
98
3
987
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string solve(string &s, int n)
{
	for (int x = '0'; x <= '9'; x++)
	{
		string ret(n, '2');
		int nuo = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] < x)
			{
				ret[i] = '1';
				nuo = i + 1;
			}
		}
		for (int i = nuo; i < n; i++)
		{
			if (s[i] == x)
			{
				ret[i] = '1';
			}
		}
		vector<int>ok;
		for (int i = 0; i < n; i++)
		{
			if (ret[i] == '1')
				ok.push_back(s[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (ret[i] == '2')
				ok.push_back(s[i]);
		}
		bool ger = true;
		for (int i = 1; i < (int)ok.size(); i++)
		{
			if (ok[i] < ok[i - 1])
				ger = false;
		}
		if (ger)
			return ret;
	}
	return "-";
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << solve(s, n) << "\n";
	}
}