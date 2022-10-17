#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int b[100020];
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
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			b[i] += b[i - 1];
		}
		a[n + 1] = 0;
		for (int i = n; i > 0; i--)
		{
			a[i] += a[i + 1];
		}
		int z = 2e9;
		for (int i = 1; i <= n; i++)
		{
			z = min(z, max(a[i + 1], b[i - 1]));
		}
		cout << z << endl;
	}
	return 0;
}