#include <bits/stdc++.h>
using namespace std;
int t, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x;
		int y = (x & -x);
		if (x == y)
		{
			if (y == 1)
			{
				y |= 2;
			}
			else
			{
				y |= 1;
			}
		}
		cout << y << endl;
	}
	return 0;
}