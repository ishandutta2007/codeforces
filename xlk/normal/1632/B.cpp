#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int m = 1;
		while (2 * m < n)
		{
			m *= 2;
		}
		for (int i = m - 1; i >= 0; i--)
		{
			cout << i << " ";
		}
		for (int i = m; i < n; i++)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}