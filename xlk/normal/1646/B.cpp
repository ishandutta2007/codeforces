#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
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
		sort(a, a + n);
		long long s = a[0];
		for (int i = 1; i < n - i; i++)
		{
			s += a[i] - a[n - i];
			if (s < 0)
			{
				break;
			}
		}
		cout << (s < 0 ? "YES" : "NO") << endl;
	}
	return 0;
}