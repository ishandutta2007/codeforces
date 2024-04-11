#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
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
		cout << max_element(a, a + n) - a + 1 << ' ' << min_element(a, a + n) - a + 1 << endl;
	}
	return 0;
}