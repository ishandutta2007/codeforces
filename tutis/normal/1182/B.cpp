/*input
5 10
..........
..*.......
.*.******.
..*.......
..........

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 gen(12938712983ll);
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	char c[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 1; i + 1 < n; i++)
	{
		for (int j = 1; j + 1 < m; j++)
		{
			if (c[i][j] == '*' &&
			        c[i - 1][j] == '*' && c[i][j - 1] == '*' &&
			        c[i + 1][j] == '*' && c[i][j + 1] == '*')
			{
				c[i][j] = '.';
				for (int t = 1; t <= 500; t++)
				{
					int x = i + t;
					int y = j;
					if (x >= n)
						break;
					if (c[x][y] == '.')
						break;
					c[x][y] = '.';
				}
				for (int t = 1; t <= 500; t++)
				{
					int x = i - t;
					int y = j;
					if (x < 0)
						break;
					if (c[x][y] == '.')
						break;
					c[x][y] = '.';
				}
				for (int t = 1; t <= 500; t++)
				{
					int x = i;
					int y = j + t;
					if (y >= m)
						break;
					if (c[x][y] == '.')
						break;
					c[x][y] = '.';
				}
				for (int t = 1; t <= 500; t++)
				{
					int x = i;
					int y = j - t;
					if (y < 0)
						break;
					if (c[x][y] == '.')
						break;
					c[x][y] = '.';
				}
				bool ok = true;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						ok &= (c[i][j] == '.');
				if (ok)
					cout << "YES\n";
				else
					cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}