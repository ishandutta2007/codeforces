#include <bits/stdc++.h>
using namespace std;
int n, m, z = 1e9;
int a[9];
string s[9];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < m; i++)
	{
		a[i] = i;
	}
	do
	{
		int mx = 0, mn = 1e9;
		for (int i = 0; i < n; i++)
		{
			int x = 0;
			for (int j = 0; j < m; j++)
			{
				x = x * 10 + s[i][a[j]] - '0';
			}
			mx = max(mx, x);
			mn = min(mn, x);
		}
		z = min(z, mx - mn);
	}
	while (next_permutation(a, a + m));
	cout << z << endl;
	return 0;
}