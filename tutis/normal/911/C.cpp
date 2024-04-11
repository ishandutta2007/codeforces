/***
4 2 3
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
bool ok(int k1, int k2, int k3, int x1, int x2, int x3)
{
	bool dega[20];
	fill_n(dega, 20, false);
	for (int t = 0; t <= 20; t++)
	{
		if (x1 + t * k1 < 20)
			dega[x1 + t * k1] = true;
		if (x2 + t * k2 < 20)
			dega[x2 + t * k2] = true;
		if (x3 + t * k3 < 20)
			dega[x3 + t * k3] = true;
	}
	for (int t = 0; t < 20; t++)
		if (!dega[t])
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	int x1 = 0;
	for (int x2 = 0; x2 <= 1500; x2++)
	{
		for (int x3 = 0; x3 <= 1500; x3++)
		{
			if (ok(k1, k2, k3, x1, x2, x3))
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}