#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n, x;
int a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			a[x] = i;
		}
		int l = a[0], r = a[0];
		long long z = 1;
		for (int i = 1; i < n; i++)
		{
			if (l < a[i] && a[i] < r)
			{
				z = z * (r - l - i + 1) % p;
			}
			l = min(l, a[i]);
			r = max(r, a[i]);
		}
		cout << z << endl;
	}
	return 0;
}