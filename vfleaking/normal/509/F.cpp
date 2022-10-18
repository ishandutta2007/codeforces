#include <iostream>
#include <cstdio>
using namespace std;

const int M = 1000000007;

const int MaxN = 500;

int main()
{
	int n;
	static int a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	static int f[MaxN + 1][MaxN + 1];
	for (int l = n; l >= 0; l--)
		for (int r = l; r <= n; r++)
		{
			if (r - l <= 1)
				f[l][r] = 1;
			else
			{
				for (int k = l + 1; k <= r; k++)
					if (k == r || a[k] > a[l])
						f[l][r] = (f[l][r] + (long long)f[l + 1][k] * f[k][r]) % M;
			}
		}

	cout << f[1][n] << endl;

	return 0;
}