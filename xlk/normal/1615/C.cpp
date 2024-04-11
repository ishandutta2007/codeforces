#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> a >> b;
		int c = 0, x = 0, y = 0, z = n + 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == '1')
			{
				x++;
			}
			if (b[i] == '1')
			{
				y++;
			}
			if (a[i] != b[i])
			{
				c++;
			}
		}
		if (x == y)
		{
			z = min(z, c);
		}
		if (n - x + 1 == y)
		{
			z = min(z, n - c);
		}
		if (z == n + 1)
		{
			z = -1;
		}
		cout << z << endl;
	}
	return 0;
}