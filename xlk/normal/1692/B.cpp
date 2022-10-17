#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[60];
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
		m = unique(a, a + n) - a;
		m -= (n + m) % 2;
		cout << m << endl;
	}
	return 0;
}