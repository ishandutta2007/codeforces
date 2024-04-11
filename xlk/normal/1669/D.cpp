#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> s;
		int f = 1, r = 0, b = 0;
		for (int i = 0; i <= n; i++)
		{
			if (i == n || s[i] == 'W')
			{
				if ((b == 0) ^ (r == 0))
				{
					f = 0;
				}
				r = 0;
				b = 0;
			}
			else if (s[i] == 'R')
			{
				r++;
			}
			else if (s[i] == 'B')
			{
				b++;
			}
			else
			{
				assert(false);
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}