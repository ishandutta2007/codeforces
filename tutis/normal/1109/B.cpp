/*input
otto

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool pal(string x)
{
	for (int i = 0; i < x.size() - 1 - i; i++)
		if (x[i] != x[x.size() - 1 - i])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int k = 1; k < s.size(); k++)
	{
		string t = s.substr(k, s.size() - k) + s.substr(0, k);
		if (pal(t) && s != t)
		{
			cout << "1\n";
			return 0;
		}
	}
	vector<int>k(26, 0);
	int kiek = 0;
	for (char i : s)
	{
		if (k[i - 'a'] == 0)
			kiek++;
		k[i - 'a']++;
	}
	if (kiek == 1)
	{
		cout << "Impossible\n";
		return 0;
	}
	if (s.size() % 2 == 1)
	{
		if (kiek == 2 && k[s[s.size() / 2] - 'a'] == 1)
		{
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << 2 << "\n";
}