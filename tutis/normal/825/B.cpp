/***
.....X....
OO.O..X...
......X...
........X.
....X....X
...X..X...
.......X..
........X.
.........X
..........
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	char X[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> X[i][j];
	for (int k = 0; k < 10; k++)
		for (int l = 0; l < 10; l++)
		{
			if (X[k][l] == '.')
			{
				X[k][l] = 'X';
				for (int j = 0; j <= 5; j++)
				{
					bool ok = true;
					for (int a = j; a < j + 5; a++)
						if (X[k][a] != 'X')
							ok = false;
					if (ok)
					{
						cout << "YES";
						return 0;
					}
				}
				for (int j = 0; j <= 5; j++)
				{
					bool ok = true;
					for (int a = j; a < j + 5; a++)
						if (X[a][l] != 'X')
							ok = false;
					if (ok)
					{
						cout << "YES";
						return 0;
					}
				}
				for (int a = 0; a <= 4; a++)
				{
					bool ok = true;
					int b = 4 - a;
					for (int j = -b; j <= a; j++)
					{
						if (k + j > 10 || k + j < 0 || l - j > 10 || l - j < 0 || X[k + j][l - j] != 'X')
							ok = false;
					}
					if (ok)
					{
						cout << "YES";
						return 0;
					}
				}
				for (int a = 0; a <= 4; a++)
				{
					bool ok = true;
					int b = 4 - a;
					for (int j = -b; j <= a; j++)
					{
						if (k + j > 10 || k + j < 0 || l + j > 10 || l + j < 0 || X[k + j][l + j] != 'X')
							ok = false;
					}
					if (ok)
					{
						cout << "YES";
						return 0;
					}
				}
				X[k][l] = '.';
			}
		}
	cout << "NO";
}