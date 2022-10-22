#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int c = n, z = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			while (x % 2 == 0)
			{
				x /= 2;
				c--;
			}
		}
		for (int i = 17; i > 0; i--)
		{
			for (int j = 1; j <= n; j++)
			{
				if (c > 0 && (j & -j) == (1 << i))
				{
					c -= i;
					z++;
				}
			}
		}
		if (c > 0)
		{
			z = -1;
		}
		cout << z << endl;
	}
	return 0;
}