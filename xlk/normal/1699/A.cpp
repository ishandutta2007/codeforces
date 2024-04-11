#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		if (n & 1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << n / 2 << " " << 0 << " " << 0 << endl;
		}
	}
	return 0;
}