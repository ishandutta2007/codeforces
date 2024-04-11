#include <bits/stdc++.h>
using namespace std;
int t, n, h, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> h;
		int y = 0, z = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (y < x)
			{
				z = y;
				y = x;
			}
			else if (z < x)
			{
				z = x;
			}
		}
		cout << (h / (y + z) * 2 + (h % (y + z) > 0) + (h % (y + z) > y)) << endl;
	}
	return 0;
}