#include <bits/stdc++.h>
using namespace std;
string p[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
int n, m;
string s;
int a[6][200020];
int main()
{
	cin >> n >> m >> s;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j + 1] = a[i][j] + (s[j] == p[i][j % 3]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		int z = 0;
		for (int j = 0; j < 6; j++)
		{
			z = max(z, a[j][r] - a[j][l]);
		}
		cout << r - l - z << endl;
	}
	return 0;
}