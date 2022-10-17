#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int f[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int z = 0;
		for (int i = n; i > 0; i--)
		{
			f[i] = a[i];
			if (i + a[i] <= n)
			{
				f[i] += f[i + a[i]];
			}
			z = max(z, f[i]);
		}
		cout << z << endl;
	}
	return 0;
}