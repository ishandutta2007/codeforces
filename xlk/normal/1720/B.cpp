#include <bits/stdc++.h>
using namespace std;
int t, n, a[1000020];
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
		cout << a[n - 1] + a[n - 2] - a[1] - a[0] << endl;
	}
	return 0;
}