#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int p[1020] = {};
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			p[x] = i;
		}
		int z = -1;
		for (int i = 1; i <= 1000; i++)
		{
			for (int j = 1; j <= 1000; j++)
			{
				if (p[i] && p[j] && __gcd(i, j) == 1)
				{
					z = max(z, p[i] + p[j]);
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}