/*input
5
6 15 35 77 22

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	clock_t prad = clock();
	mt19937 rng(prad);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	int kur[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		kur[i] = 1;
		rng = mt19937(rng() + a[i]);
	}
	int p[n];
	iota(p, p + n, 0);
	while ((clock() - prad) * 20 <= 8 * CLOCKS_PER_SEC)
	{
		int i0 = rng() % n;
		fill_n(kur, n, 1);
		kur[i0] = 2;
		int g = a[i0];
		shuffle(p, p + n, rng);
		for (int i : p)
		{
			int g_ = __gcd(g, a[i]);
			if (g_ < g)
			{
				g = g_;
				kur[i] = 2;
			}
		}
		if (g == 1)
		{
			g = 0;
			for (int i = 0; i < n; i++)
				if (kur[i] == 1)
					g = __gcd(g, a[i]);
			if (g == 1)
			{
				cout << "YES\n";
				for (int i = 0; i < n; i++)
				{
					cout << kur[i] << " ";
				}
				cout << "\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}