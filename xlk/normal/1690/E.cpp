#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		long long z = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			z += a[i] / k;
			a[i] %= k;
		}
		sort(a, a + n);
		for (int i = 0, j = n - 1; i < j; i++)
		{
			if (a[i] + a[j] >= k)
			{
				z++;
				j--;
			}
		}
		cout << z << endl;
	}
	return 0;
}