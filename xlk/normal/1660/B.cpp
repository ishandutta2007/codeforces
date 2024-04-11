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
		a[n] = 0;
		sort(a, a + n + 1);
		cout << (a[n] - a[n - 1] < 2 ? "YES" : "NO") << endl;
	}
	return 0;
}