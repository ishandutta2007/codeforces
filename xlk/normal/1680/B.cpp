#include <bits/stdc++.h>
using namespace std;
int t, n, m;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		int r = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			for (int j = 0; j < m; j++)
			{
				if (s[j] == 'R')
				{
					if (r == -1)
					{
						r = j;
					}
					else if (j < r)
					{
						r = m;
					}
				}
			}
		}
		cout << (r < m ? "YES" : "NO") << endl;
	}
	return 0;
}