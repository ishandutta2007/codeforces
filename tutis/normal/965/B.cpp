/*input
5 2
..##.
####.
#####
.####
..#..
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n, k;
	cin >> n >> k;
	int r = 1;
	int co = 1;
	int maxi = -2;
	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '#')
				continue;
			int a = 0;
			int b = 0;
			int c = 0;
			int d = 0;
			while (i - a - 1 >= 0 && s[i - a - 1][j] == '.')
				a++;
			while (i + b + 1 < n && s[i + b + 1][j] == '.')
				b++;
			while (j - c - 1 >= 0 && s[i][j - c - 1] == '.')
				c++;
			while (j + d + 1 < n && s[i][j + d + 1] == '.')
				d++;
			int kiek = 0;
			if (k == 1)
				kiek = 1;
			else
			{
				for (int dx = 0; dx >= -a; dx--)
				{
					if (dx + k - 1 >= 0 && dx + k - 1 <= b)
						kiek++;
				}
				for (int dx = 0; dx >= -c; dx--)
				{
					if (dx + k - 1 >= 0 && dx + k - 1 <= d)
						kiek++;
				}
			}
			if (kiek > maxi)
			{
				maxi = kiek;
				r = i + 1;
				co = j + 1;
			}
		}
	}
	cout << r << " " << co << '\n';
}