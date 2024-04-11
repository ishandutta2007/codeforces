#include <bits/stdc++.h>
using namespace std;
int t, n, a[60];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int f = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] %= 2;
			if (a[i] != a[i % 2])
			{
				f = 0;
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}