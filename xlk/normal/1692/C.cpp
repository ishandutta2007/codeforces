#include <bits/stdc++.h>
using namespace std;
string s[8];
int t;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		for (int i = 0; i < 8; i++)
		{
			cin >> s[i];
		}
		for (int i = 1; i < 7; i++)
		{
			for (int j = 1; j < 7; j++)
			{
				if (s[i][j] == '#' && s[i - 1][j - 1] == '#' && s[i - 1][j + 1] == '#')
				{
					cout << i + 1 << " " << j + 1 << endl;
				}
			}
		}
	}
	return 0;
}