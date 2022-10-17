#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	int t, n, m;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> a[i];
		}
		sort(a + n, a + 2 * n, greater<int>());
		sort(a, a + n + m, greater<int>());
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s += a[i];
		}
		cout << s << endl;
	}
	return 0;
}