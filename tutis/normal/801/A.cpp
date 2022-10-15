#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int ats = 0;
	for (int i = 0; i < s.length(); i++)
	{
		string g=s;
		if (g[i] == 'V')
			g[i] = 'K';
		else if (g[i] == 'K')
			g[i] = 'V';
		int k = 0;
		for (int j = 0; j < g.length() - 1; j++)
		{
			if (g[j] == 'V' and g[j + 1] == 'K')
				k++;
		}
		ats = max(ats, k);
	}
	int k = 0;
	for (int j = 0; j < s.length() - 1; j++)
	{
		if (s[j] == 'V' and s[j + 1] == 'K')
			k++;
	}
	ats = max(ats, k);
	cout << ats;
	return 0;
}