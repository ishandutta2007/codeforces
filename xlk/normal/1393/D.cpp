#include <bits/stdc++.h>
using namespace std;
int n, m, z;
string s[2020];
int f[2020][2020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (i >= 2 && j >= 1 && j + 1 < m)
			{
				char c = s[i][j];
				if (c == s[i-1][j-1] && c == s[i-1][j+1] && c == s[i-1][j] && c == s[i-2][j])
				{
					f[i][j] = min(min(f[i-1][j-1], f[i-1][j+1]), min(f[i-1][j], f[i-2][j]));				
				}
			}
			z += ++f[i][j];
		}
	}
	cout << z << endl;
	return 0;
}