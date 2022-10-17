#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int a[120] = {};
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			a[abs(x)]++;
		}
		int z = min(a[0], 1);
		for (int i = 1; i <= 100; i++)
		{
			z += min(a[i], 2);
		}
		cout << z << endl;
	}
	return 0;
}