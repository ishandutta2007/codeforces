#include <bits/stdc++.h>
using namespace std;
int t, n, m, z;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		z = n;
		for (int i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (i <= m)
				{
					z = min(z, n / i);
				}
				if (n / i <= m)
				{
					z = min(z, i);
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}