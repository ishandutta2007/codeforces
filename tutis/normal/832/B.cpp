/***
abc
a?a?a*
4
abacaba
abaca
apapa
aaaaax
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string good;
	cin >> good;
	set<char>geri;
	for (char i : good)
		geri.insert(i);
	string t;
	cin >> t;
	int n;
	cin >> n;
	int id = -1;
	for (int i = 0; i < t.size(); i++)
		if (t[i] == '*')
		{
			id = i;
		}
	while (n--)
	{
		string s;
		cin >> s;
		bool ok = true;
		if (s.size() != t.size() && id == -1)
			ok = false;
		int nuo = 0;
		int iki = s.size() - 1;
		for (int k = 0; k < id && k < s.size(); k++)
		{
			if (t[k] == '?')
			{
				if (geri.count(s[k]) == 0)
					ok = false;
			}
			else if (s[k] != t[k])
				ok = false;
			nuo = max(nuo, k + 1);
		}
		int ind = t.size();
		int k = s.size();
		while (ind > id && k > 0 && ind > 0)
		{
			ind--;
			k--;
			if (ind != id)
			{
				if (t[ind] == '?')
				{
					if (geri.count(s[k]) == 0)
						ok = false;
				}
				else if (s[k] != t[ind])
					ok = false;
				iki = min(iki, k - 1);
			}
		}
		if (id != -1)
		{
			for (int i = nuo; i <= iki; i++)
				if (geri.count(s[i]))
					ok = false;
			if (nuo > iki)
			{
				if (s.size() != t.size() - 1)
					ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
	return 0;
}