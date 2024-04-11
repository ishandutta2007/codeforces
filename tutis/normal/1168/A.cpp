/*input
5 7
0 6 1 3 2

*/
#include <bits/stdc++.h>
using namespace std;
bool ok(int a[], int n, int m, int x)
{
	int lo = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] + x < m)
		{
			if (a[i] + x < lo)
			{
				return false;
			}
			lo = max(lo, a[i]);
		}
		else
		{
			int y = (a[i] + x) % m;
			if (y >= lo)
				continue;
			lo = max(lo, a[i]);
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int lo = 0;
	int hi = m - 1;
	while (lo < hi)
	{
		int x = (lo + hi) / 2;
		if (ok(a, n, m, x))
		{
			hi = x;
		}
		else
		{
			lo = x + 1;
		}
	}
	int x = (lo + hi) / 2;
	cout << x << "\n";
}