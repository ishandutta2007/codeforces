/*input
2
7 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
mt19937_64 rng(156);
int main()
{
	int n;
	cin >> n;
	ll a[n];
	ull x[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		x[i] = rng();
	}
	ull dabar = 0;
	ull sum = 0;
	for (int i = 0; i < n; i++)
	{
		dabar += x[i] * ull(__builtin_popcount(a[i]));
		sum += x[i];
	}
	ull ok[31];
	for (int k = 0; k <= 30; k++)
	{
		ok[k] = sum * ull(k) - dabar;
	}
	ull de[30];
	for (int j = 0; j < 30; j++)
	{
		de[j] = 0;
		for (int i = 0; i < n; i++)
		{
			if ((a[i] & (1ll << j)) > 0)
				de[j] -= x[i];
			else
				de[j] += x[i];
		}
	}
	map<ull, int>M;
	for (int msk = 0; msk < (1ll << 16); msk++)
	{
		ull suma = 0;
		for (int i = 0; i < 16; i++)
		{
			if ((msk & (1 << i)) > 0)
				suma += de[i];
		}
		M[suma] = msk;
	}
	for (int msk = 0; msk < (1ll << 14); msk++)
	{
		ull suma1 = 0;
		for (int i = 0; i < 14; i++)
		{
			if ((msk & (1 << i)) > 0)
				suma1 += de[i + 16];
		}
		for (int k = 0; k <= 30; k++)
		{
			if (M.count(ok[k] - suma1))
			{
				cout << ((msk << 16) + M[ok[k] - suma1]) << "\n";
				return 0;
			}
		}
	}
	cout << "-1\n";
}