/*input
5 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
map<int, int>MAXI;
int maxi(int n)
{
	if (MAXI.count(n))
		return MAXI[n];
	if (n == 1)
		return 1;
	return MAXI[n] = 1 + maxi(n / 2) + maxi(n - n / 2);
}
map<pair<int, int>, int>POSS;
int possible(int n, int k)
{
	if (k <= 0 || k > maxi(n))
		return false;
	if (POSS.count({n, k}))
		return POSS[ {n, k}];
	if (n == 1)
		return (k == 1);
	if (k == 1)
		return true;
	for (int a = k / 2 - 7; a <= k / 2 + 7; a++)
	{
		if (possible(n / 2, a) && possible(n - n / 2, k - a - 1))
			return POSS[ {n, k}] = true;
	}
	return POSS[ {n, k}] = false;
}
int Possible(int l, int r, int k, int a[])
{
	if (k == 1)
	{
		sort(a + l, a + r);
		return 1;
	}
	int n = r - l;
	int mid = (l + r) / 2;
	for (int c = k / 2 - 7; c <= k / 2 + 7; c++)
	{
		if (possible(n / 2, c) && possible(n - n / 2, k - c - 1))
		{
			return Possible(l, mid, c, a) * Possible(mid, r, k - c - 1, a);
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (!possible(n, k))
	{
		cout << "-1\n";
		return 0;
	}
	int a[n];
	for (int i = 0; i < n; i++)
		a[i] = n - i;
	cerr << Possible(0, n, k, a) << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}