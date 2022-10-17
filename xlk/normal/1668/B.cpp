#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		long long s = n + a[n - 1];
		for (int i = 1; i < n; i++)
		{
			s += a[i];
		}
		cout << (s > m ? "NO" : "YES") << endl;
	}
	return 0;
}