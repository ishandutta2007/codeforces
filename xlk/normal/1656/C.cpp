#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int f = 0, g = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 1)
			{
				g = 1;
			}
		}
		sort(a, a + n);
		for (int i = 1; i < n; i++)
		{
			if (a[i] - a[i - 1] == 1)
			{
				f = 1;
			}
		}
		cout << (g & f ? "NO" : "YES") << endl;
	}
	return 0;
}