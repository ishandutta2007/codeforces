#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string x, y;
	cin >> x >> y;
	string z = x;
	for (int i = 0; i < x.length(); i++)
	{
		bool ok = false;
		for (z[i] = 'a'; z[i] <= 'z'; z[i]++)
		{
			if (y[i] == min(x[i], z[i]))
			{
				ok = true;
				break;
			}
		}
		if (!ok)
		{
			cout << -1;
			return 0;
		}
	}
	cout << z;
	return 0;
}