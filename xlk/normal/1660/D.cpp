#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int zl = 1, zr = 0, z = 0;
		int f = 0, fi = 1;
		int g = -1e9, gi = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			if (x == 0)
			{
				f = 0;
				fi = i + 1;
				g = -1e9;
				gi = i;
			}
			else
			{
				if (x == 2 || x == -2)
				{
					f++;
					g++;
				}
				if (x < 0)
				{
					swap(f, g);
					swap(fi, gi);
				}
				if (x == -1)
				{
					if (g < 0)
					{
						g = 0;
						gi = i;
					}
				}
				if (x == -2)
				{
					if (g < 1)
					{
						g = 1;
						gi = i;
					}
				}
				if (x == 1)
				{
					if (f < 0)
					{
						f = 0;
						fi = i;
					}
				}
				if (x == 2)
				{
					if (f < 1)
					{
						f = 1;
						fi = i;
					}
				}
			}
			if (z < f)
			{
				z = f;
				zl = fi;
				zr = i;
			}
		}
		cout << zl - 1 << " " << n - zr << endl;
	}
	return 0;
}