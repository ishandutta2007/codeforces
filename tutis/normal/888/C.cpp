/*input
abacaba
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	int suma[s.size() + 1][26];
	for (int t = 0; t < 26; t++)
		suma[0][t] = 0;
	for (int i = 1; i <= s.size(); i++)
	{
		for (int a = 0; a < 26; a++)
			suma[i][a] = suma[i - 1][a];
		suma[i][s[i - 1] - 'a']++;
	}
	int lo = 1;
	int hi = s.size();
	while (lo < hi)
	{
		bool taip[26];
		fill_n(taip, 26, true);
		int k = (lo + hi) / 2;
		for (int l = 1; l + k - 1 <= s.size(); l++)
		{
			for (int a = 0; a < 26; a++)
			{
				taip[a] &= (suma[l + k - 1][a] - suma[l - 1][a] > 0);
			}
		}
		bool ok = false;
		for (bool c : taip)
			ok |= c;
		if (ok)
			hi = k;
		else
			lo = k + 1;
	}
	cout << lo << "\n";
}