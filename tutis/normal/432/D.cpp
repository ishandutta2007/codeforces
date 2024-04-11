/*input
AAAAAAAAAAAAAAAAXAAAAAAAAAAAAAAAAAAAAAAA
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void z_(const string &s, vector<int>&z)
{
	z = vector<int>(s.size(), 0);
	z[0] = s.size();
	int l = 0;
	int r = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<int>z;
	z_(s, z);
	int zz[s.size() + 1];
	fill_n(zz, s.size() + 1, 0);
	for (int i = 0; i < s.size(); i++)
	{
		zz[z[i]]++;
	}
	for (int i = s.size() - 1; i >= 0; i--)
		zz[i] += zz[i + 1];
	vector<pair<int, int>>ans;
	for (int l = 1; l <= s.size(); l++)
	{
		if (z[s.size() - l] == l)
			ans.push_back({l, zz[l]});
	}
	cout << ans.size() << "\n";
	for (pair<int, int> i : ans)
		cout << i.first << " " << i.second << "\n";
}