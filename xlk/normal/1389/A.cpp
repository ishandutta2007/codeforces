#include <bits/stdc++.h>
using namespace std;
int t, l, r;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> l >> r;
		if (2 * l <= r)
		{
			cout << l << " " << 2 * l << endl;
		}
		else
		{
			cout << "-1 -1" << endl;
		}
	}
	return 0;
}