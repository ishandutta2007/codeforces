#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int l, x, c = 0, z = 0;
		cin >> n >> k >> l;
		for (int i = 1; i < n; i++)
		{
			cin >> x;
			if (l < 2 * x)
			{
				c++;
			}
			else
			{
				c = 0;
			}
			if (c >= k)
			{
				z++;
			}
			l = x;
		}
		cout << z << endl;
	}
	return 0;
}