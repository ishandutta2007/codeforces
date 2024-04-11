#include <bits/stdc++.h>
using namespace std;
int t, n, a[120];
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
		int x = min_element(a, a + n) - a;
		int y = max_element(a, a + n) - a;
		if (x > y)
		{
			swap(x, y);
		}
		cout << n - max(max(n - y - 1, y - x - 1), x) << endl;
	}
	return 0;
}