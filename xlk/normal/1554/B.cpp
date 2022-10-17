#include <bits/stdc++.h>
using namespace std;
int t;
long long n, k, a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		long long z = -1e18;
		for (int i = n; i > 0; i--)
		{
			for (long long j = n; j > i && i * j > n * (n - 1) - k * 2 * n; j--)
			{
				z = max(z, i * j - k * (a[i] | a[j]));
			}
		}
		cout << z << endl;
	}
	return 0;
}