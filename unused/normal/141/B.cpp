#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, x, y;
	cin >> a >> x >> y;

	if (y % a == 0) cout << "-1\n";
	else
	{
		int yy = y / a;
		if (yy == 0)
		{
			if (abs(x) <= (a - 1) / 2)
			{
				cout << "1\n";
			}
			else cout << "-1\n";
		}
		else if (yy & 1)
		{
			if (abs(x) <= (a - 1) / 2)
			{
				cout << (yy - 1) / 2 * 3 + 2 << "\n";
			}
			else cout << "-1\n";
		}
		else
		{
			if (abs(x) >= a || x == 0)
			{
				cout << "-1\n";
			}
			else
			{
				if (x < 0)
				{
					cout << (yy - 1) / 2 * 3 + 3 << "\n";
				}
				else
				{
					cout << (yy - 1) / 2 * 3 + 4 << "\n";
				}
			}
		}
	}
}