#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[20];
long long k, d[20];
int main()
{
	d[0] = 1;
	for (int i = 1; i < 19; i++)
	{
		d[i] = d[i - 1] * 10;
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		a[n] = 18;
		k++;
		long long z = 0;
		for (int i = 0; i < n; i++)
		{
			long long u = min(d[a[i + 1] - a[i]] - 1, k);
			z += u * d[a[i]];
			k -= u;
		}
		cout << z << endl;
	}
	return 0;
}