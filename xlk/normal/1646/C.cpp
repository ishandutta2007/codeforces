#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
long long f[20];
int main()
{
	for (int i = f[0] = 1; i <= 14; i++)
	{
		f[i] = f[i - 1] * i;
	}
	// f[3] ~ f[14]
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int z = 99;
		for (int i = 0; i < 1 << 12; i++)
		{
			long long m = n;
			int c = 0;
			for (int j = 0; j < 12; j++)
			{
				if (i >> j & 1)
				{
					c += 1;
					m -= f[j + 3];
				}
			}
			if (m >= 0)
			{
				z = min(z, c + __builtin_popcountll(m));			
			}
		}
		cout << z << endl;
	}
	return 0;
}