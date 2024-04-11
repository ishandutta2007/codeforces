#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int c[200020];
int d[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			c[x] = i;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			d[x] = i;
		}
		int z = n;
		int minc = n;
		for (int j = 2; j <= 2 * n; j += 2)
		{
			minc = min(minc, c[j - 1]);
			z = min(z, minc + d[j]);
		}
		cout << z << endl;
	}
	return 0;
}