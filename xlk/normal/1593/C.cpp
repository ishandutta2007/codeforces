#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[400020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> a[i];
			a[i] = n - a[i];
		}
		sort(a, a + k);
		a[k] = n;
		for (int i = 0; i <= k; i++)
		{
			if (n <= a[i])
			{
				cout << i << endl;
				break;
			}
			n -= a[i];
		}
	}
	return 0;
}