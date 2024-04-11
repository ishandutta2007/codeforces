#include <bits/stdc++.h>
using namespace std;
int t, n, m, l;
char s[120][120];
void gao(int x, int y, int h)
{
	assert(x % 2 == 0 && y % 2 == 0);
	if ((x + y) % 4 == 0)
	{
		s[x][y] = 'a';
		s[x + 1 - h][y + h] = 'a';
		s[x + h][y + 1 - h] = 'b';
		s[x + 1][y + 1] = 'b';		
	}
	else
	{
		s[x][y] = 'c';
		s[x + 1 - h][y + h] = 'c';
		s[x + h][y + 1 - h] = 'd';
		s[x + 1][y + 1] = 'd';		
	}
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		s[i][m] = 0;
		cout << s[i] << endl;
	}
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m >> l;
		if (n % 2 == 0 && m % 2 == 0)
		{
			if (l % 2 == 0)
			{
				cout << "YES" << endl;
				for (int i = 0; i < n; i += 2)
				{
					for (int j = 0; j < m; j += 2)
					{
						gao(i, j, l > 0);
						l -= 2;
					}
				}
				print();
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else if (n % 2 == 0)
		{
			if (l % 2 == 0 && l <= n * (m / 2))
			{
				cout << "YES" << endl;
				for (int i = 0; i < n; i += 2)
				{
					for (int j = 0; j < m - 1; j += 2)
					{
						gao(i, j, l > 0);
						l -= 2;
					}
					gao(i, m - 1, 0);
				}
				print();
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else if (m % 2 == 0)
		{
			if (l >= m / 2 && (l - m / 2) % 2 == 0)
			{
				cout << "YES" << endl;
				for (int j = 0; j < m; j += 2)
				{
					gao(n - 1, j, l > 0);
					l--;
				}
				for (int i = 0; i < n - 1; i += 2)
				{
					for (int j = 0; j < m; j += 2)
					{
						gao(i, j, l > 0);
						l -= 2;
					}
				}
				print();
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			assert(false);
		}
	}
	return 0;
}