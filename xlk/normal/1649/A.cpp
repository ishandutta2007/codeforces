#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int mx = -3, mn = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x == 0)
			{
				mx = i;
				if (mn == -1)
				{
					mn = i;
				}
			}
		}
		cout << mx - mn + 2 <<endl;
	}
	return 0;
}