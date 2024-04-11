#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		if (2 * m - 1 <= n)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j && i % 2 == 0 && i / 2 < m)
					{
						cout << "R";
					}
					else
					{
						cout << ".";
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}