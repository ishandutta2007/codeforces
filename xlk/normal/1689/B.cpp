#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int v[1020];
int z[1020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		memset(v, 0, sizeof v);
		memset(z, 0, sizeof z);
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			for (int j = 1; j <= n; j++)
			{
				if (!v[j] && j != x)
				{
					z[i] = j;
					v[j] = 1;
					break;
				}
			}
		}
		if (n == 1)
		{
			cout << -1 << endl;
			continue;
		}
		if (x == n && z[n] == 0)
		{
			z[n] = z[n - 1];
			z[n - 1] = n;
		}
		for (int i = 1; i <= n; i++)
		{
			cout << z[i] << " ";
		}
		cout << endl;
	}
	return 0;
}