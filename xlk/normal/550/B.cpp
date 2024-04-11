#include <bits/stdc++.h>
using namespace std;
int n, l, r, x, a[20], z;
int main()
{
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 1 << n; i++)
	{
		int s = 0;
		int mx = 0;
		int mn = 1e9;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				s += a[j];
				mx = max(mx, a[j]);
				mn = min(mn, a[j]);
			}
		}
		if (l <= s && s <= r && mx - mn >= x)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}