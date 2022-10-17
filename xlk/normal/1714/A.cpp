#include <bits/stdc++.h>
using namespace std;
int t, n, h, m, x, y;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> h >> m;
		x = h * 60 + m;
		int z = 1440;
		for (int i = 0; i < n; i++)
		{
			cin >> h >> m;
			y = h * 60 + m;
			if (y < x)
			{
				y += 1440;
			}
			z = min(z, y - x);
		}
		cout << z / 60 << " " << z % 60 << endl;
	}
}