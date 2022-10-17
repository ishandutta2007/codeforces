#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		if (m == 1)
		{
			cout << "YES" << endl;
			for (int i = 1; i <= n; i++)
			{
				cout << i << endl;
			}
		}
		else if (n % 2 == 0)
		{
			cout << "YES" << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << i / 2 * 2 * m + i % 2 + 2 * j + 1 << ' ';
				}
				cout << endl;
			}
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}