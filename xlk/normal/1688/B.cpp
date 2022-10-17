#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] & 1)
			{
				c++;
			}
		}
		if (c)
		{
			cout << n - c << endl;
			continue;
		}
		int x = 100;
		for (int i = 0; i < n; i++)
		{
			int y = 0;
			while (a[i] % 2 == 0)
			{
				a[i] /= 2;
				y++;
			}
			x = min(x, y);
		}
		x += n - 1;
		cout << x << endl;
	}
	return 0;
}