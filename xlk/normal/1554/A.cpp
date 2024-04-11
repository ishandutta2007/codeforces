#include <bits/stdc++.h>
using namespace std;
int t, n, a[100020];
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
		long long z = 0;
		for (int i = 1; i < n; i++)
		{
			z = max(z, (long long)a[i - 1] * a[i]);
		}
		cout << z << endl;
	}
	return 0;
}