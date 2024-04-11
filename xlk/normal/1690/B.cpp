#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[50020];
int b[50020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int d = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			d = max(d, a[i] - b[i]);
		}
		for (int i = 0; i < n; i++)
		{
			a[i] = max(a[i] - d, 0);
		}
		int f = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				f = 1;
				break;
			}
		}
		cout << (f ? "NO" : "YES") << endl;
	}
	return 0;
}