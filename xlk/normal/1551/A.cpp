#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		int x = n / 3, y = n / 3;
		if (n % 3 == 1)
		{
			x++;
		}
		else if (n % 3 == 2)
		{
			y++;
		}
		cout << x << ' ' << y << endl;
	}
	return 0;
}