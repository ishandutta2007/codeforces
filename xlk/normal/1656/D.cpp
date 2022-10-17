#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		long long x = n & -n;
		if (x == n)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << min(n / x, 2 * x) << endl;
		}
	}
	return 0;
}