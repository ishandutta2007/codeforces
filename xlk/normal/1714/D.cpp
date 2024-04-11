#include <bits/stdc++.h>
using namespace std;
int q, n;
string t, s[20];
int f[120];
int g[120];
int h[120];
int main()
{
	for (cin >> q; q--;)
	{
		cin >> t >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
		}
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		for (int i = 1; i <= t.size(); i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i >= s[j].size() && t.substr(i - s[j].size(), s[j].size()) == s[j])
				{
					for (int k = i - s[j].size(); k < i; k++)
					{
						if (f[i] > f[k] + 1)
						{
							f[i] = f[k] + 1;
							g[i] = j;
							h[i] = k;
						}						
					}
				}
			}
		}
		if (f[t.size()] > t.size())
		{
			cout << -1 << endl;
		}
		else
		{
			int p = t.size();
			cout << f[p] << endl;
			while (p > 0)
			{
				cout << g[p] << " " << p - s[g[p]].size() + 1 << endl;
				p = h[p];
			}
		}
	}
}